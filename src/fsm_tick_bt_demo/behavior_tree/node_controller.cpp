#include "node_controller.h"

NodeController::NodeController()
{

}
void NodeController::registerTaskNode()
{
    output("注册任务节点")
    factory_.registerNodeType<BackToIdleOrAbnormalAction>("BackToIdleOrAbnormal");
    factory_.registerNodeType<StartExecuteTaskAction>("StartExecuteTask");
    factory_.registerNodeType<IsAbleExecuteTaskCondition>("IsAbleExecuteTask");
    factory_.registerNodeType<IsAbleStartTaskCondition>("IsAbleStartTask");
    factory_.registerNodeType<IsHaveUnexecutedTaskCondition>("IsHaveUnexecutedTask");
    factory_.registerSimpleAction("HaltTaskHandle",simpleHaltTaksHandle);
}

BT::NodeStatus simpleHaltTaksHandle(BT::TreeNode& self)
{

    output("simpleHaltTaksHandle tick!!!!!")
    return BT::NodeStatus::FAILURE;
}

void NodeController::registerTree(const std::string &file_name)
{
    output("注册树结构")
    factory_.registerBehaviorTreeFromFile(file_name);
}

BT::Tree NodeController::createTree(const std::string &tree_name,BT::Blackboard::Ptr blackboard)
{
    output("创建树")
    return factory_.createTree(tree_name,blackboard);
}

BT::Tree NodeController::createTree(const std::string &tree_name)
{
    output("创建树,不传入黑板")
    return factory_.createTree(tree_name);
}
