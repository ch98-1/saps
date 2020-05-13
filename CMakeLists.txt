cmake_minimum_required (VERSION 3.0.2)

# Basic project setup
cmake_policy(SET CMP0048 NEW)
project (saps VERSION 0.1.0)

# Find source files
FILE(GLOB_RECURSE SourceFiles src/*.c)
FILE(GLOB_RECURSE HeaderFiles src/*.h)

# Create the executable
include_directories (
  "${PROJECT_SOURCE_DIR}/src"
  )
add_executable (saps ${SourceFiles})

# Add install targets
install (TARGETS saps DESTINATION bin)
install (FILES ${HeaderFiles} DESTINATION include)


# Set target properties for various platforms
set_target_properties(saps PROPERTIES
  C_STANDARD 99)


# Packaging
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VENDOR "Corwin Hansen")
include (CPack)

