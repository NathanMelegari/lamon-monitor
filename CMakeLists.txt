cmake_minimum_required(VERSION 3.16)

project(lamon VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Files ----
add_executable(lamon
    src/main.cpp
    src/request.cpp
)

# ---- Find libcurl ----
find_package(CURL REQUIRED)

target_include_directories(lamon PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(lamon PRIVATE CURL::libcurl)

install(TARGETS lamon DESTINATION /usr/local/bin)
