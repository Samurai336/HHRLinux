#################################################################
cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
#set (CMAKE_VERBOSE_MAKEFILE ON)

set (App_Name "HHR_X")
if(App_Name STREQUAL "")
	message(FATAL_ERROR "You Must set the App_Name varable")
endif()

project (${App_Name})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


##################################################################

set (Build_Dir_OK "TRUE")
string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Sub_Dir ${CMAKE_BINARY_DIR})
if (In_Sub_Dir)
  string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Build_Dir ${CMAKE_BINARY_DIR})
  if (NOT In_Build_Dir)
    set (Build_Dir_OK "FALSE")
  endif ()
endif ()

if (NOT Build_Dir_OK)
  message (FATAL_ERROR "You must run cmake from a directory that is not in your source tree, or that is in a special subdirectory of the tree whose name begins with ‘build’.")
endif ()





###########################################################################
if (CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

#############################################################################



if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    message("Debug ON")
    set(DEBUG_MODE ON)
    set(CMAKE_VERBOSE_MAKEFILE ON)
    set(PHYSICS_DEBUG OFF CACHE BOOL "Show Physics Debug information") # Configurable by user
endif()


configure_file ( HHR_Config.h.in  src/HHR_Config.h )



###############################################################################

file(GLOB game_files src/*.c src/*.cpp src/*.h src/*.hpp)

file(GLOB renderer_files src/Renderer/*.h src/Renderer/*.cpp)

file(GLOB baseClasses_files src/BaseClasses/*.h src/BaseClasses/*.cpp)

file(GLOB physics_files src/Physics/*.h src/Physics/*.cpp)

file(GLOB particle_files src/Particles/*.h src/Particles/*.cpp)

file(GLOB audio_files src/Audio/*.h src/Audio/*.cpp)

file(GLOB_RECURSE game_classes src/GameClasses/*.cpp src/GameClasses/*.h)



SOURCE_GROUP(Renderer FILES ${renderer_files})

SOURCE_GROUP(Game FILES ${game_files})

SOURCE_GROUP(BaseClasses FILES ${baseClasses_files})

SOURCE_GROUP(Physics FILES ${physics_files})

SOURCE_GROUP(Particles FILES ${particle_files})

SOURCE_GROUP(Audio FILES ${audio_files})

SOURCE_GROUP(GameClasses FILES ${game_classes})



link_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/src
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)


if(WIN32)
	add_executable(${App_Name} WIN32
        ${game_files}
        ${baseClasses_files}
        ${renderer_files}
        ${physics_files}
        ${particle_files}
        ${audio_files}
        ${game_classes}
	)

        if(CMAKE_BUILD_TYPE MATCHES DEBUG)
            SET_TARGET_PROPERTIES(${App_Name} PROPERTIES COMPILE_FLAGS "/Od /ZI")
            SET_TARGET_PROPERTIES(${App_Name} PROPERTIES LINK_FLAGS "/DEBUG")
        endif()

else ()
	add_executable (${App_Name}
        ${game_files}
        ${baseClasses_files}
        ${renderer_files}
        ${physics_files}
        ${particle_files}
        ${audio_files}
        ${game_classes}
	)

        set(CMAKE_CXX_FLAGS "-g -Wno-write-strings")



endif ()

target_link_libraries(${App_Name}
)

#################################################################3


option(Option_SDL_Dev "" ON)

if (Option_SDL_Dev)
	find_package(SDL2)
	if (NOT SDL2_FOUND)
		message (FATAL_ERROR "SDL not found!")
	endif (NOT SDL2_FOUND)

	find_package(SDL2_image)
	if (NOT SDL2IMAGE_FOUND)
		message (FATAL_ERROR "SDL_Image not found!")
	endif (NOT SDL2IMAGE_FOUND)

	find_package(SDL2_ttf)
	if (NOT SDL2TTF_FOUND)
		message (FATAL_ERROR "SDL_ttf not found!")
	endif (NOT SDL2TTF_FOUND)

        find_package(SDL2_mixer)
        if (NOT SDL2MIXER_FOUND)
                message (FATAL_ERROR "SDL_mixer not found!")
        endif (NOT SDL2MIXER_FOUND)


	include_directories(
		${SDL2_INCLUDE_DIR}
		${INCLUDE_DIRECTORIES}
		)
	target_link_libraries(${App_Name}
		${SDL2_LIBRARY}
		${SDL2MAIN_LIBRARY}
		${SDL2IMAGE_LIBRARY}
		${SDL2TTF_LIBRARY}
                ${SDL2MIXER_LIBRARY}
		${TARGET_LINK_LIBRARIES}
		)

endif(Option_SDL_Dev)

#message("${CMAKE_SOURCE_DIR}/Assets")
#message("${CMAKE_BINARY_DIR}")

file(COPY "${CMAKE_SOURCE_DIR}/Assets" DESTINATION "${CMAKE_BINARY_DIR}")




