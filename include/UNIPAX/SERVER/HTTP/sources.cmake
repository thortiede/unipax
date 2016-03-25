### list all filenames of the directory here ###
SET(GROUP "SERVER/HTTP")

SET(DIRECTORY "${CMAKE_SOURCE_DIR}/include/UNIPAX/${GROUP}")

FILE(GLOB HEADERS_LIST "${DIRECTORY}/*.h")

FILE(GLOB MOCS "${DIRECTORY}/*.h")

LIST(APPEND MOC_HEADERS_LIST ${MOCS})

ADD_UNIPAX_HEADERS("${GROUP}" "${HEADERS_LIST}")
