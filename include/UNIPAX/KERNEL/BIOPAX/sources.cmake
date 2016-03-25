### list all filenames of the directory here ###
SET(GROUP "KERNEL/BIOPAX")

SET(DIRECTORY "${CMAKE_SOURCE_DIR}/include/UNIPAX/KERNEL${GROUP}")

FILE(GLOB HEADERS_LIST "${DIRECTORY}/*.h")	

ADD_UNIPAX_HEADERS("${GROUP}" "${HEADERS_LIST}")
