cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(Unary.Shear DESCRIPTION "Unary.Shear engine" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#=======================================================================#
#EASTL
include_directories(${EASTL_DIR}/test/packages/EAStdC/include)
include_directories(${EASTL_DIR}/test/packages/EABase/include/Common)
include_directories(${EASTL_DIR}/include)
add_custom_target(NatVis SOURCES ${EASTL_DIR}/doc/EASTL.natvis)
#asio
include_directories(${ASIO_DIR}/include)
#infoware
include_directories(${INFOWARE_DIR}/include)
#RapidJSON
include_directories(${RAPIDJSON_DIR}/include)
#soloud
include_directories(${SOLOUD_DIR}/include)
#imgui
include_directories(${IMGUI_DIR}/include)
#glm
include_directories(${GLM_DIR}/include)
#glfw
include_directories(${GLAD_DIR}/include)
include_directories(${GLFW_DIR}/include)
#Steam
include_directories(${STEAM_DIR}/public)
#=======================================================================#
include_directories(Include)

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Source/*.hpp)
#=======================================================================#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")

	include_directories(Tests)

	file(GLOB_RECURSE SOURCES_TESTS Tests/*.cpp)
	file(GLOB_RECURSE HEADERS_TESTS Tests/*.hpp)

	list (APPEND SOURCES ${SOURCES_TESTS})
	list (APPEND HEADERS ${HEADERS_TESTS})

endif()
#=======================================================================#
add_library(Unary.Shear STATIC ${SOURCES} ${HEADERS})
#=======================================================================#
if (MSVC)
	target_compile_options(Unary.Shear PRIVATE /GR-)
elseif(NOT APPLE)
	target_compile_options(Unary.Shear PRIVATE -fno-rtti)
endif()
#=======================================================================#
#EASTL
target_link_libraries(Unary.Shear EAStdC)
target_link_libraries(Unary.Shear EASTL)
#infoware
target_link_libraries(Unary.Shear infoware)
#soloud
target_link_libraries(Unary.Shear soloud)
#glfw
if(MSVC)
	target_link_libraries(Unary.Shear opengl32 gdi32 version Ole32 OleAut32 wbemuuid)
elseif()
	target_link_libraries(Unary.Shear libGL)
endif()
target_link_libraries(Unary.Shear imgui)
target_link_libraries(Unary.Shear glad)
target_link_libraries(Unary.Shear glfw)
target_link_libraries(Unary.Shear ${STEAM_DIR}/redistributable_bin/${OS}/steam_api64${LIBRARY})
#=======================================================================#