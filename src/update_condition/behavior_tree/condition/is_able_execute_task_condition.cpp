#include "is_able_execute_task_condition.h"

IsAbleExecuteTaskCondition::IsAbleExecuteTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config): BT::ConditionNode(condition_name,config)
{
    output("构建IsAbleExecuteTaskCondition")

}
BT::NodeStatus IsAbleExecuteTaskCondition::tick()
{

    getInput("robot_state", robot_state_);
    output("是否满足任务执行条件： robot_state "<<robot_state_)
    if (!robot_state_) {
       output("满足")
       return BT::NodeStatus::SUCCESS;
     }
    else
    {
       output("不满足")
       return BT::NodeStatus::FAILURE;
    }
//     return BT::NodeStatus::SUCCESS;

}
