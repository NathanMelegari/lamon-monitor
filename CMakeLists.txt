cmake_minimum_required(VERSION 3.10)

project(lamon VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
add_executable(lamon
    src/main.cpp
    src/request.cpp
)

# libcurl
find_package(CURL REQUIRED)
target_link_libraries(lamon CURL::libcurl)

# Install
install(TARGETS lamon DESTINATION /usr/local/bin)
