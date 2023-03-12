#include "is_able_start_task_condition.h"

IsAbleStartTaskCondition::IsAbleStartTaskCondition(
        const std::string & condition_name)
    : BT::ConditionNode(condition_name,{})
{
    getInput("min_battery", min_battery_);


}

BT::NodeStatus IsAbleStartTaskCondition::tick()
{
    if (min_battery_>GloI.power_value) {
       return BT::NodeStatus::FAILURE;
     }
    if(0)
    {
        return BT::NodeStatus::FAILURE;
    }
     return BT::NodeStatus::SUCCESS;
}
