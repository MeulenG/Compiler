# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (CodeGen "CodeGen.cpp" "CodeGen.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CodeGen PROPERTY CXX_STANDARD 20)
endif()