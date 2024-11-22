# Minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Project definition
project(AllocX
    VERSION 1.0.0
    DESCRIPTION "High-performance, cross-platform memory management library for low-latency systems"
    LANGUAGES C
)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable testing
include(CTest)

# Enable compile warnings
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Options
option(ALLOCX_BUILD_TESTS "Build tests for AllocX" ON)
option(ALLOCX_ENABLE_SANITIZERS "Enable sanitizers for debugging" OFF)

# Sanitizers (if enabled)
if(ALLOCX_ENABLE_SANITIZERS AND (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang"))
    add_compile_options(-fsanitize=address -fsanitize=undefined)
    add_link_options(-fsanitize=address -fsanitize=undefined)
endif()

# Define project directories
set(ALLOCX_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ALLOCX_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# Create the AllocX library target
add_library(allocx STATIC
    ${ALLOCX_SOURCE_DIR}/memory_pool.c
    ${ALLOCX_SOURCE_DIR}/memory_buffer.c
)

# Include directories
target_include_directories(allocx
    PUBLIC ${ALLOCX_INCLUDE_DIR}
)

# Library properties
set_target_properties(allocx PROPERTIES
    OUTPUT_NAME allocx
    POSITION_INDEPENDENT_CODE ON
)

# Install AllocX
install(TARGETS allocx
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY ${ALLOCX_INCLUDE_DIR}/allocx DESTINATION include)

# Tests (if enabled)
#if(ALLOCX_BUILD_TESTS)
#    enable_testing()
#    add_subdirectory(tests)
#endif()