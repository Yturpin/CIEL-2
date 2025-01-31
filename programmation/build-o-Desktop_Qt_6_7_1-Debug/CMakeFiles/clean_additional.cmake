# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/o_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/o_autogen.dir/ParseCache.txt"
  "o_autogen"
  )
endif()
