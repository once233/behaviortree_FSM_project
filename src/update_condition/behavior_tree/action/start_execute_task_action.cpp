#include "start_execute_task_action.h"

StartExecuteTaskAction::StartExecuteTaskAction(const std::string& name, const BT::NodeConfig& config):BT::StatefulActionNode(name, config)
{
    output("构建StartExecuteTaskAction config")
config_ = config;

   fake_exec=0; //模拟执行任务
   exec_state_=2;//任务执行状态
}

// this function is invoked once at the beginning.
BT::NodeStatus StartExecuteTaskAction::onStart()
{
//    setOutput("robot_state", 1);
    fake_exec=0; //模拟执行任务
    output("重置任务状态并开始任务")
    return BT::NodeStatus::RUNNING;
}

// If onStart() returned RUNNING, we will keep calling
// this method until it return something different from RUNNING
BT::NodeStatus StartExecuteTaskAction::onRunning()
{
    std::string count="-1";
std::function<void(int)> cb;
    getInput<std::function<void(int)>>("count", cb);
    output("input count: "<<count)
cb(fake_exec);
            config_.blackboard.get()->debugMessage();
    output("任务执行中: 任务"<<GloI.cur_task_.name)
    if(fake_exec++>30)
    {
//        setOutput("robot_state", 0);
        output("已收到任务结束信号")
        return BT::NodeStatus::SUCCESS;
    }
    return BT::NodeStatus::RUNNING;
}

// callback to execute if the action was aborted by another node
void StartExecuteTaskAction::onHalted()
{
    output("强制中止任务")

}
