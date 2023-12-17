set(SRC_FILES
    source.cc
    source.h
)

add_library(srclib ${SRC_FILES})

target_link_libraries(srclib PUBLIC ${Boost_LIBRARIES})
target_include_directories(srclib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
