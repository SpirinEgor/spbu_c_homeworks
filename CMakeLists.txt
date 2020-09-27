cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
    library/commonUtils/list.c
)
add_library(library ${SOURCE_LIB})

add_executable(hw3.1 homework_3/hw3.1/main.c)
target_link_libraries(hw3.1 library)
