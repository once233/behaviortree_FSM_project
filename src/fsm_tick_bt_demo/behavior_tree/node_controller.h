#ifndef NODECONTROLLER_H
#define NODECONTROLLER_H
#include "define.h"

#include "behaviortree_cpp/bt_factory.h"
#include "action/back_to_idle_or_abnormal_action.h"
#include "action/start_execute_task_action.h"
#include "condition/is_able_execute_task_condition.h"
#include "condition/is_able_start_task_condition.h"
#include "condition/is_have_unexecuted_task_condition.h"
class NodeController
{
public:
    NodeController();
    BT::BehaviorTreeFactory factory_;
    BT::Tree *tree_;
    void registerTaskNode();
    void registerTree(const std::string &file_name);
    BT::Tree createTree(const std::string &tree_name,BT::Blackboard::Ptr &blackboard);
    BT::Tree createTree(const std::string &tree_name);
};

#endif // NODECONTROLLER_H


