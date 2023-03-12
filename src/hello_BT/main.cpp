#include "hello_behavior_tree.h"

int main() {

BehaviorTreeFactory factory;
factory.registerNodeType<CalculateGoal>("CalculateGoal");
factory.registerNodeType<PrintTarget>("PrintTarget");

struct Pose2D
{
    int x;
    int y;
};
Pose2D mygoal = { 1,14};

auto blackboard = Blackboard::create();
auto tree = factory.createTreeFromText(xml_text,blackboard);
blackboard->set("mygoal",mygoal);

Pose2D aftergoal;
blackboard->get<Pose2D>("mygoal",aftergoal);
std::cout<< aftergoal.x<< " " << aftergoal.y;
mygoal ={3,3};
blackboard->set<Pose2D>("mygoal",mygoal);
blackboard->get<Pose2D>("mygoal",aftergoal);
std::cout<< aftergoal.x<< " &" << aftergoal.y;
tree.tickWhileRunning();




/* Expected output:
*
  Target positions: [ 1.1, 2.3 ]
  Converting string: "-1;3"
  Target positions: [ -1.0, 3.0 ]
*/
  return 0;
}
