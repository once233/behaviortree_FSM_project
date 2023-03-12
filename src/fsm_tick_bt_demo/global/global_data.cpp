#include "global_data.h"
GlobalData& GlobalData::instance() {
  static GlobalData instance;
  return instance;
}

GlobalData::GlobalData():is_charge(false),power_value(100){

}
