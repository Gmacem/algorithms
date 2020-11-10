file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/algorithms/*.h")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
#set(HEADER_LIST "${CMAKE_SOURCE_DIR}/include/algorithms/graph.h")
add_library(algo_lib 
    ${SOURCE_LIST}
    ${HEADER_LIST})

target_include_directories(algo_lib PUBLIC ../include)
