# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles/q2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/q2_autogen.dir/ParseCache.txt"
  "q2_autogen"
  )
endif()
