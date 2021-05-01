project(array_common_tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/gtest")

set(GTEST_INCLUDE_DIR ${googletest_SOURCE_DIR}/include)

include_directories("${CMAKE_BINARY_DIR}/libs/array_common/include" ${GTEST_INCLUDE_DIR})
file(GLOB UNIT_TEST_SRC *.cpp *.cxx)

add_executable(${PROJECT_NAME} ${UNIT_TEST_SRC})

target_link_libraries(${PROJECT_NAME} array_common ${GTEST_COMMON_LIBS})

set(TEST_SUITE_NAME ArrayCommonTests)
add_test(NAME ${TEST_SUITE_NAME} COMMAND ${PROJECT_NAME})