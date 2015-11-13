set(NAME mnet)

add_executable(
  ${NAME}

  main.cc

  TrayIcon.h
  TrayIcon.cc
  )

qt5_use_modules(
  ${NAME}
  Core
  Gui
  Widgets
  )
