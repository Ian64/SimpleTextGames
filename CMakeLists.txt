cmake_minimum_required(VERSION 3.2)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg

project(SimpleTextGames)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-g -O0 --coverage")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SRC_LIST
    src/GameField.hpp
    src/Input.hpp
    src/Input.cpp
    src/GameObjects.hpp
    src/GameObjects.cpp
    src/GameBoard.hpp
    src/GameBoard.cpp
    src/BattleShip.hpp
    src/BattleShip.cpp
    src/OX.hpp
    src/OX.cpp
    src/Pong.hpp
    src/Pong.cpp
    src/Snake.hpp
    src/Snake.cpp
    )

include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_compile_options(-Wall -Wextra -Werror -Wpedantic)
add_executable(${PROJECT_NAME} src/main.cpp)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)
else (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
endif (UNIX)

set(TEST_SRC_LIST
    test/test_main.cpp
    test/TestBattleShip.cpp
    test/TestOX.cpp
    test/TestGameObjects.cpp
)

link_libraries(gtest)
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
