cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(OmniRobot C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

pico_sdk_init()

add_executable(runnable
main.cpp
Motors/motors_control.cpp
)

target_link_libraries(runnable pico_stdlib hardware_pwm) 


pico_add_extra_outputs(runnable)