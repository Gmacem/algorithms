cmake_minimum_required(VERSION 3.1)
project (algorithms)

file(GLOB SOURCES "structures/*.cpp")
add_library(native-lib SHARED ${SOURCES})
