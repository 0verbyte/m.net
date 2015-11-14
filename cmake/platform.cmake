include(compilation)
include(deps)

if (APPLE)
  include(mac)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(LINUX 1)
endif()
if (LINUX)
  include(linux)
endif()
