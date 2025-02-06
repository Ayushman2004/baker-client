# CommonLibs.cmake

set(LIBRARY_INCLUDE_DIR "C:\baker-client\header")
set(LIBRARY_LIB_DIR "C:\baker-client\src")
set(LIBRARY_BIN_DIR "C:\baker-client\bin")

include_directories(${LIBRARY_INCLUDE_DIR})
link_directories(${LIBRARY_LIB_DIR})
set(CMAKE_PREFIX_PATH ${LIBRARY_BIN_DIR})

list(APPEND CMAKE_PROGRAM_PATH ${LIBRARY_BIN_DIR})
list(APPEND CMAKE_LIBRARY_PATH ${LIBRARY_LIB_DIR})
list(APPEND CMAKE_INCLUDE_PATH ${LIBRARY_INCLUDE_DIR})
