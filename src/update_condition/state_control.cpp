#include "state_control.h"
#include "global_data.h"

#define RF ctrl_fsm_.get()->getFsm().get()

StateControl &StateControl::instance() {

//  static StateControl instance{};
//  return instance;
}

StateControl::StateControl(std::string desc, std::function<void(int)> cb):exit_thread_(false),power_value(30)
{
    cb_ = cb;
    desc_ =desc;
    if (ctrl_fsm_ == nullptr) {
      ctrl_fsm_ = std::make_shared<FSMControl>(desc_);
      output("创建控制器成功"<<" desc:"<<desc_)
    }


   RF->set_current_states("Init"_s);
   simulatePowerChange();
}


void StateControl::simulatePowerChange()
{
    std::thread power_simulate([this]() {
        while(1)
        {
            if(exit_thread_)
            {
                exit_thread_ = true;
                output("结束线程"<<" desc:"<<desc_)
               RF->process_event(FSMControl::HaltTaskEvent{});
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                 cb_(99);
                return;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            if(power_value<=100&&!GloI.is_charge)
            {
                if(--power_value<20)
                {
                     exit_thread_ = true;
                    output("电量低，停止任务准备充电"<<" desc:"<<desc_)
                    RF->process_event(FSMControl::HaltTaskEvent{});
                    RF->process_event(FSMControl::BatteryLowEvent{});
                }
                output("电量: "<<power_value<<" desc:"<<desc_)
                if(power_value ==25&&desc_=="2")
                 {
                      output("开始析构实例" <<desc_)
                        RF->process_event(FSMControl::HaltTaskEvent{});
                      std::this_thread::sleep_for(std::chrono::milliseconds(500));
                      cb_(88);
                      return;
                 }

            }
            else if(GloI.is_charge)
            {
                if(++power_value>=100)
                {
                    output("充电结束"<<" desc:"<<desc_)
                    RF->process_event(FSMControl::BatteryFullEvent{});
                }
                else
                {
                    output("充电中...电量： "<< power_value<<" desc:"<<desc_)
                }

            }
            else
            {
                --power_value;
                output("电量: "<<power_value<<" desc:"<<desc_)
            }
        }

    });
    power_simulate.detach();
}


void StateControl::startDoTask()
{
    output("开始执行任务"<<" desc:"<<desc_)
    RF->process_event(FSMControl::DoTaskEvent{});
}


void StateControl::startInit()
{
    output("开始初始化"<<" desc:"<<desc_)
            cb_(std::stoi(desc_));
    RF->process_event(FSMControl::InitEvent{"初始化需要的信息"});
}

StateControl::~StateControl()
{
    output("析构StateControl: " << desc_)
}
