cmake_minimum_required(VERSION 3.23)
project(Projet_info C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Sim)
include_directories(test)

add_executable(Projet_info
        Sim/simulateur.c
        Sim/simulateur.h
        Sim/test_simulateur.c
        #test/autotests.c
        test/autotests.h
        consigne.c
        consigne.h
        define.h
        regulation.c
        regulation.h
        visualisationC.c
        visualisationC.h
        visualisationT.c
        visualisationT.h)
