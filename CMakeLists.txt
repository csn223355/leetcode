# 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
project(leetcode)

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    message(STATUS "include_directories : ${OpenCV_INCLUDE_DIRS}")
    message(STATUS "_LIBRARIES: ${OpenCV_LIBS}")
else()
    message("Can not find opnecv ")
endif()


# 添加opencv库b0
# find_package(OpenCV REQUIRED)

# 添加头文件（两个target都需要）
# include_directories(${OpenCV_INCLUDE_DIRS})
# link_libraries(${OpenCV_LIBS})



# 将src目录下的所有cpp文件编译成对应的可执行文件
# 例如：src/1_read_image.cpp -> 1_read_image
# 列出src目录下的所有cpp文件，存入SRC_FILES变量，它是一个列表，GLOBAL_RECURSE表示递归查找
file(GLOB_RECURSE SRC_FILES 
    ListCode/*.cpp
    array/*.cpp
    hashtable/*.cpp
    str/*.cpp)

# message(STATUS "SRC_FILES: ${SRC_FILES}")

# 遍历SRC_FILES列表，对每个文件编译成一个可执行文件
foreach(SRC_FILE ${SRC_FILES})
    # 获取文件名，不包含后缀，存入TARGET_NAME变量，NAME_WLE：File name with neither the directory nor the last extension
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WLE) 
    # 添加可执行文件
    add_executable(${TARGET_NAME} ${SRC_FILE})
    target_include_directories(${TARGET_NAME} PRIVATE "./include")
endforeach()




#[[
cmake -S . -B build 
cmake --build build 
]]