#指定CMake工具最低版本3.10
cmake_minimum_required(VERSION 3.5)
#项目名称：lvgl
project(lvgl)
#c标准：C11
set(CMAKE_C_STANDARD 11)#C11
#C++标准C17
set(CMAKE_CXX_STANDARD 17)#C17
#强制要求编译器严格支持由 CMAKE_CXX_STANDARD 指定的 C++ 标准版本
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置C编译器为arm-linux-gcc
set(CMAKE_C_COMPILER "arm-linux-gcc")
# 如果需要C++支持，设置C++编译器为arm-linux-g++
set(CMAKE_CXX_COMPILER "arm-linux-g++")

#INCLUDE_DIRECTORIES：向编译器添加头文件包含目录。它会为当前目录及所有子目录中的所有目标添加搜索路径。
#PROJECT_SOURCE_DIR： CMakeLists.txt 文件所在的绝对路径
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/lvgl)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/my_code)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/lv_drivers)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}//lv_drivers/display)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}//lv_drivers/indev)

#寻找这些目录中的所有头文件和源文件
file(GLOB_RECURSE INCLUDES   "lv_drivers/*.h" "lvgl/demos/*.h"  "lvgl/*.h"  "./*.h" "my_code/*.h")
file(GLOB_RECURSE SOURCES    "lv_drivers/*.c" "lvgl/demos/*.c"  "lvgl/src/*.c" "my_code/*.c")

#指定最后的可执行文件输出路径
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#优化等级：最高等级-03
SET(CMAKE_CXX_FLAGS "-O3")

#指定可执行文件名为main，源文件为main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES}
add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})

#为后续的目标添加一个宏定义LV_CONF_INCLUDE_SIMPLE，值为1
# add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)