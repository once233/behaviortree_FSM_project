#ifndef ISBATTERYLOWCONDITION_H
#define ISBATTERYLOWCONDITION_H
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "global_data.h"
#include "publish_imitate.h"
#include <functional>
/**
 * @brief A BT::ConditionNode that listens to a battery topic and
 * returns SUCCESS when battery is low and FAILURE otherwise
 */
class IsAbleStartTaskCondition : public BT::ConditionNode
{
public:
  /**
   * @brief A constructor for nav2_behavior_tree::IsBatteryLowCondition
   * @param condition_name Name for the XML tag for this node
   * @param conf BT node configuration
   */
  IsAbleStartTaskCondition(
    const std::string & condition_name, const BT::NodeConfig& config,const int&robot_state);

  IsAbleStartTaskCondition() = delete;
 PublishImitate<std::function<void(std::string)>> sub;
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
        BT::InputPort<int>("robot_state"),
        BT::OutputPort<std::function<void(int)>>("count")
      };
  }

private:
  /**
   * @brief Callback function for battery topic
   * @param msg Shared pointer to sensor_msgs::msg::BatteryState message
   */
  double min_battery_=20;
  int robot_state_;
  std::string desc_;
    BT::NodeConfig config_;
    int count_;
};

#endif // ISBATTERYLOWCONDITION_H
