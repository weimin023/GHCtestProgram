cmake_minimum_required(VERSION 3.24.2)
project(GHCtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/boost/include)
set(CMAKE_PREFIX_PATH ${BOOST_ROOT})

find_package(Boost REQUIRED COMPONENTS system)

include_directories(${CMAKE_SOURCE_DIR}/src/ ${BOOST_ROOT})
add_subdirectory(src)


set(SOURCE_FILES main.cpp)
add_executable(GHCtest ${SOURCE_FILES})

target_link_libraries(GHCtest PRIVATE srclib pthread)


file(COPY ${CMAKE_SOURCE_DIR}/testdata DESTINATION ${CMAKE_BINARY_DIR})
