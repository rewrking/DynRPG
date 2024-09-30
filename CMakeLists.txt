cmake_minimum_required(VERSION 3.10)

project(DynRPG VERSION 0.33)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer -Wall -Wno-unused-variable -static-libgcc -static-libstdc++ -s ${CMAKE_CXX_FLAGS}")

if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 98)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED DYNRPG_SHARED)
	set(DYNRPG_SHARED OFF)
endif()
message(STATUS "DYNRPG_SHARED: ${DYNRPG_SHARED}")

if (NOT DEFINED DYNRPG_BUILD_DOCS)
	set(DYNRPG_BUILD_DOCS ON)
endif()
message(STATUS "DYNRPG_BUILD_DOCS: ${DYNRPG_BUILD_DOCS}")

if (NOT DEFINED DYNRPG_LIB_DIR)
	set(DYNRPG_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
endif()
message(STATUS "DYNRPG_LIB_DIR: ${DYNRPG_LIB_DIR}")

set(TARGET_NAME DynRPG)

file(GLOB_RECURSE SOURCES
	src/*.cpp
)

if (DYNRPG_SHARED)
	add_library(${TARGET_NAME} SHARED ${SOURCES})
	set_target_properties(${TARGET_NAME} PROPERTIES PREFIX "")
	set_target_properties(${TARGET_NAME} PROPERTIES IMPORT_SUFFIX ".a")
	set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "DYNRPG_SHARED")
else()
	add_library(${TARGET_NAME} STATIC ${SOURCES})
endif()

target_precompile_headers(${TARGET_NAME} PRIVATE
	src/PCH.hpp
)
set_target_properties(${TARGET_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY
		${DYNRPG_LIB_DIR}
)
target_include_directories(${TARGET_NAME}
	PRIVATE
		src/
		include
)

if(DYNRPG_BUILD_DOCS)
	find_package(Doxygen COMPONENTS doxygen)

	if(DOXYGEN_EXECUTABLE)
		set(DOXYGEN_GENERATE_HTML ON)
		add_custom_target(docs ALL BYPRODUCTS
			COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile.cfg
			WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
			COMMENT "Generating API documentation with Doxygen"
		)
	else()
		message(FATAL_ERROR "doxygen not found")
	endif()
endif()
