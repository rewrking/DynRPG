cmake_minimum_required(VERSION 3.10)

project(DynRPG VERSION 0.32)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
	src/*.cpp
)

add_library(DynRPG STATIC ${SOURCES})
set_target_properties(DynRPG PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY
		${CMAKE_SOURCE_DIR}/lib
)

target_include_directories(DynRPG
	PRIVATE
		src/
		include/DynRPG
)