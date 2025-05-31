# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TheatreProject_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TheatreProject_autogen.dir/ParseCache.txt"
  "TheatreProject_autogen"
  )
endif()
