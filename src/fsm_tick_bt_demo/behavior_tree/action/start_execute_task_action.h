#ifndef STARTEXECUTETASKACTION_H
#define STARTEXECUTETASKACTION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class StartExecuteTaskAction: public BT::StatefulActionNode
{
public:
    StartExecuteTaskAction(const std::string& name, const BT::NodeConfig& config) ;
    StartExecuteTaskAction() = delete;
    // this function is invoked once at the beginning.
    BT::NodeStatus onStart() override;

    // If onStart() returned RUNNING, we will keep calling
    // this method until it return something different from RUNNING
    BT::NodeStatus onRunning() override;

    // callback to execute if the action was aborted by another node
    void onHalted() override;
    static BT::PortsList providedPorts()
    {
        return {
          BT::InputPort<int>("cur_task_data"),
          BT::OutputPort<int>("robot_state")
        };
    }

private:
    int exec_state_;
    int fake_exec;
};

#endif // STARTEXECUTETASKACTION_H
