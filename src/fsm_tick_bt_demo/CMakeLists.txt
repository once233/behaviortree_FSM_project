# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.5.1)

project ("fsm_tick_bt_demo")
# set(BEHAVIOR_TREE_LIBRARY ${PROJECT_SOURCE_DIR}/lib)
#set(BEHAVIOR_TREE_INCLUDE ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp)
include_directories(
    ${BEHAVIOR_TREE_INCLUDE}
    ${BEHAVIOR_TREE_NODE}
    ${FSM_INCLUDE}
    ${CMAKE_CACHEFILE_DIR}
    global/
    behavior_tree/
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/loggers
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/scripting
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/flatbuffers
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/decorators
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/controls
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/actions
    )
link_directories(${BEHAVIOR_TREE_LIBRARY})

file(GLOB SRC_FILES
 *.cpp
 *.h
 behavior_tree/*/*.cpp
 behavior_tree/*/*.h
 behavior_tree/*.h
 behavior_tree/*.cpp
 global/*
 ${BEHAVIOR_TREE_NODE}/*.cpp
 ${BEHAVIOR_TREE_NODE}/*.h
)
message("node dir " ${BEHAVIOR_TREE_NODE})

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} libbehaviortree_cpp.so libpthread.so)

