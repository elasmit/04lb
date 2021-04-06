project("l03")

file(GLOB SRC src/*.cpp src/*.cxx *.cxx *.cpp calc/*.cpp calc/*.cxx)

if ("${CMAKE_SYSTEM}" MATCHES "Linux")
    add_executable(${PROJECT_NAME}.o ${SRC})
    target_link_libraries(${PROJECT_NAME}.o ${COMMON_DEPS})
elseif("${CMAKE_SYSTEM}" MATCHES "Windows")
    add_executable(${PROJECT_NAME} ${SRC})
    target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})
else()
    add_executable(${PROJECT_NAME} ${SRC})
    target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})
endif()