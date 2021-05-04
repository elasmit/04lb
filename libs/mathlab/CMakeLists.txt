project(mathlab)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} ${COMMON_LIB_DEPS})

target_include_directories(
        ${PROJECT_NAME}
        INTERFACE
        .
)
