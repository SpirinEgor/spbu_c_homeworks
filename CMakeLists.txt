cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
    library/commonUtils/mysorts.c
)
add_library(library ${SOURCE_LIB})

add_executable(hw2.4 homework_2/hw2.4/main.c)
target_link_libraries(hw2.4 library)
