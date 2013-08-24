SET(SDL2_SEARCH_PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw # Fink
	/opt/local # DarwinPorts
	/opt/csw # Blastwave
	/opt
)

FIND_PATH(SDL2_INCLUDE_DIR SDL_ttf.h
	HINTS
	$ENV{SDL2DIR}
	PATH_SUFFIXES include/SDL2 include
	PATHS ${SDL2_SEARCH_PATHS}
)

FIND_LIBRARY(SDL2TTF_LIBRARY
	NAMES SDL2_ttf
	HINTS
	$ENV{SDL2DIR}
	PATH_SUFFIXES lib64 lib
	PATHS ${SDL2_SEARCH_PATHS}
	DOC "SDL2 ttf Library Path"
)

INCLUDE(FindPackageHandleStandardArgs)

#message(${SDL2IMAGE_LIBRARY})

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_ttf REQUIRED_VARS SDL2TTF_LIBRARY SDL2_INCLUDE_DIR) 

SET(SDL2IMAGE_FOUND "NO")
IF(SDL2TTF_LIBRARY AND SDL2_INCLUDE_DIR)
	SET(SDL2TTF_FOUND "YES")
ENDIF(SDL2TTF_LIBRARY AND SDL2_INCLUDE_DIR)
