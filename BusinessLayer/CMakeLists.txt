cmake_minimum_required(VERSION 3.26)
project(CandyCrush)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        Board.cpp
        Board.h
        BoardManager.cpp
        Candy.cpp
        level.cpp
        level.h
        GameController.cpp
        public/GameController.h
        public/DTOs.h
        public/GameEvents.h
)
add_library(BusinessLayer STATIC ${SOURCES})

#add_executable(untitled main.cpp
#        Board.cpp
#        BoardManager.cpp
#        Candy.cpp
#        level.cpp
#        level.h
#        GameController.cpp
#        GameController.h
#        DTOs.h)
