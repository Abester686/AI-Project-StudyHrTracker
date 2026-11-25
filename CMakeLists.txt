
cmake_minimum_required(VERSION 3.14)

project(StudyHoursTracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(study_tracker src/StudyTracker.cpp)
target_include_directories(study_tracker PUBLIC include)

add_executable(study_app src/main.cpp)
target_link_libraries(study_app PRIVATE study_tracker)

enable_testing()

find_package(GTest REQUIRED)

add_executable(run_tests tests/test_study_tracker.cpp)
target_link_libraries(run_tests PRIVATE
    study_tracker
    GTest::gtest_main
)

add_test(NAME StudyTrackerTests COMMAND run_tests)
