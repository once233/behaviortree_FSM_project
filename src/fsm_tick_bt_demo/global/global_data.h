#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <iostream>
#include <queue>
#include "define.h"

#define GloI GlobalData::instance()

/// \brief 全局数据类
class GlobalData {
 public:
  static GlobalData& instance();

  ~GlobalData() {}
  GlobalData(const GlobalData&) = delete;
  GlobalData& operator=(const GlobalData&) = delete;
  void run(){output("running globalData")}

 private:
  GlobalData();
private:
  struct task_info{
      std::string name;
  };
public:
int power_value;
bool is_charge;
std::queue<task_info> task_queue;
};

#endif // GLOBALDATA_H
