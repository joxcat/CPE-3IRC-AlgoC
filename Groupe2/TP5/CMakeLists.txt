cmake_minimum_required(VERSION 3.21)
project(TP5 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(TP5
        src/client.c
        src/client.h
        src/combinator.c
        src/combinator.h
        src/operator.c
        src/operator.h
        src/repertoire.c
        src/repertoire.h
        src/serveur.c
        src/serveur.h)
