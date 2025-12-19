cmake_minimum_required(VERSION 3.20)
project(ConsoleArtLib LANGUAGES C CXX)

#
# C++ version
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Warnings
#
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	add_compile_options(-Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options(/W4)
endif()

#
# Other settings
#
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_definitions(NOMINMAX)
endif()

#
# Optimization
#
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
	set(CMAKE_C_FLAGS_RELEASE "-O3")
	#
	set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DDEBUG")
	set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS_RELEASE "/O2")
	set(CMAKE_C_FLAGS_RELEASE "/O2")
	#
	set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /DDEBUG")
	set(CMAKE_C_FLAGS_DEBUG "/Od /Zi /DDEBUG")
endif()

#
# PREBUILT STATIC LIBRARIES
#
set(GENERAL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

set(CONSOLE_LIB_DIR ${GENERAL_LIB_DIR}/ConsoleLib)

# Create an IMPORTED target for the .a file
add_library(ConsoleLib STATIC IMPORTED)

# Point the IMPORTED target to the actual file
if (WIN32)
	set_target_properties(ConsoleLib PROPERTIES
	IMPORTED_LOCATION ${CONSOLE_LIB_DIR}/ConsoleLib.lib
	INTERFACE_INCLUDE_DIRECTORIES ${CONSOLE_LIB_DIR}/inc)
else()
	set_target_properties(ConsoleLib PROPERTIES
	IMPORTED_LOCATION ${CONSOLE_LIB_DIR}/libConsoleLib.a
	INTERFACE_INCLUDE_DIRECTORIES ${CONSOLE_LIB_DIR}/inc)
endif()

#
# Library itself
#
file(MAKE_DIRECTORY build)

file(GLOB_RECURSE APP_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(ConsoleArtLib STATIC ${APP_SOURCES})

target_link_libraries(ConsoleArtLib PRIVATE ConsoleLib)

