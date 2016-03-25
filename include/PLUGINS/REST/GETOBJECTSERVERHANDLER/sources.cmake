### list all filenames of the directory here ###
SET(GROUP REST/GETOBJECTSERVERHANDLER)

SET(DIRECTORY "${CMAKE_SOURCE_DIR}/include/PLUGINS/${GROUP}")

FILE(GLOB HEADERS_LIST "${DIRECTORY}/*.h")	

FILE(GLOB MOCS "${DIRECTORY}/*.h")

LIST(APPEND GetObjectServerHandler_MOC_HEADERS_LIST ${MOCS})
