# CMakeList.txt : CMake project for week01_solution, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (week01_solution "week01_solution.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET week01_solution PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
