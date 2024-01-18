cmake_minimum_required(VERSION 3.16)

project (vector LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

add_executable(vector src/week01_solution.cpp)

# Include sub-projects.
add_subdirectory (include)
add_subdirectory (src)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()