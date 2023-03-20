#include "is_able_start_task_condition.h"

IsAbleStartTaskCondition::IsAbleStartTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config,const int &robot_state)
    : BT::ConditionNode(condition_name,config),robot_state_(robot_state)
{

    output("构建IsAbleStartTaskCondition")

}

BT::NodeStatus IsAbleStartTaskCondition::tick()
{

    setOutput("robot_state;", robot_state_);

    output("是否满足开始任务条件 robot_state "<<robot_state_)
    if (min_battery_>GloI.power_value) {
       return BT::NodeStatus::FAILURE;
     }
    else
    {
        return BT::NodeStatus::SUCCESS;
    }
//    else
//     return BT::NodeStatus::FAILURE;
}
