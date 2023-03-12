#ifndef BACKTOIDLEORABNORMALACTION_H
#define BACKTOIDLEORABNORMALACTION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class BackToIdleOrAbnormalAction : public BT::SyncActionNode
{
public:
    BackToIdleOrAbnormalAction(const std::string& name, const BT::NodeConfig& config) ;
    BT::NodeStatus tick() override;
    static BT::PortsList providedPorts()
    {
        return {
          BT::InputPort<double>("min_battery", "Minimum battery percentage/voltage")
        };
    }

};

#endif // BACKTOIDLEORABNORMALACTION_H
