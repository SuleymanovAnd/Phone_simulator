cmake_minimum_required(VERSION 3.22)

set(MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set (SOURCE
        main.cpp
        isNum.cpp
        phone.cpp
        number.cpp
        )
set (INCLUDE
        ${MY_DIRECTORY}/isNum.h
        ${MY_DIRECTORY}/phone.h
        ${MY_DIRECTORY}/number.h
        )

add_executable(phone_simulator ${SOURCE} ${INCLUDE} )
target_include_directories(phone_simulator PUBLIC ${MY_DIRECTORY})