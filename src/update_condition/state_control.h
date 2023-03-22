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
    StateControl(std::string desc, std::function<void(int)> cb = nullptr);
    StateControl(const StateControl&) = delete;
    StateControl& operator=(const StateControl&) = delete;
    ~StateControl();
    /// \brief 机器人状态机
    std::shared_ptr<FSMControl> ctrl_fsm_ = nullptr;
//    void RegisterNode(BT::BehaviorTreeFactory &factory);
    std::function<void(int)> cb_;
    std::string desc_;
    bool exit_thread_;
    int power_value;

private:
    void simulatePowerChange();

private:


public:
    void startDoTask();
    void startInit();
};

#endif // STATE_CONTROL_H
