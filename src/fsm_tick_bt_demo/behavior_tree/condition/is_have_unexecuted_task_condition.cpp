#include "is_have_unexecuted_task_condition.h"

IsHaveUnexecutedTaskCondition::IsHaveUnexecutedTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config)
    : BT::ConditionNode(condition_name,config)
{
    output("构建IsHaveUnexecutedTaskCondition")
}

BT::NodeStatus IsHaveUnexecutedTaskCondition::tick()
{

    output("是否还有未分配的任务")
    if (!GloI.task_queue_.empty()) {

       output("准备执行下一个任务:" <<GloI.task_queue_.front().name)
       GloI.cur_task_= GloI.task_queue_.front();
       output("当前任务:" <<GloI.cur_task_.name)
       GloI.task_queue_.pop();
       return BT::NodeStatus::SUCCESS;
     }
    else{
        output("任务队列中无任务，返回空闲")
        return BT::NodeStatus::FAILURE;
    }

}
