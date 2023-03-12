#ifndef ISHAVEUNEXECUTEDTASKCONDITION_H
#define ISHAVEUNEXECUTEDTASKCONDITION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"

class IsHaveUnexecutedTaskCondition: public BT::ConditionNode
{
public:

    IsHaveUnexecutedTaskCondition(
      const std::string & condition_name, const BT::NodeConfig& config);

    IsHaveUnexecutedTaskCondition() = delete;

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
      return {};
    }

  private:
};

#endif // ISHAVEUNEXECUTEDTASKCONDITION_H
