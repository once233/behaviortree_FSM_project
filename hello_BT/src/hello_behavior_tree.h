#ifndef __HELLO_BEHAVIOR_TREE_H__
#define __HELLO_BEHAVIOR_TREE_H__
#include "behaviortree_cpp/bt_factory.h"


#include "dummy_nodes.h"
#include "movebase_node.h"

using namespace BT;

/** This tutorial will teach you how basic input/output ports work.
 *
 * Ports are a mechanism to exchange information between Nodes using
 * a key/value storage called "Blackboard".
 * The type and number of ports of a Node is statically defined.
 *
 * Input Ports are like "argument" of a functions.
 * Output ports are, conceptually, like "return values".
 *
 * In this example, a Sequence of 5 Actions is executed:
 *
 *   - Actions 1 and 4 read the input "message" from a static string.
 *
 *   - Actions 3 and 5 read the input "message" from an entry in the
 *     blackboard called "the_answer".
 *
 *   - Action 2 writes something into the entry of the blackboard
 *     called "the_answer".
*/

// clang-format off
static const char* xml_text = R"(

 <root BTCPP_format="4" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root">
            <SaySomething     message="hello" />
            <SaySomething2    message="this works too" />
            <ThinkWhatToSay   text="{the_answer}"/>
            <SaySomething2    message="{the_answer}" />
        </Sequence>
     </BehaviorTree>

 </root>
 )";
// clang-format on

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
  ThinkWhatToSay(const std::string& name, const BT::NodeConfig& config) :
    BT::SyncActionNode(name, config)
  {}

  // This Action simply write a value in the port "text"
  BT::NodeStatus tick() override
  {
    setOutput("text", "The answer is 42");
    return BT::NodeStatus::SUCCESS;
  }

  // A node having ports MUST implement this STATIC method
  static BT::PortsList providedPorts()
  {
    return {BT::OutputPort<std::string>("text")};
  }
};

#endif
