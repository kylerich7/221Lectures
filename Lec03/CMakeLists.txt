cmake_minimum_required(VERSION 3.17)
project(Lec03)

set(CMAKE_CXX_STANDARD 14)

include_directories(DoubleLinked)
include_directories(LinkedList)
include_directories(old)

add_executable(Lec03
        DoubleLinked/DLList.cpp
        DoubleLinked/DLList.h
        DoubleLinked/NodeDLL.cpp
        DoubleLinked/NodeDLL.h
        LinkedList/LList.cpp
        LinkedList/LList.h
        LinkedList/NodeLL.cpp
        LinkedList/NodeLL.h
        old/DLLOps.cpp
        old/DLLOps.h
        old/LLOps.cpp
        old/LLOps.h
        main.cpp)
