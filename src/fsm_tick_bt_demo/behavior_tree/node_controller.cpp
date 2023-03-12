#include "node_controller.h"

NodeController::NodeController()
{

}
void NodeController::registerTaskNode()
{
    factory_.registerNodeType<BackToIdleOrAbnormalAction>("BackToIdleOrAbnormal");
    factory_.registerNodeType<StartExecuteTaskAction>("StartExecuteTask");
    factory_.registerNodeType<IsAbleExecuteTaskCondition>("IsAbleExecuteTask");
    factory_.registerNodeType<IsAbleStartTaskCondition>("IsAbleStartTask");
    factory_.registerNodeType<IsHaveUnexecutedTaskCondition>("IsHaveUnexecutedTask");
}
void NodeController::registerTree(const std::string &file_name)
{
    factory_.registerBehaviorTreeFromFile(file_name);
}
