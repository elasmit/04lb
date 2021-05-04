include(CTest)

if("${CMAKE_SYSTEM}" MATCHES "Windows")
# Unit tests
enable_testing()

###### Add google-test ######

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(googletest)

set(GTEST_INCLUDE_DIR ${googletest_SOURCE_DIR}/include)

list(APPEND GTEST_COMMON_LIBS gtest gtest_main)
###### Add test sub-projects ######

add_subdirectory(gtests)
endif()


