cmake_minimum_required (VERSION 3.8)


project (class)


add_executable (class  main.cpp Vector.h Vector.cpp VectorVert.h VectorVert.cpp VectorHor.h VectorHor.cpp test.h test.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")