SET(SOURCES_LIST
	test_GraphMappingServerHandler.cpp
)

UNIPAX_ADD_TESTS("PLUGINS/REST/GRAPHMAPPINGSERVERHANDLER" ${SOURCES_LIST})

# for searching needed MOCKS subdirectories:
INCLUDE_DIRECTORIES("UNIPAX/COMMON/MOCKS")
