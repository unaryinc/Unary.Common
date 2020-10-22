cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(Unary.App DESCRIPTION "Unary.App" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(APP_VERSION 0.0.1)
set(SHEAR_VERSION 0.0.1)
set(CORE_VERSION 0.0.1)
#=======================================================================#
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_STATIC OFF CACHE BOOL "" FORCE)

set(EASTL_BUILD_TESTS ON CACHE BOOL "" FORCE)

set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)

set(SOLOUD_BACKEND_NULL ON CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_SDL2 OFF CACHE BOOL "" FORCE)
if (MSVC)
	set(SOLOUD_BACKEND_WINMM ON CACHE BOOL "" FORCE)
	set(INFOWARE_USE_D3D ON CACHE BOOL "" FORCE)
elseif(APPLE)
	set(SOLOUD_BACKEND_COREAUDIO ON CACHE BOOL "" FORCE)
endif()

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

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
set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/Unary.Recusant")
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
message(STATUS "APP_VERSION is ${APP_VERSION}")
#=======================================================================#
#EASTL
set(EASTL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/EASTL)
add_subdirectory(${EASTL_DIR})
#asio
set(ASIO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/asio)
#infoware
set(INFOWARE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/infoware)
add_subdirectory(${INFOWARE_DIR})
#RapidJSON
set(RAPIDJSON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/rapidjson)
#soloud
set(SOLOUD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/soloud)
add_subdirectory(${SOLOUD_DIR}/contrib)
#imgui
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/imgui)
add_subdirectory(${IMGUI_DIR})
#glm
set(GLM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glm)
#glad
set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glad)
add_subdirectory(${GLAD_DIR})
#glfw
set(GLFW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/glfw)
add_subdirectory(${GLFW_DIR})
#Steam
set(STEAM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/Steam)
#=======================================================================#
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
	set(ARCHITECTURE "x64")
else()
	set(ARCHITECTURE "x32")
endif()
#=======================================================================#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_VER "Debug")
	add_definitions(-DSHEAR_DEBUG)
else()
	set(BUILD_VER "Release")
endif()
#=======================================================================#
add_subdirectory(Unary.Shear)
add_subdirectory(Unary.Recusant)
#=======================================================================#