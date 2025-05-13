cmake_minimum_required(VERSION 3.30)
project(data_structure C)

set(CMAKE_C_STANDARD 17)

add_executable(data_structure main.c chapter4_stack/chapter4_dynamic_stack.c chapter4_stack/chapter4_static_stack.c
chapter5_queue/chapter5_circular_queue.c chapter5_queue/chapter5_linear_queue.c)
