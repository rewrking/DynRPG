cmake_minimum_required(VERSION 3.10)

project(DynRPG VERSION 0.33)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer -Wall -Wno-unused-variable -static-libgcc -static-libstdc++ -s ${CMAKE_CXX_FLAGS}")

if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 11)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_NAME DynRPG)

file(GLOB_RECURSE SOURCES
	src/*.cpp
)

add_library(${TARGET_NAME} SHARED ${SOURCES})
target_precompile_headers(${TARGET_NAME} PRIVATE src/PCH.hpp)

set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
set_target_properties(${TARGET_NAME} PROPERTIES IMPORT_SUFFIX ".a")
set_target_properties(${TARGET_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY
		${CMAKE_SOURCE_DIR}/lib
)

target_include_directories(${TARGET_NAME}
	PRIVATE
		src/
		include
)