set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)
project(main)
#Add additional files to set with a space 
set(SOURCE buildMaze.cpp DisjSets.cpp maze.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
