# TODO: Try to find 10.8, then 10.9, 10.10, 10.11. Look first in xcode then in /Developer legacy
# dir.
set(SDK_MIN "10.11")
set(SDK "10.11")
set(DEV_SDK "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX${SDK}.sdk")

add_definitions(
  -DMAC
  -DGCC_VISIBILITY
  -mmacosx-version-min=${SDK_MIN}
  )

set(CMAKE_OSX_SYSROOT ${DEV_SDK})
