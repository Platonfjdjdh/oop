cmake_minimum_required(VERSION 3.27)
project(lr5)

set(CMAKE_CXX_STANDARD 17)

add_executable(lr5
        main.cpp
        SentenceSearcher.cpp
        SentenceSearcherTest.cpp
        SentenceSearcher.h)
