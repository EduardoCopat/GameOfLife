cmake_minimum_required(VERSION 2.6)
project(game_project)

# For some external project macros
include(ExternalProject)

##########
# Main
###############
add_executable(game main.cpp cell.cpp cell.h game_matrix.cpp game_matrix.h)
target_link_libraries(game Boost::boost)




##############
# SDL
# https://ccavusoglu.github.io/posts/Setting-up-SDL2-and-SDL_gpu-on-Windows-using-CMake/
#################
set(SDL2_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2-2.0.9/include)
set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2-2.0.9)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Find the SDL2 library
find_package(SDL2 REQUIRED)

# SDL2_INCLUDE_DIR variable set by the FindSDL2 module (if it finds directory).
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_GPU_INCLUDE_PATH})


target_link_libraries(game ${SDL2_LIBRARY})

################################
# GTest
################################
ADD_SUBDIRECTORY (lib/googletest-release-1.8.1)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( runUnitTests test_game_of_life.cpp cell.cpp cell.h test_cell_matrix.cpp game_matrix.cpp game_matrix.h )
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main Boost::boost)
add_test( runUnitTests runUnitTests )

add_subdirectory(lib/boost-cmake-master)





