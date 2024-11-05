cmake_minimum_required(VERSION 3.28)
project(Biblioteki C)

set(CMAKE_C_STANDARD 99)

add_library(Biblioteki STATIC test.c
        sll_lib.c
        ../Hashtable/ht_lib.c
        ../Hashtable/ht_lib-list_collisions.c)
