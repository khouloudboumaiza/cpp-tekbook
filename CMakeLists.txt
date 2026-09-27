cmake_minimum_required(VERSION 3.20)
project(cpp_tekbook VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(tekbook_lib src/tekbook.cpp)
target_include_directories(tekbook_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tekbook_app src/main.cpp)
target_link_libraries(tekbook_app PRIVATE tekbook_lib)

include(CTest)
if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(run_tests tests/test_main.cpp)
    target_link_libraries(run_tests PRIVATE tekbook_lib Catch2::Catch2WithMain)

    include(Catch)
    catch_discover_tests(run_tests)
endif()
