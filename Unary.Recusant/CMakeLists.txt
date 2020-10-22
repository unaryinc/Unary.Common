cmake_minimum_required(VERSION 3.9)
#=======================================================================#
project(Unary.Recusant DESCRIPTION "Recusant" LANGUAGES CXX)
#=======================================================================#
set(CMAKE_CXX_STANDARD 17)
#=======================================================================#
#EASTL
include_directories(${EASTL_DIR}/test/packages/EAStdC/include)
include_directories(${EASTL_DIR}/test/packages/EABase/include/Common)
include_directories(${EASTL_DIR}/include)
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
include_directories(${ROOT_DIR}/Unary.Shear/Include)
include_directories(${STEAM_DIR}/public)

include_directories(Include)
include_directories(Source)

file(GLOB_RECURSE SOURCES Source/*.cpp)
file(GLOB_RECURSE HEADERS Include/*.hpp)
#=======================================================================#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")

	include_directories(Tests)

	file(GLOB_RECURSE SOURCES_TESTS Tests/*.cpp)
	file(GLOB_RECURSE HEADERS_TESTS Tests/*.hpp)

	list (APPEND SOURCES ${SOURCES_TESTS})
	list (APPEND HEADERS ${HEADERS_TESTS})

endif()
#=======================================================================#
if (MSVC)
	add_executable(Unary.Recusant ${SOURCES} ${HEADERS})
else()
	add_executable(Unary.Recusant SHARED ${SOURCES} ${HEADERS})
endif()
#=======================================================================#
if (MSVC)
	target_compile_options(Unary.Recusant PRIVATE /GR-)
elseif(NOT APPLE)
	target_compile_options(Unary.Recusant PRIVATE -fno-rtti)
endif()
#=======================================================================#
target_link_libraries(Unary.Recusant Unary.Shear)
target_link_libraries(Unary.Recusant ${STEAM_DIR}/redistributable_bin/${OS}/steam_api64${LIBRARY})
#=======================================================================#
add_custom_command(TARGET Unary.Recusant POST_BUILD
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
)