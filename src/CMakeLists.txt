cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCE
        main.cpp

        )
set(INCLUDE
        ${MY_DIRECTORY}/kitchen.h
        ${MY_DIRECTORY}/waiter.h
        ${MY_DIRECTORY}/deliveryman.h
        )


add_executable(elf_village ${SOURCE} ${INCLUDE})
target_include_directories (elf_village PUBLIC ${MY_DIRECTORY})
