# ==================================================================================================
# The MIT License (MIT)
#
# Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==================================================================================================

cmake_minimum_required(VERSION 3.2)

option(FAST_SDL2_CPP_INSTALL_LIBRARY "Whether to install the library or not"
       OFF)

project(
  FAST_SDL2_CPP
  VERSION 1.0.0
  DESCRIPTION "Fast interpolation with SDL2 for C++"
  HOMEPAGE_URL "https://github.com/vitimiti/fast_sdl2cpp"
  LANGUAGES C CXX)

add_subdirectory(vendor)

if(SDL2_NOT_FOUND)
  find_package(SDL2 REQUIRED)
endif()

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>
            ${PREPROC_CONFIG_SOURCE_DIR}/include
            ${ADVANCED_TYPES_SOURCE_DIR}/include
            ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} INTERFACE ${SDL2_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} INTERFACE <cstdint> <optional>
                          <string_view> <variant>)

include(GNUInstallDirs)
if(FAST_SDL2_CPP_INSTALL_LIBRARY)
  message(TRACE
          "Configuring installation system with prefix ${CMAKE_INSTALL_PREFIX}")

  install(
    TARGETS FAST_SDL2_CPP
    EXPORT FAST_SDL2_CPP_TARGETS
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
    "fast_sdl2cpp-config-version.cmake"
    VERSION ${FAST_SDL2_CPP_VERSION}
    COMPATIBILITY SameMajorVersion)

  configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/fast_sdl2cpp-config.cmake.in"
    "${PROJECT_BINARY_DIR}/fast_sdl2cpp-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fast_sdl2cpp)

  install(
    EXPORT FAST_SDL2_CPP_TARGETS
    FILE fast_sdl2cpp-targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fast_sdl2cpp)

  install(FILES "${PROJECT_BINARY_DIR}/fast_sdl2cpp-config.cmake"
                "${PROJECT_BINARY_DIR}/fast_sdl2cpp-config-version.cmake"
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fast_sdl2cpp)

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/fast_sdl2cpp
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()
