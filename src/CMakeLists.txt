set(NAME mnet)

set(MAC_SRC "")
if (APPLE)
  set(MAC_SRC "MacNotification.mm")
endif()

add_executable(
  ${NAME}

  main.cc

  TrayIcon.h
  TrayIcon.cc

  Network.h
  Network.cc

  ${MAC_SRC}
  )

qt5_use_modules(
  ${NAME}
  Core
  Gui
  Widgets
  Network
  MacExtras
  )

if (APPLE)
  find_library(
    FOUNDATION
    Foundation
    )
  mark_as_advanced(FOUNDATION)
  target_link_libraries(
    ${NAME}
    ${FOUNDATION}
    )
endif()
