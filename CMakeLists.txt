cmake_minimum_required(VERSION 3.10.0)

project(L-LIDE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(OBJDIR ${CMAKE_CURRENT_BINARY_DIR}/obj)
file(MAKE_DIRECTORY ${OBJDIR})

add_executable(${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX} ${SOURCES})
target_link_libraries(${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX} ${GTKMM_LIBRARIES})

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove ${OBJDIR}/*.o
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}
    COMMENT "Cleaning build artifacts"
)

message(${GTKMM_INCLUDE_DIRS})
