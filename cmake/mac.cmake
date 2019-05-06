# TODO clean up older SDK version
set(SDKs
    10.8
    10.9
    10.10
    10.11
    10.12
    10.13
    10.14)

foreach (sdk IN LISTS SDKs)
  set(SDK ${sdk})

  set(DEV_SDK "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX${SDK}.sdk")
  if (EXISTS "${DEV_SDK}" AND IS_DIRECTORY "${DEV_SDK}")
    break()
  endif()

  set(DEV_SDK "/Developer/SDKs/MacOSX${SDK}.sdk")
  if (EXISTS "${DEV_SDK}" AND IS_DIRECTORY "${DEV_SDK}")
    break()
  endif()
endforeach()

if (NOT EXISTS "${DEV_SDK}" AND NOT IS_DIRECTORY "${DEV_SDK}")
  message(FATAL_ERROR "Could not find any of the following Mac OS X SDKs: ${SDKs}")
endif()

add_definitions(
  -DMAC
  -DGCC_VISIBILITY
  -mmacosx-version-min=${SDK}
  )

set(CMAKE_OSX_SYSROOT ${DEV_SDK})
