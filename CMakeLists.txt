cmake_minimum_required(VERSION 3.10)
project(Lamon)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

add_executable(lamon
    src/main.cpp
    src/request.cpp
)

install(TARGETS lamon DESTINATION bin)

target_link_libraries(lamon CURL::libcurl)
