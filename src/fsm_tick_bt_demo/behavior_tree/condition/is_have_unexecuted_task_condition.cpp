#include "is_have_unexecuted_task_condition.h"

IsHaveUnexecutedTaskCondition::IsHaveUnexecutedTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config)
    : BT::ConditionNode(condition_name,config)
{
    output("构建IsHaveUnexecutedTaskCondition")
}

BT::NodeStatus IsHaveUnexecutedTaskCondition::tick()
{

    if (GloI.task_queue.empty()) {
       output("准备执行下一个任务")
       return BT::NodeStatus::FAILURE;
     }
    else{
        output("任务队列中无任务，返回空闲")
        return BT::NodeStatus::SUCCESS;
    }

}
