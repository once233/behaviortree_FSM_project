#ifndef STARTEXECUTETASKACTION_H
#define STARTEXECUTETASKACTION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class StartExecuteTaskAction: public BT::SyncActionNode
{
public:
    StartExecuteTaskAction(const std::string& name, const BT::NodeConfig& config) ;
    StartExecuteTaskAction() = delete;
    BT::NodeStatus tick() override;
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
