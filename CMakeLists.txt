cmake_minimum_required(VERSION 3.25)
project(digital_lib)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

add_executable(${PROJECT_NAME}
        src/db.cpp
        src/db_filler.cpp
        src/main.cpp

        include/db.h
        include/db_filler.h
        include/util.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${SQLite3_LIBRARIES}
        spdlog::spdlog
        fmt::fmt)
