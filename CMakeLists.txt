# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("BT_project")
set(BEHAVIOR_TREE_LIBRARY ${PROJECT_SOURCE_DIR}/lib)
set(BEHAVIOR_TREE_INCLUDE ${PROJECT_SOURCE_DIR}/include)
set(BEHAVIOR_TREE_NODE ${PROJECT_SOURCE_DIR}/lib/sample_nodes)
set(FSM_INCLUDE ${PROJECT_SOURCE_DIR}/include)
# 包含子项目。

add_subdirectory(src/hello_BT)
add_subdirectory(src/fsm_tick_bt_demo)
add_subdirectory(src/async_control)

