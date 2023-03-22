#include "is_able_start_task_condition.h"

IsAbleStartTaskCondition::IsAbleStartTaskCondition(
        const std::string & condition_name, const BT::NodeConfig& config,const int &robot_state)
    : BT::ConditionNode(condition_name,config),robot_state_(robot_state),count_(0)
{

output("构建IsAbleStartTaskCondition" <<"debug message")
         config.blackboard->debugMessage();
config_ = config;
}

BT::NodeStatus IsAbleStartTaskCondition::tick()
{

    output("是否满足开始任务条件 robot_state "<<robot_state_)
//    setOutput<std::string>("count", std::to_string(30));
    std::string co;
    output("after set output count:  "<<co)
     if(desc_=="")
    {
        std::string s;
        config_.blackboard.get()->get<std::string>("desc",s);
        desc_ = s;


                sub.setCallback([this](std::string a){
//                setOutput("count", std::to_string(count_++));
           output("IsAbleExecuteTaskCondition revive pub  "<<a)
        },desc_);
    }
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
