PROJECT(TFEncyclopediaImporter)

SET(SOURCES
	main.cpp
)


IF (database STREQUAL "oracle")	
	INCLUDE_DIRECTORIES(
		${Boost_INCLUDE_DIR}
		${ODB_INCLUDE_DIR}
		${ODBORACLE_INCLUDE_DIR}
	    ${ORACLE_INCLUDE_DIR}
		${SBML_INCLUDE_DIR}
	)
ENDIF (database STREQUAL "oracle")

IF (NOT (database STREQUAL "oracle"))
	INCLUDE_DIRECTORIES(
		${Boost_INCLUDE_DIR}
		${MYSQL_INCLUDE_DIR}
		${ODB_INCLUDE_DIR}
		${ODBMYSQL_INCLUDE_DIR}
		${SBML_INCLUDE_DIR}
	)
ENDIF (NOT (database STREQUAL "oracle"))


ADD_EXECUTABLE(TFEncyclopediaImporter ${SOURCES} ${HEADERS})
TARGET_LINK_LIBRARIES(TFEncyclopediaImporter UniPAX)
SET_TARGET_PROPERTIES(TFEncyclopediaImporter PROPERTIES COMPILE_FLAGS "${UNIPAX_COMPILE_FLAGS} ${UNIPAX_DATABASE_FLAGS}")
SET_TARGET_PROPERTIES(TFEncyclopediaImporter PROPERTIES LINK_FLAGS    "${UNIPAX_LINK_FLAGS}")
