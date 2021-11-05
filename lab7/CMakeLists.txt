cmake_minimum_required(VERSION 2.7)
project(l7_prep C)

set(CMAKE_C_STANDARD 11)




# Add all your .h/.cpp files here (just after "main.c",
# separated by a whiespace)
# Note: If you have a directory outside your code file,
# add the directory name, e.g: Graph/Figure.h
set(SOURCE_FILES main.c tree.c tree.h)


add_executable(l7_prep ${SOURCE_FILES})

# Compile flags
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic" CACHE STRING "Set C++ Compiler Flags" FORCE)