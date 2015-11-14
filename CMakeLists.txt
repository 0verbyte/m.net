cmake_minimum_required(VERSION 3.0)
project(mnet)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Detect version
file(
  STRINGS "${CMAKE_SOURCE_DIR}/src/Version.h"
  VERSION_CONTENTS
  REGEX "MNET_VERSION"
  )
set(VERSION_LIST -1) # "empty" list.
foreach (var IN LISTS VERSION_CONTENTS)
  string(REGEX MATCH "[0-9]+" num ${var})
  list(APPEND ${VERSION_LIST} ${num})
endforeach()

list(GET ${VERSION_LIST} 0 VERSION_MAJOR)
list(GET ${VERSION_LIST} 1 VERSION_MINOR)
list(GET ${VERSION_LIST} 2 VERSION_BUILD)
set(VERSION_NUMBER "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD}")

include(platform)
include(target)

add_subdirectory(src)

message(STATUS "--------------------------------------------------")
message(STATUS "Version: ${VERSION_NUMBER}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if (APPLE)
  message(STATUS "OS X SDK: ${DEV_SDK}")
endif()
message(STATUS "--------------------------------------------------")
