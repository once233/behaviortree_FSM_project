#include "fsm_control.h"
#include "global_data.h"
#include "cmake_config.h"
#define RF getFsm().get()
FSMControl::FSMControl(/* args */)
{
    if (fsm_ == nullptr)
    {
        fsm_ = std::make_shared<boost::sml::sm<RobotState, boost::sml::logger<FsmLogger>>>(this, logger_);
        output("创建状态机成功"<<PROJECT_AUTHORS)
    }
    if(blackboard_ ==nullptr)
    {
        node_ctr_.registerTaskNode();
        node_ctr_.registerTree("/home/ros2/behavior_tree/my_project/src/fsm_tick_bt_demo/behavior_tree/dotask.xml");
        do_task_tree_ = node_ctr_.createTree("BehaviorTreeControl");
        blackboard_ = do_task_tree_.rootBlackboard();
        blackboard_->set<int>("robot_state",0);
        std::cout<<"subtree size: "<<do_task_tree_.subtrees.size();
        output("robot_state: "<<blackboard_->get<int>("robot_state"))
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
        fsm_->process_event(DoTaskEvent{});

    }


}
 void FSMControl::actionDoTask()
 {
    output("任务中，此时将启动行为树...")
    GlobalData::task_info task;
    task.name = "1";
    GloI.task_queue_.push(task);
    task.name = "2";
    GloI.task_queue_.push(task);
    task.name = "3";
    GloI.task_queue_.push(task);

    std::thread thread_([this](){
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        BT::NodeStatus state_ =  do_task_tree_.tickOnce();
        if(state_ == BT::NodeStatus::FAILURE)
        {
            output("任务失败")
            return;
        }
        else if(state_ == BT::NodeStatus::SUCCESS)
        {
             output("任务成功")
            fsm_->process_event(FinishTaskEvent{});
             return;
        }
        else if(state_ == BT::NodeStatus::RUNNING)
        {
            output("任务进行中")
        }
    }
   });
   thread_.detach();


 }
 void FSMControl::actionHaltTask()
 {
    output("打断任务，此时将终止行为树...")
    do_task_tree_.haltTree();
 }

 void FSMControl::actionFinishTask()
 {
     output("任务结束，返回空闲")

     actionIdel();
 }

 void FSMControl::actionCharge()
 {
     GloI.is_charge=true;
 }
FSMControl::~FSMControl()
{
}
