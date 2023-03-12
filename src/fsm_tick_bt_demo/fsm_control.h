#include "boost/sml.hpp"
#include <memory>
#include <iostream>
#include "define.h"
#include "behaviortree_cpp/bt_factory.h"
#include "node_controller.h"
class FSMControl
{
private:
    struct FsmLogger {
    template <class SM, class TEvent>
    void log_process_event(const TEvent&) {
      std::cout<<"[" << boost::sml::aux::get_type_name<SM>() << "][event] " << boost::sml::aux::get_type_name<TEvent>()<<std::endl;
    }

    template <class SM, class TGuard, class TEvent>
    void log_guard(const TGuard&, const TEvent&, bool result) {
     std::cout<<"[" << boost::sml::aux::get_type_name<SM>() << "][guard] " << boost::sml::aux::get_type_name<TGuard>()
                   << " " << boost::sml::aux::get_type_name<TEvent>() << " " << (result ? "[OK]" : "[Reject]")<<std::endl;
    }

    template <class SM, class TAction, class TEvent>
    void log_action(const TAction&, const TEvent&) {
      std::cout<<"[" << boost::sml::aux::get_type_name<SM>() << "][action] " << boost::sml::aux::get_type_name<TAction>()
                   << " " << boost::sml::aux::get_type_name<TEvent>()<<std::endl;
    }

    template <class SM, class TSrcState, class TDstState>
    void log_state_change(const TSrcState& src, const TDstState& dst) {
      std::cout<<"[" << boost::sml::aux::get_type_name<SM>() << "][transition] " << src.c_str() << " -> " << dst.c_str()<<std::endl;
    }
  };



public:
    struct RobotState;   // 机器人状态机
    struct InitOKEvent {};    // 初始化成功信号
    struct BatteryLowEvent {};   // 电池量低信号
    struct BatteryFullEvent {};  // 电池充满信号
    struct StartChargeEvent {};   // 电池量低信号
    struct InitEvent {std::string init_info;};   // 初始化信号
    struct DoTaskEvent {};  // 任务信号


public:
    FSMControl();
    ~FSMControl();

    std::shared_ptr<boost::sml::sm<RobotState, boost::sml::logger<FsmLogger>>> getFsm() { return fsm_; }

public:
     void actionInit(const FSMControl::InitEvent& event);
     void actionIdel();
     void actionDoTask();
     void actionHaltTask();
     void actionCharge();

private:


private:
    /// \brief 状态机记录器
    FsmLogger logger_;
    /// \brief 状态机实例
    std::shared_ptr<boost::sml::sm<RobotState, boost::sml::logger<FsmLogger>>> fsm_ = nullptr;
    NodeController node_ctr_;


};

const auto action_init = [](FSMControl* rf, FSMControl::InitEvent e) { rf->actionInit(e); };  // 机器人初始化动作
const auto action_idle = [](FSMControl* rf) {rf->actionIdel();};    // 机器人空闲动作
const auto action_task = [](FSMControl* rf) { rf->actionDoTask();};    // 机器人任务动作
const auto action_halt_task = [](FSMControl* rf) {rf->actionHaltTask();};    // 机器人空闲动作
const auto action_charge = [](FSMControl* rf) {rf->actionCharge();};    // 机器人空闲动作
/// \brief 机器人状态
struct FSMControl::RobotState {
  auto operator()() const noexcept {
    using namespace boost::sml;
    // clang-format off
    return make_transition_table(
     *"Init"_s           + event<InitEvent>           / action_init     = "Initing"_s,
      "Initing"_s        + event<InitOKEvent>         / action_idle     = "Idle"_s,
      "Idle"_s           + event<BatteryLowEvent>     / action_idle     = "Idle"_s,
      "Idle"_s           + event<StartChargeEvent>     / action_charge  = "Charging"_s,
      "Charging"_s       + event<BatteryFullEvent>     / action_idle    = "Idle"_s,
      "Tasking"_s        + event<BatteryLowEvent>     / action_halt_task     = "Idle"_s,
      "Idle"_s           + event<DoTaskEvent>           / action_task     = "Tasking"_s
    );
    // clang-format on
  };

};
