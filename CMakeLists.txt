cmake_minimum_required(VERSION 3.3)
project(Graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/constants/Constants.h
        src/constants/Constants.cpp
        src/model/Edge.h
        src/model/Edge.cpp
        src/model/Vertex.h
        src/model/Vertex.cpp
        src/model/Graph.h
        src/model/Graph.cpp
        src/run/Runner.h
        src/run/Runner.cpp)

add_executable(Graphs ${SOURCE_FILES})