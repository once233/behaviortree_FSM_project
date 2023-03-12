#ifndef STATE_CONTROL_H
#define STATE_CONTROL_H

#include "fsm_control.h"
#include "define.h"
#include <thread>
#define SCtrI StateControl::instance()
using namespace boost::sml;
class StateControl
{
public:
    static StateControl& instance();
    void run() {output("running StateControl")}
    StateControl();
    StateControl(const StateControl&) = delete;
    StateControl& operator=(const StateControl&) = delete;
    /// \brief 机器人状态机
    std::shared_ptr<FSMControl> ctrl_fsm_ = nullptr;

private:
    void simulatePowerChange();

private:


public:
    void startDoTask();
    void startInit();
};

#endif // STATE_CONTROL_H
