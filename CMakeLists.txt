cmake_minimum_required(VERSION 3.25)
project(OpenMP_Exercises LANGUAGES CXX)

# Force C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and configure OpenMP
find_package(OpenMP REQUIRED)

# Find all .cpp files in the src/ directory
file(GLOB SRC_FILES "src/*.cpp")

# Loop through each file to create individual executables
foreach(FILE_PATH ${SRC_FILES})
    # Extract the filename without the path and extension (e.g., "src/critical.cpp" -> "critical")
    get_filename_component(EXE_NAME ${FILE_PATH} NAME_WE)
    
    # Define the executable target
    add_executable(${EXE_NAME} ${FILE_PATH})
    
    # Link OpenMP flags/libraries to this specific target
    target_link_libraries(${EXE_NAME} PRIVATE OpenMP::OpenMP_CXX)
endforeach()