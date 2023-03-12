#include "state_control.h"

int main(int argc, char* argv[]) {


    SCtrI.run();
    SCtrI.startInit();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}
