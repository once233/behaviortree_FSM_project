#include "back_to_idle_or_abnormal_action.h"

BackToIdleOrAbnormalAction::BackToIdleOrAbnormalAction(const std::string& name, const BT::NodeConfig& config):BT::SyncActionNode(name, config)
{
    output("构建BackToIdleOrAbnormalAction")
}
BT::NodeStatus BackToIdleOrAbnormalAction::tick()
{
    output("返回空闲或异常")
    getInput("robot_state", robot_state_);
    return BT::NodeStatus::SUCCESS;
//    switch (robot_state_) {
//    case 0:
//    {
//        return BT::NodeStatus::FAILURE;
//     break;
//    }
//    case 1:
//    {
//     return BT::NodeStatus::SUCCESS;
//     break;
//    }
//    default:
//        return BT::NodeStatus::FAILURE;
//    }
}
