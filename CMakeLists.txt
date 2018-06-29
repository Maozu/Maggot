cmake_minimum_required(VERSION 3.10)
project(Snake C)

set(CMAKE_C_STANDARD 99)

add_executable(snake main.c Snake/snake.h)