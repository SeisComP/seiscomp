IF(WIN32)
	SET(TYPE STATIC)
ELSE(WIN32)
	SET(TYPE SHARED)
ENDIF(WIN32)

ADD_LIBRARY(mseed ${TYPE}
	crc32c.c
	extraheaders.c
	fileutils.c
	genutils.c
	gmtime64.c
	logging.c
	lookup.c
	msio.c
	msrutils.c
	pack.c
	packdata.c
	parseutils.c
	selection.c
	tracelist.c
	unpack.c
	unpackdata.c
	yyjson.c
)

SET_TARGET_PROPERTIES(mseed PROPERTIES VERSION 3.1.9)

IF(NOT WIN32)
	INSTALL(TARGETS mseed DESTINATION ${SC3_PACKAGE_LIB_DIR})
ENDIF(NOT WIN32)
