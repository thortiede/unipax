### list all filenames of the directory here ###
SET(GROUP PERSISTENCE/ORACLE)

SET(DIRECTORY "${CMAKE_SOURCE_DIR}/include/UNIPAX/${GROUP}")

FILE(GLOB HEADERS_LIST "${DIRECTORY}/*.h")	

FILE(GLOB MOCS "${DIRECTORY}/*.h")

LIST(APPEND MOC_HEADERS_LIST ${MOCS})

ADD_UNIPAX_HEADERS("${GROUP}" "${HEADERS_LIST}")

INCLUDE(${CMAKE_SOURCE_DIR}/include/UNIPAX/PERSISTENCE/ORACLE/BIOPAX/sources.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/include/UNIPAX/PERSISTENCE/ORACLE/EXT/sources.cmake)
