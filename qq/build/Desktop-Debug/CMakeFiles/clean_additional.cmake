# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/qq_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qq_autogen.dir/ParseCache.txt"
  "qq_autogen"
  )
endif()
