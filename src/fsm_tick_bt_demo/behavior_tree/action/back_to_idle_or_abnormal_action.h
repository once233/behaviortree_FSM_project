#ifndef BACKTOIDLEORABNORMALACTION_H
#define BACKTOIDLEORABNORMALACTION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class BackToIdleOrAbnormalAction : public BT::SyncActionNode
{
public:
    BackToIdleOrAbnormalAction(const std::string& name, const BT::NodeConfig& config) ;
    BackToIdleOrAbnormalAction() = delete;
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
        return {
          BT::InputPort<int>("robot_state")
        };
    }

private:
    int robot_state_;

};

#endif // BACKTOIDLEORABNORMALACTION_H
