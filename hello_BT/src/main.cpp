#include "hello_behavior_tree.h"

int main() {
using namespace DummyNodes;

  BehaviorTreeFactory factory;

  // The class SaySomething has a method called providedPorts() that define the INPUTS.
  // In this case, it requires an input called "message"
  factory.registerNodeType<SaySomething>("SaySomething");

  // Similarly to SaySomething, ThinkWhatToSay has an OUTPUT port called "text"
  // Both these ports are std::string, therefore they can connect to each other
  factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

  // SimpleActionNodes can not define their own method providedPorts(), therefore
  // we have to pass the PortsList explicitly if we want the Action to use getInput()
  // or setOutput();
  PortsList say_something_ports = {InputPort<std::string>("message")};
  factory.registerSimpleAction("SaySomething2", SaySomethingSimple, say_something_ports);

  /* An INPUT can be either a string, for instance:
     *
     *     <SaySomething message="hello" />
     *
     * or contain a "pointer" to a type erased entry in the Blackboard,
     * using this syntax: {name_of_entry}. Example:
     *
     *     <SaySomething message="{the_answer}" />
     */

  auto tree = factory.createTreeFromText(xml_text);

  tree.tickWhileRunning();

  /*  Expected output:
     *
        Robot says: hello
        Robot says: this works too
        Robot says: The answer is 42
    *
    * The way we "connect" output ports to input ports is to "point" to the same
    * Blackboard entry.
    *
    * This means that ThinkSomething will write into the entry with key "the_answer";
    * SaySomething and SaySomething will read the message from the same entry.
    *
    */
  return 0;
}
