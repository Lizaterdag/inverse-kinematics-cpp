cmake_minimum_required(VERSION 3.20)
project(motion_and_vision)

set(CMAKE_CXX_STANDARD 14)

add_executable(motion_and_vision main.cpp main.h Vect.cpp Vect.h Arm.cpp Arm.h ArmSegment.cpp ArmSegment.h)
