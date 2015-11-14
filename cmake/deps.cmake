# Qt 5
# Added some paths to help find the modules on some systems.
if (NOT WIN32)
  set(
    CMAKE_PREFIX_PATH
    ${CMAKE_PREFIX_PATH}
    "/opt/qt55"
    "/usr/local/opt"
    "/usr/local/opt/qt5"
    "/usr/local/Qt-5.5.1"
    "/usr/local/Qt-5.5.0"
    "/usr/local/Qt-5.4.2"
    "/usr/local/Qt-5.4.1"
    "/usr/local/Qt-5.4.0"
    "/usr/local/Qt-5.3.2"
    "/usr/local/Qt-5.3.1"
    "/usr/local/Qt-5.3.0"
    "/usr/local/Qt-5.2.1"
    )
else()
  set(
    CMAKE_PREFIX_PATH
    ${CMAKE_PREFIX_PATH}
    "C:/qt-everywhere-opensource-src-5.4.1-w64/qtbase/lib/cmake"
    "C:/qt-everywhere-opensource-src-5.4.0-w64/qtbase/lib/cmake"
    )
endif()

set(CMAKE_AUTOMOC ON) # moc when necessary.
set(CMAKE_AUTORCC ON) # rcc when necessary.

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
