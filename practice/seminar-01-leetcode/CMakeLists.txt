cmake_minimum_required(VERSION 3.20)

project(Playground)

# Compilation settings
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)  # I'm fine

# Some sanitizers
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Sources
file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(executable ${SOURCE_FILES})
target_include_directories(executable PUBLIC ${PROJECT_SOURCE_DIR}/src/)
target_include_directories(executable PUBLIC ${PROJECT_SOURCE_DIR}/../support-lib)
target_compile_options(executable PUBLIC -Dlocal)

# Properties
set_target_properties(executable
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)