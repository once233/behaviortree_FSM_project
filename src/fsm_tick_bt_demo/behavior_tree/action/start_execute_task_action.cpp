#include "start_execute_task_action.h"

StartExecuteTaskAction::StartExecuteTaskAction(const std::string& name, const BT::NodeConfig& config):BT::SyncActionNode(name, config)
{
    output("构建StartExecuteTaskAction")
   fake_exec=0; //模拟执行任务
   exec_state_=2;//任务执行状态
}

BT::NodeStatus StartExecuteTaskAction::tick()
{

    switch (exec_state_) {
    case 0:
    {
        setOutput("robot_state", 1);
        return BT::NodeStatus::FAILURE;
    }
    case 1:
    {
     setOutput("robot_state", 0);
     output("任务结束")
     fake_exec=0;
     exec_state_=2;
     return BT::NodeStatus::SUCCESS;
    }
    case 2:
    {
        setOutput("robot_state", 1);
        output("任务执行中")
        if(fake_exec++>10)
        {
            exec_state_=1;
            output("已受到任务结束信号")
        }

        return BT::NodeStatus::RUNNING;
    }
    default:
        return BT::NodeStatus::FAILURE;
    }
}
