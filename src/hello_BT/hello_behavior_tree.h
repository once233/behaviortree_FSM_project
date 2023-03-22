#ifndef __HELLO_BEHAVIOR_TREE_H__
#define __HELLO_BEHAVIOR_TREE_H__
#include "behaviortree_cpp/bt_factory.h"

using namespace BT;

/* This tutorial will teach you how to deal with ports when its
 *  type is not std::string.
*/

// We want to be able to use this custom type
struct Position2D
{
  double x, y;
};

// It is recommended (or, in some cases, mandatory) to define a template
// specialization of convertFromString that converts a string to Position2D.
namespace BT
{
template <>
inline Position2D convertFromString(StringView str)
{
  printf("Converting string: \"%s\"\n", str.data());

  // real numbers separated by semicolons
  auto parts = splitString(str, ';');
  if (parts.size() != 2)
  {
    throw RuntimeError("invalid input)");
  }
  else
  {
    Position2D output;
    output.x = convertFromString<double>(parts[0]);
    output.y = convertFromString<double>(parts[1]);
    return output;
  }
}
}   // end namespace BT

class CalculateGoal : public SyncActionNode
{
public:
  CalculateGoal(const std::string& name, const NodeConfig& config) :
    SyncActionNode(name, config)
  {}

  NodeStatus tick() override
  {
    Position2D mygoal = {1.1, 2.3};
    setOutput("goal", mygoal);
    return NodeStatus::SUCCESS;
  }
  static PortsList providedPorts()
  {
    return {OutputPort<Position2D>("goal")};
  }
};

class PrintTarget : public SyncActionNode
{
public:
  PrintTarget(const std::string& name, const NodeConfig& config) :
    SyncActionNode(name, config)
  {}

  NodeStatus tick() override
  {
    auto res = getInput<Position2D>("target");
    if (!res)
    {
      throw RuntimeError("error reading port [target]:", res.error());
    }
    Position2D goal = res.value();
    printf("Target positions: [ %.1f, %.1f ]\n", goal.x, goal.y);
    return NodeStatus::SUCCESS;
  }

  static PortsList providedPorts()
  {
    // Optionally, a port can have a human readable description
    const char* description = "Simply print the target on console...";
    return {InputPort<Position2D>("target", description)};
  }
};

//----------------------------------------------------------------

/** The tree is a Sequence of 4 actions

*  1) Store a value of Position2D in the entry "GoalPosition"
*     using the action CalculateGoal.
*
*  2) Call PrintTarget. The input "target" will be read from the Blackboard
*     entry "GoalPosition".
*
*  3) Use the built-in action Script to write the key "OtherGoal".
*     A conversion from string to Position2D will be done under the hood.
*
*  4) Call PrintTarget. The input "goal" will be read from the Blackboard
*     entry "OtherGoal".
*/

// clang-format off
static const char* xml_text = R"(

 <root BTCPP_format="4" >
     <BehaviorTree ID="MainTree">
        <Switch2 case_1="c1" case_2="c2" variable="c2">
            <Sequence>
                <CalculateGoal   goal="{GoalPosition}" />
                <PrintTarget     target="{GoalPosition}" />
                <Script          code="OtherGoal='-1;3'" />
                <PrintTarget     target="{OtherGoal}" />
            </Sequence>
            <Sequence>
                <CalculateGoal   goal="{GoalPosition}" />
                <PrintTarget     target="{GoalPosition}" />
            </Sequence>
            <Sequence>
                <PrintTarget     target="{GoalPosition}" />
            </Sequence>
        </Switch2>
     </BehaviorTree>
 </root>
 )";

//        <Sequence name="root">
//            <CalculateGoal   goal="{GoalPosition}" />
//            <PrintTarget     target="{GoalPosition}" />
//            <Script          code="OtherGoal='-1;3'" />
//            <PrintTarget     target="{OtherGoal}" />
//        </Sequence>


// clang-format on

#endif
