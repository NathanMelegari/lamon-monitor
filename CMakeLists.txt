cmake_minimum_required(VERSION 3.16)

project(lamon VERSION 1.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Files ----
add_executable(lamon
    src/main.cpp
    src/lamon_commands.cpp
    src/trate_api/read_file.cpp
    src/trate_api/listen_endpoints.cpp
    src/trate_api/request_api.cpp
    src/trate_api/update_stats.cpp
    src/trate_api/show_monitor.cpp
)

# ---- Find libcurl ----
find_package(CURL REQUIRED)

target_link_libraries(lamon PRIVATE CURL::libcurl)

target_compile_options(lamon PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(lamon PRIVATE include)

install(TARGETS lamon RUNTIME DESTINATION bin)
