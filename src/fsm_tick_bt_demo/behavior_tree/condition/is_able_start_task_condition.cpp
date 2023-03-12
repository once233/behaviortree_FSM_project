#include "is_able_start_task_condition.h"

IsAbleStartTaskCondition::IsAbleStartTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config)
    : BT::ConditionNode(condition_name,config)
{

    output("构建IsAbleStartTaskCondition")

}

BT::NodeStatus IsAbleStartTaskCondition::tick()
{
    getInput("robot_state;", robot_state_);
    if (min_battery_>GloI.power_value) {
       return BT::NodeStatus::FAILURE;
     }
    else if(!robot_state_)
    {
        return BT::NodeStatus::SUCCESS;
    }
    else
     return BT::NodeStatus::FAILURE;
}
