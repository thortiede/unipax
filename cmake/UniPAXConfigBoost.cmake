SET(UNIPAX_BOOST_COMPONENTS system graph math_tr1 regex program_options date_time filesystem serialization)
IF ( WIN32 )
  LIST(APPEND UNIPAX_BOOST_COMPONENTS zlib bzip2)
	ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)
	ADD_DEFINITIONS(-DBOOST_THREAD_USE_DLL)
ENDIF()

SET(Boost_ADDITIONAL_VERSIONS "1.39" "1.39.0" "1.40" "1.40.0" "1.41" "1.41.0"
	"1.42" "1.42.0" "1.43" "1.43.0" "1.44.0" "1.45" "1.45.0" "1.46.1" "1.49.0" "1.55.0")
SET(Boost_DETAILED_FAILURE_MSG ON)

FIND_PACKAGE(Boost REQUIRED COMPONENTS ${UNIPAX_BOOST_COMPONENTS})

IF (NOT Boost_VERSION) ## we cannot test for Boost_FOUND since this requires all components
	MESSAGE(SEND_ERROR "Could not find a suitable boost installation! This is a required dependency for UniPAX! Try setting BOOST_ROOT in ccmake!")
ELSE()
	SET(BOOST_LIBRARIES "")
	FOREACH(COMPONENT ${UNIPAX_BOOST_COMPONENTS})
		STRING(TOUPPER ${COMPONENT} COMPONENT)
		
		IF (Boost_${COMPONENT}_FOUND)
			SET(UNIPAX_HAS_BOOST_${COMPONENT} TRUE)
			LIST(APPEND BOOST_LIBRARIES ${Boost_${COMPONENT}_LIBRARY})
		ENDIF()
	ENDFOREACH()
ENDIF()
