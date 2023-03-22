#include "state_control.h"

int main(int argc, char* argv[]) {

    std::unordered_map<int,std::shared_ptr<StateControl>> robot_list;

    robot_list[1] = std::make_shared<StateControl>("1",[&robot_list](int state){
        output("instance 1 receive:"<< state)
        if(state==99)  robot_list.erase(1);

        output((robot_list[1]==nullptr?"已赋值空":"未赋值空"))
    });

    robot_list[1].get()->startInit();

//    robot_list[2] = std::make_shared<StateControl>("2",[&robot_list](int state){
//        output("instance 2 receive:"<< state)
//        if(state==88)
//        {
//           robot_list.erase(2);
//        }
//        });
//    robot_list[2].get()->startInit();


    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
