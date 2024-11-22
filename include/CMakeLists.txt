# CMakeLists.txt for the include directory of AllocX

# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.15)

# Define the project name and language
project(AllocXHeaders LANGUAGES C)

# Set the base directory for headers
set(ALLOCX_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# List all public header files
set(ALLOCX_PUBLIC_HEADERS
    ${ALLOCX_INCLUDE_DIR}/allocx.h
    ${ALLOCX_INCLUDE_DIR}/allocx_atomic.h
    ${ALLOCX_INCLUDE_DIR}/allocx_core_types.h
    ${ALLOCX_INCLUDE_DIR}/allocx_errors.h
    ${ALLOCX_INCLUDE_DIR}/memory_pool.h
)

# Create an interface library to hold the headers
add_library(allocx_headers INTERFACE)

# Specify the include directories for the interface library
target_include_directories(allocx_headers INTERFACE ${ALLOCX_INCLUDE_DIR})

# Install the headers to the appropriate destination
install(FILES ${ALLOCX_PUBLIC_HEADERS} DESTINATION include/allocx)
