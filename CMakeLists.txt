# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Project name and description
project(AllocX
    VERSION 1.0
    DESCRIPTION "A high-performance, cross-platform memory management library designed for low-latency, high-frequency systems."
    LANGUAGES C CXX
)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
enable_testing()

# Options
option(ALLOCX_BUILD_TESTS "Build unit tests" ON)
option(ALLOCX_BUILD_EXAMPLES "Build examples" ON)

# Define output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include source directories
add_subdirectory(src)
add_subdirectory(include)

# Add tests if enabled
if(ALLOCX_BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Add examples if enabled
if(ALLOCX_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Documentation target
find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found. Documentation will not be generated.")
endif()

# Installation rules
include(GNUInstallDirs)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS AllocX
    EXPORT AllocXTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Export targets for downstream projects
install(EXPORT AllocXTargets
    FILE AllocXConfig.cmake
    NAMESPACE AllocX::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/AllocX
)

# Display configuration summary
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Description: ${PROJECT_DESCRIPTION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")