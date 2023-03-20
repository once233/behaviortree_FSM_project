# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.5.1)

project (async_demo VERSION 1.0)
set(PROJECT_AUTHORS yyj)

include_directories(
    ${BEHAVIOR_TREE_INCLUDE}
    ${BEHAVIOR_TREE_NODE}
    ${FSM_INCLUDE}
    ${CMAKE_CURRENT_SOURCE_DIR}
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
configure_file(cmake_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/global/cmake_config.h)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} libbehaviortree_cpp.so libpthread.so)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


