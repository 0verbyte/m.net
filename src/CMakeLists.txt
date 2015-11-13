set(NAME mnet)

add_executable(
  ${NAME}
  main.cc
  )

qt5_use_modules(
  ${NAME}
  Core
  )
