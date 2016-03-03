cmake_minimum_required(VERSION 3.3)
project(Graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/model/Vertex.cpp
        src/model/Vertex.h
        src/model/Edge.cpp
        src/model/Edge.h
        src/model/Graph.cpp
        src/model/Graph.h
        src/main.cpp
        src/run/Runner.cpp
        src/run/Runner.h
        src/constants/Constants.cpp
        src/constants/Constants.h)

add_executable(Graphs ${SOURCE_FILES})