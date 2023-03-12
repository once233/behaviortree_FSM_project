#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <iostream>
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

 public:
int power_value;
bool is_charge;
};

#endif // GLOBALDATA_H
