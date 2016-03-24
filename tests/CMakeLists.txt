set(TEST_DIR "${BIN_DIR}/tests")

file(MAKE_DIRECTORY ${TEST_DIR})

include_directories(
  gtest
  gtest/include
)

add_library(
  gtest
  gtest/src/gtest-all.cc
)

macro(add_mnet_test name)
  add_executable(
    ${name}
    ${ARGV}
    )
  add_test(
    NAME ${name}
    COMMAND ${name}
    )
  target_link_libraries(
    ${name}
    gtest
    )
  include_directories(
    gtest/include
    ..
    )
endmacro(add_mnet_test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TEST_DIR})

add_mnet_test(Test test.cc)
