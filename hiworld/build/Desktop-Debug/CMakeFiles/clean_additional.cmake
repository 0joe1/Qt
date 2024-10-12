# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/hiworld_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/hiworld_autogen.dir/ParseCache.txt"
  "hiworld_autogen"
  )
endif()
