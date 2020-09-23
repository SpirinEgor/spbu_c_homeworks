cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)

add_library(library ${SOURCE_LIB})

add_executable(hw1.1 homework_1/hw1.1/main.c)
add_executable(hw1.2 homework_1/hw1.2/main.c)
add_executable(hw1.3 homework_1/hw1.3/main.c)
add_executable(hw1.4 homework_1/hw1.4/main.c)
add_executable(hw1.5 homework_1/hw1.5/main.c)
