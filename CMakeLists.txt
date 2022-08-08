# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Compiler")

set(CMAKE_CXX_STANDARD 14)
set(BUILD_ARCH "-m64")
set(TARGET_64 ON)
set (C_COMPILER clang++)
set (C_FLAGS -g -O3)

# llvm setup
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})


# Include sub-projects.
add_subdirectory ("Compiler")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/llvm-project/llvm)

target_link_libraries(${PROJECT_NAME} ${llvm_libs})