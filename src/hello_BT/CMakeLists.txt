# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置

cmake_minimum_required (VERSION 3.5.1)

project ("hello_BT")
include_directories(
    ${BEHAVIOR_TREE_INCLUDE}
    ${BEHAVIOR_TREE_NODE}
    )
link_directories(${BEHAVIOR_TREE_LIBRARY})

file(GLOB SRC_FILES
 *.cpp
 *.h
 ${BEHAVIOR_TREE_NODE}/*.cpp
 ${BEHAVIOR_TREE_NODE}/*.h
)
message("node dir " ${BEHAVIOR_TREE_NODE} "  aa" ${BEHAVIOR_TREE_INCLUDE})

add_executable(${PROJECT_NAME} ${SRC_FILES}) 

# TODO: 如有需要，请添加测试并安装目标。
target_link_libraries(${PROJECT_NAME} libbehaviortree_cpp.so)

