#include "state_control.h"
#include "global_data.h"
#define RF ctrl_fsm_.get()->getFsm().get()

StateControl &StateControl::instance() {

  static StateControl instance{};
  return instance;
}

StateControl::StateControl()
{
    if (ctrl_fsm_ == nullptr) {
      ctrl_fsm_ = std::make_shared<FSMControl>();
      output("创建控制器成功")
    }

   RF->set_current_states("Init"_s);
   simulatePowerChange();
}

void StateControl::simulatePowerChange()
{
    std::thread power_simulate([this]() {
        while(1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if(GloI.power_value<=100&&!GloI.is_charge)
            {
                if(--GloI.power_value<=20)
                {
                    output("电量低，停止任务准备充电")
                    RF->process_event(FSMControl::BatteryLowEvent{});
                }
                output("电量: "<<GloI.power_value)

            }
            else if(GloI.is_charge)
            {
                if(++GloI.power_value>=100)
                {
                    output("充电结束")
                    RF->process_event(FSMControl::BatteryFullEvent{});
                }
                else
                {
                    output("充电中...电量： "<< GloI.power_value)
                }

            }
            else
            {
                --GloI.power_value;
                output("电量: "<<GloI.power_value)
            }

        }

    });
    power_simulate.detach();
}


void StateControl::startDoTask()
{
    output("开始执行任务")
    RF->process_event(FSMControl::DoTaskEvent{});
}


void StateControl::startInit()
{
    output("开始初始化")
    RF->process_event(FSMControl::InitEvent{"初始化需要的信息"});
}
