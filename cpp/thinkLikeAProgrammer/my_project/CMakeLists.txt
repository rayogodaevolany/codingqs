cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


    # # Force macOS SDK path (via xcrun) and libc++ standard library
    # execute_process(
    #   COMMAND xcrun --show-sdk-path
    #   OUTPUT_VARIABLE MACOS_SDK_PATH
    #   OUTPUT_STRIP_TRAILING_WHITESPACE
    # )
    # set(CMAKE_OSX_SYSROOT ${MACOS_SDK_PATH})

    # # Use libc++ explicitly (modern macOS std lib)
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
include_directories(${PROJECT_SOURCE_DIR}/include)


# ---- Libraries ----
add_library(customString src/customString.cpp)
add_library(recordCollection src/recordCollection.cpp)

# ---- Executables ----
add_executable(test_customString tests/test_customString.cpp)
add_executable(test_recordCollection tests/test_recordCollection.cpp)

# ---- Link libraries ----
target_link_libraries(test_customString
  customString
  GTest::gtest_main
)
target_link_libraries(test_recordCollection
  recordCollection
  GTest::gmock
  GTest::gtest_main
  )


# CTest can discover and run tests
include(GoogleTest)
gtest_discover_tests(test_customString)
gtest_discover_tests(test_recordCollection)
