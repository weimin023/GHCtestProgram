cmake_minimum_required(VERSION 3.24.2)
project(GHCtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/src/)
include_directories(${CMAKE_SOURCE_DIR}/asio-1.28.0/include/)
add_subdirectory(src)


set(SOURCE_FILES main.cpp)
add_executable(GHCtest ${SOURCE_FILES})

target_link_libraries(GHCtest PRIVATE srclib pthread)


file(COPY ${CMAKE_SOURCE_DIR}/testdata DESTINATION ${CMAKE_BINARY_DIR})
