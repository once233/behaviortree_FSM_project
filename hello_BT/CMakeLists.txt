# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("hello_BT")
# set(BEHAVIOR_TREE_LIBRARY ${PROJECT_SOURCE_DIR}/lib)
#set(BEHAVIOR_TREE_INCLUDE ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp)
include_directories(
    ${BEHAVIOR_TREE_INCLUDE}
    ${BEHAVIOR_TREE_NODE}
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/loggers
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/scripting
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/flatbuffers
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/decorators
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/controls
    # ${PROJECT_SOURCE_DIR}/include/behaviortree_cpp/actions
    )
link_directories(${BEHAVIOR_TREE_LIBRARY})

file(GLOB SRC_FILES
 src/*.cpp
 src/*.h
 ${BEHAVIOR_TREE_NODE}/*.cpp
 ${BEHAVIOR_TREE_NODE}/*.h
)
message("node dir " ${BEHAVIOR_TREE_NODE})

add_executable(${PROJECT_NAME} ${SRC_FILES})

# TODO: 如有需要，请添加测试并安装目标。
target_link_libraries(${PROJECT_NAME} libbehaviortree_cpp.so)

