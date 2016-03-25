### list all filenames of the directory here ###
SET(GROUP "PERSISTENCE/ORACLE/EXT")

SET(DIRECTORY "${CMAKE_SOURCE_DIR}/include/UNIPAX/${GROUP}")

FILE(GLOB HEADERS_LIST "${DIRECTORY}/*.hxx")	

ADD_UNIPAX_HEADERS("${GROUP}" "${HEADERS_LIST}")
