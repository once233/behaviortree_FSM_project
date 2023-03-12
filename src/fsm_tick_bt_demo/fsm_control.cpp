#include "fsm_control.h"
#include "global_data.h"
#define RF getFsm().get()
FSMControl::FSMControl(/* args */)
{
    if (fsm_ == nullptr)
    {
        fsm_ = std::make_shared<boost::sml::sm<RobotState, boost::sml::logger<FsmLogger>>>(this, logger_);
        output("创建状态机成功")
    }

}

void FSMControl::actionInit(const FSMControl::InitEvent& event)
{
    output("接收到 ：" <<event.init_info)
    fsm_.get()->process_event(InitOKEvent {});

}
 void FSMControl::actionIdel()
{
    output("进入空闲状态，开始一些车体参数检测：")

    if(GloI.power_value<20)
    {
        output("电量过低，开始充电")
        fsm_->process_event(StartChargeEvent{});
        return;
    }
    else
    {
        GloI.is_charge=false;
    }
    fsm_->process_event(DoTaskEvent{});

}
 void FSMControl::actionDoTask()
 {
    output("任务中，此时将启动行为树...")
    node_ctr_.registerTaskNode();
    node_ctr_.registerTree("behavior_tree/dotask.xml");


 }
 void FSMControl::actionHaltTask()
 {
    output("打断任务，此时将终止行为树...")
 }

 void FSMControl::actionCharge()
 {
     GloI.is_charge=true;
 }
FSMControl::~FSMControl()
{
}
