cmake_minimum_required(VERSION 3.1.0)
project(drogon_extension)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE INCLUDES "include/**.hpp")
file(GLOB_RECURSE SOURCES "src/**.cpp")

add_library(
        drogon_extension

        ${INCLUDES}
        ${SOURCES}
)

target_include_directories(drogon_extension PUBLIC "include")

target_link_libraries(drogon_extension PUBLIC ${DROGON_LIB})
