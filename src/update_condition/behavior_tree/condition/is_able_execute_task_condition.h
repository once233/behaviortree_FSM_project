#ifndef ISABLEEXECUTETASKCONDITION_H
#define ISABLEEXECUTETASKCONDITION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class IsAbleExecuteTaskCondition : public BT::ConditionNode
{
public:
    IsAbleExecuteTaskCondition(
      const std::string & condition_name, const BT::NodeConfig& config);

    IsAbleExecuteTaskCondition() = delete;

    /**
     * @brief The main override required by a BT action
     * @return BT::NodeStatus Status of tick execution
     */
    BT::NodeStatus tick() override;




    /**
     * @brief Creates list of BT ports
     * @return BT::PortsList Containing node-specific ports
     */
    static BT::PortsList providedPorts()
    {
        return {
          BT::InputPort<int>("robot_state")
        };
    }
private:
    int robot_state_;
};

#endif // ISABLEEXECUTETASKCONDITION_H
