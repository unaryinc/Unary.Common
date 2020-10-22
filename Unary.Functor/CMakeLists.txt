cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(Functor DESCRIPTION "Functor" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(FUNCTOR_VERSION 0.0.1)
#=======================================================================#
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_STATIC OFF CACHE BOOL "" FORCE)

set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)

add_definitions(-DWIN32_LEAN_AND_MEAN)
#=======================================================================#
if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	set(CompilerFlags
			CMAKE_CXX_FLAGS
			CMAKE_CXX_FLAGS_DEBUG
			CMAKE_CXX_FLAGS_RELEASE
			CMAKE_C_FLAGS
			CMAKE_C_FLAGS_DEBUG
			CMAKE_C_FLAGS_RELEASE
			)
	foreach(CompilerFlag ${CompilerFlags})
	  string(REPLACE "/W3" "/W0" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
	foreach(CompilerFlag ${CompilerFlags})
	  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
	set(EXECUTABLE ".exe")
	set(RUNTIME ".dll")
	set(LIBRARY ".lib")
	set(OS "Windows")
endif()
#=======================================================================#
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
#=======================================================================#
find_package(Git)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-list --max-count=1 HEAD
        OUTPUT_VARIABLE APP_REVISION
        ERROR_QUIET
        )
    if(NOT ${APP_REVISION} STREQUAL "")
        string(STRIP ${APP_REVISION} APP_REVISION)
    endif()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} status -s
        OUTPUT_VARIABLE GIT_CHANGES
        ERROR_QUIET
        )
    if(NOT ${GIT_CHANGES} STREQUAL "")
        string(APPEND APP_REVISION "-uncommited")
    endif()
else()
    set(APP_REVISION "Unknown")
endif()
message(STATUS "APP_REVISION is ${APP_REVISION}")
#=======================================================================#
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(APP_COMPILER "Clang ${CMAKE_CXX_COMPILER_VERSION} CXX${CMAKE_CXX_STANDARD}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(APP_COMPILER "GNU ${CMAKE_CXX_COMPILER_VERSION} CXX${CMAKE_CXX_STANDARD}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
	set(APP_COMPILER "Intel ${CMAKE_CXX_COMPILER_VERSION} CXX${CMAKE_CXX_STANDARD}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(APP_COMPILER "MSVC ${CMAKE_CXX_COMPILER_VERSION} CXX${CMAKE_CXX_STANDARD}")
else()
	set(APP_COMPILER "Unknown")
endif()

message(STATUS "APP_COMPILER is ${APP_COMPILER}")
#=======================================================================#
message(STATUS "FUNCTOR_VERSION is ${FUNCTOR_VERSION}")
#=======================================================================#
#infoware
set(INFOWARE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/infoware)
add_subdirectory(${INFOWARE_DIR})
#RapidJSON
set(RAPIDJSON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/rapidjson)
#Steam
set(STEAM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/Steam)
#Ultralight
set(ULTRALIGHT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/Ultralight)
#=======================================================================#
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
	set(ARCHITECTURE "x64")
else()
	set(ARCHITECTURE "x32")
endif()
#=======================================================================#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_VER "Debug")
	add_definitions(-DFUNCTOR_DEBUG)
else()
	set(BUILD_VER "Release")
endif()
#=======================================================================#
#infoware
include_directories(${INFOWARE_DIR}/include)
#RapidJSON
include_directories(${RAPIDJSON_DIR}/include)
#Steam
include_directories(${STEAM_DIR}/public)
#Ultralight
include_directories(${ULTRALIGHT_DIR}/include)
#=======================================================================#
include_directories(Functor/Include)

file(GLOB_RECURSE SOURCES Functor/*.cpp)
file(GLOB_RECURSE HEADERS Functor/*.hpp)
#=======================================================================#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")

	include_directories(Tests)

	file(GLOB_RECURSE SOURCES_TESTS Tests/*.cpp)
	file(GLOB_RECURSE HEADERS_TESTS Tests/*.hpp)

	list (APPEND SOURCES ${SOURCES_TESTS})
	list (APPEND HEADERS ${HEADERS_TESTS})

endif()
#=======================================================================#
add_executable(Functor ${SOURCES} ${HEADERS})
#=======================================================================#
if (MSVC)
	target_compile_options(Functor PRIVATE /GR-)
elseif(NOT APPLE)
	target_compile_options(Functor PRIVATE -fno-rtti)
endif()
#=======================================================================#
#infoware
target_link_libraries(Functor infoware)
#Steam
target_link_libraries(Functor ${STEAM_DIR}/redistributable_bin/${OS}/steam_api64${LIBRARY})
#Ultralight
target_link_libraries(Functor ${ULTRALIGHT_DIR}/lib/AppCore${LIBRARY} ${ULTRALIGHT_DIR}/lib/Ultralight${LIBRARY} ${ULTRALIGHT_DIR}/lib/UltralightCore${LIBRARY} ${ULTRALIGHT_DIR}/lib/WebCore${LIBRARY})
#=======================================================================#
add_custom_command(TARGET Functor POST_BUILD
	#Remove output dir
	COMMAND ${CMAKE_COMMAND} 
	-E remove_directory 
	"${OUTPUT_DIR}/Data"
	#Copy engine data
	COMMAND ${CMAKE_COMMAND} 
	-E copy_directory 
	"${ROOT_DIR}/Data" 
	"${OUTPUT_DIR}/Data"
	#Copy Steam
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ROOT_DIR}/Thirdparty/Steam/redistributable_bin/${OS}/steam_api64${RUNTIME}" 
	"${OUTPUT_DIR}/steam_api64${RUNTIME}"
	#Copy AppID
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ROOT_DIR}/Thirdparty/Steam/steam_appid.txt" 
	"${OUTPUT_DIR}/steam_appid.txt"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/AppCore${RUNTIME}" 
	"${OUTPUT_DIR}/AppCore${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/Ultralight${RUNTIME}" 
	"${OUTPUT_DIR}/Ultralight${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/UltralightCore${RUNTIME}" 
	"${OUTPUT_DIR}/UltralightCore${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/WebCore${RUNTIME}" 
	"${OUTPUT_DIR}/WebCore${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/icudt63${RUNTIME}" 
	"${OUTPUT_DIR}/icudt63${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/icuin63${RUNTIME}" 
	"${OUTPUT_DIR}/icuin63${RUNTIME}"
	COMMAND ${CMAKE_COMMAND} 
	-E copy
	"${ULTRALIGHT_DIR}/bin/icuuc63${RUNTIME}" 
	"${OUTPUT_DIR}/icuuc63${RUNTIME}"
)