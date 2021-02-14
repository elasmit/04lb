cmake_minimum_required(VERSION 3.16)
set(CXX_STANDARD_REQUIRED 11)

project("04lb")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/../bin")

add_subdirectory("libs")
add_subdirectory("projects")