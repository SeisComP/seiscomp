MACRO (SC_BEGIN_PACKAGE ...)
	SET(SC3_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
	SET(SC3_PACKAGE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
	IF (${ARGC} GREATER 1)
		SET(SC3_PACKAGE_DIR ${ARGV1})
		SET(SC3_PACKAGE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${ARGV1})
		SET(SC3_PACKAGE_BIN_DIR ${ARGV1}/bin)
		SET(SC3_PACKAGE_SBIN_DIR ${ARGV1}/sbin)
		SET(SC3_PACKAGE_LIB_DIR ${ARGV1}/lib)
		SET(SC3_PACKAGE_PYTHON_LIB_DIR ${ARGV1}/${PYTHON_LIBRARY_PATH})
		SET(SC3_PACKAGE_INCLUDE_DIR ${ARGV1}/include)
		SET(SC3_PACKAGE_SHARE_DIR ${ARGV1}/share)
		SET(SC3_PACKAGE_INIT_DIR ${ARGV1}/etc/init)
		SET(SC3_PACKAGE_CONFIG_DIR ${ARGV1}/etc/defaults)
		SET(SC3_PACKAGE_APP_CONFIG_DIR ${ARGV1}/etc)
		SET(SC3_PACKAGE_APP_DESC_DIR ${ARGV1}/etc/descriptions)
		SET(SC3_PACKAGE_TEMPLATES_DIR ${ARGV1}/share/templates)
	ELSE (${ARGC} GREATER 1)
		SET(SC3_PACKAGE_DIR ".")
		SET(SC3_PACKAGE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
		SET(SC3_PACKAGE_BIN_DIR bin)
		SET(SC3_PACKAGE_SBIN_DIR sbin)
		SET(SC3_PACKAGE_LIB_DIR lib)
		SET(SC3_PACKAGE_PYTHON_LIB_DIR ${PYTHON_LIBRARY_PATH})
		SET(SC3_PACKAGE_INCLUDE_DIR include)
		SET(SC3_PACKAGE_SHARE_DIR share)
		SET(SC3_PACKAGE_INIT_DIR etc/init)
		SET(SC3_PACKAGE_CONFIG_DIR etc/defaults)
		SET(SC3_PACKAGE_APP_CONFIG_DIR etc)
		SET(SC3_PACKAGE_APP_DESC_DIR etc/descriptions)
		SET(SC3_PACKAGE_TEMPLATES_DIR share/templates)
	ENDIF (${ARGC} GREATER 1)
	MESSAGE(STATUS "Adding pkg ${ARGV0}")
	MESSAGE(STATUS "... resides in ${SC3_PACKAGE_SOURCE_DIR}.")
	MESSAGE(STATUS "... will be installed under ${SC3_PACKAGE_INSTALL_PREFIX}.")
ENDMACRO ()

MACRO (SC_ADD_CHANGELOG _app)
	SET(CL_DIR ${CMAKE_CURRENT_SOURCE_DIR})
	IF (${ARGC} GREATER 1)
		SET(CL_DIR ${ARGV1})
	ENDIF()

	IF(EXISTS "${CL_DIR}/CHANGELOG.md")
		INSTALL(FILES ${CL_DIR}/CHANGELOG.md DESTINATION ${SC3_PACKAGE_SHARE_DIR}/doc/${_app} RENAME CHANGELOG)
	ELSE(EXISTS "${CL_DIR}/CHANGELOG.md")
		IF(EXISTS "${CL_DIR}/CHANGELOG.rst")
			INSTALL(FILES ${CL_DIR}/CHANGELOG.rst DESTINATION ${SC3_PACKAGE_SHARE_DIR}/doc/${_app})
		ELSE(EXISTS "${CL_DIR}/CHANGELOG.rst")
			IF(EXISTS "${CL_DIR}/CHANGELOG")
				INSTALL(FILES ${CL_DIR}/CHANGELOG DESTINATION ${SC3_PACKAGE_SHARE_DIR}/doc/${_app})
			ENDIF(EXISTS "${CL_DIR}/CHANGELOG")
		ENDIF(EXISTS "${CL_DIR}/CHANGELOG.rst")
	ENDIF(EXISTS "${CL_DIR}/CHANGELOG.md")
ENDMACRO ()

MACRO (SC_ADD_VERSION _package _name)
	INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

	# Read build year from current source directory
	EXECUTE_PROCESS (
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND bash -c "echo -n `date -d @\\`git log -1 --pretty=format:%at -- .\\` +%Y`"
		OUTPUT_VARIABLE BUILD_YEAR
	)

	# Read build day from current source directory
	EXECUTE_PROCESS (
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND bash -c "echo -n `date -d @\\`git log -1 --pretty=format:%at -- .\\` +%j | sed 's/^0*//'`"
		OUTPUT_VARIABLE BUILD_DAY
	)

	# Read build day from current source directory
	EXECUTE_PROCESS (
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND bash -c "echo -n `date -d @\\`git log -1 --pretty=format:%at -- .\\` +%j`"
		OUTPUT_VARIABLE BUILD_DAY_STR
	)

	# Read build hash from current source directory
	EXECUTE_PROCESS (
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND bash -c "echo -n `git log -1 --pretty=format:%h -- .`"
		OUTPUT_VARIABLE BUILD_HASH
	)

	SET(${_name}_VERSION ${CMAKE_CURRENT_BINARY_DIR}/version.h)
	ADD_CUSTOM_TARGET(
		${_name}_version ALL
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND bash -c 'echo \"\#define ${_package}_VERSION ${BUILD_YEAR}.${BUILD_DAY_STR}\#${BUILD_HASH}\"' > ${${_name}_VERSION}.tmp
		COMMAND bash -c 'echo \"\#define ${_package}_BUILD_YEAR ${BUILD_YEAR}\"' >> ${${_name}_VERSION}.tmp
		COMMAND bash -c 'echo \"\#define ${_package}_BUILD_DAY ${BUILD_DAY}\"' >> ${${_name}_VERSION}.tmp
		COMMAND bash -c 'echo \"\#define STR_VALUE_0\(X\) \#X\"' >> ${${_name}_VERSION}.tmp
		COMMAND bash -c 'echo \"\#define STR_VALUE\(X\) STR_VALUE_0\(X\)\"' >> ${${_name}_VERSION}.tmp
		COMMAND bash -c 'echo \"\#define ${_package}_VERSION_NAME STR_VALUE\(${_package}_VERSION\)\"' >> ${${_name}_VERSION}.tmp
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${${_name}_VERSION}.tmp ${${_name}_VERSION}
		COMMAND ${CMAKE_COMMAND} -E remove ${${_name}_VERSION}.tmp
		COMMENT "Create version header in ${${_name}_VERSION}"
	)

	ADD_DEPENDENCIES(${_name} ${_name}_version)

	SET(${_package}_SOURCES ${${_package}_SOURCES} ${${_name}_VERSION})

	SC_ADD_CHANGELOG(${_name})
ENDMACRO ()

MACRO (SC_ADD_SUBDIRS)
	FILE(GLOB files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "[^.]*")
	SET(dirs "")
	SET(prio_dirs " ")
	IF (${ARGC} GREATER 0)
		SET(prio_dirs ${ARGN})
		LIST(REVERSE prio_dirs)
	ENDIF (${ARGC} GREATER 0)
	FOREACH(dir ${files})
		IF (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
			IF (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/.scignore)
				SET(dirs ${dirs} ${dir})
			ENDIF ()
		ENDIF (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
	ENDFOREACH(dir ${files})
	IF(prio_dirs)
		FOREACH(prio_dir ${prio_dirs})
			LIST(FIND dirs ${prio_dir} dirs_index)
			IF(${dirs_index} GREATER -1)
				LIST(REMOVE_AT dirs ${dirs_index})
				SET(dirs ${prio_dir} ${dirs})
			ENDIF(${dirs_index} GREATER -1)
		ENDFOREACH(prio_dir ${prio_dirs})
	ENDIF(prio_dirs)
	IF(dirs)
		SUBDIRS(${dirs})
	ENDIF()
ENDMACRO ()

MACRO (SC_SETUP_LIB_SUBDIR _package)
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY SOURCES ${${_package}_SOURCES})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY HEADERS ${${_package}_HEADERS})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY DEFS ${${_package}_DEFINITIONS})
ENDMACRO ()


# This macro changed in CMake 2.8 it does not work anymore correctly so
# it is included here as _COMPAT version
MACRO (QT_EXTRACT_OPTIONS_COMPAT _qt_files _qt_options)
	SET(${_qt_files})
	SET(${_qt_options})
	SET(_QT_DOING_OPTIONS FALSE)
	FOREACH(_currentArg ${ARGN})
		IF ("${_currentArg}" STREQUAL "OPTIONS")
			SET(_QT_DOING_OPTIONS TRUE)
		ELSE ("${_currentArg}" STREQUAL "OPTIONS")
			IF(_QT_DOING_OPTIONS)
				LIST(APPEND ${_qt_options} "${_currentArg}")
			ELSE(_QT_DOING_OPTIONS)
				LIST(APPEND ${_qt_files} "${_currentArg}")
			ENDIF(_QT_DOING_OPTIONS)
		ENDIF ("${_currentArg}" STREQUAL "OPTIONS")
	ENDFOREACH(_currentArg)
ENDMACRO ()


MACRO(SC_QT_WRAP_UI outfiles)
	QT_EXTRACT_OPTIONS_COMPAT(ui_files ui_options ${ARGN})

	IF (SC_GLOBAL_GUI_QT6)
		get_target_property(QT_UIC_EXECUTABLE Qt6::uic LOCATION)
	ELSEIF (SC_GLOBAL_GUI_QT5)
		get_target_property(QT_UIC_EXECUTABLE Qt5::uic LOCATION)
	ENDIF ()

	FOREACH (it ${ui_files})
		GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
		GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
		GET_FILENAME_COMPONENT(_rel ${it} PATH)
		IF (_rel)
			SET(_rel "${_rel}/")
		ENDIF (_rel)
		SET(outfile ${CMAKE_CURRENT_BINARY_DIR}/${_rel}ui_${outfile}.h) # Here we set output
		ADD_CUSTOM_COMMAND(OUTPUT ${outfile}
			COMMAND ${QT_UIC_EXECUTABLE}
			ARGS ${ui_options} -o ${outfile} ${infile}
			MAIN_DEPENDENCY ${infile})
		SET(${outfiles} ${${outfiles}} ${outfile})
	ENDFOREACH (it)
ENDMACRO ()


MACRO (SC_SETUP_GUI_LIB_SUBDIR _package)
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY SOURCES ${${_package}_SOURCES})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY HEADERS ${${_package}_HEADERS})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY DEFS ${${_package}_DEFINITIONS})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY MOCS ${${_package}_MOC_HEADERS})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY UIS ${${_package}_UI})
	SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY RESOURCES ${${_package}_RESOURCES})
ENDMACRO ()


MACRO (SC_ADD_SUBDIR_SOURCES ...)
	SET(prefix ${ARGV0})
	SET(dir ${ARGV1})
	ADD_SUBDIRECTORY(${dir})
	SET(sources "")
	SET(headers "")
	SET(defs "")
	GET_PROPERTY(sources DIRECTORY ${dir} PROPERTY SOURCES)
	GET_PROPERTY(headers DIRECTORY ${dir} PROPERTY HEADERS)
	GET_PROPERTY(defs DIRECTORY ${dir} PROPERTY DEFS)

	ADD_DEFINITIONS(${defs})
	SET(${prefix}_DEFINITIONS ${${prefix}_DEFINITIONS} ${defs})

	FOREACH (_src ${sources})
		SET(_src ${dir}/${_src})
		SET(${prefix}_SOURCES ${${prefix}_SOURCES} ${_src})
		#IF(NOT "${defs}" STREQUAL "")
		#	SET_SOURCE_FILES_PROPERTIES(${_src} COMPILE_FLAGS ${defs})
		#ENDIF(NOT "${defs}" STREQUAL "")
	ENDFOREACH(_src)

	FILE(RELATIVE_PATH _package_dir ${SC3_PACKAGE_SOURCE_DIR}/libs ${CMAKE_CURRENT_SOURCE_DIR})

	FOREACH (_head ${headers})
		SET(_head ${dir}/${_head})
		SET(${prefix}_HEADERS ${${prefix}_HEADERS} ${_head})
		IF(NOT ARGV2)
			STRING(REPLACE "/" ";" _head_dirs ${_head})
			LIST(LENGTH _head_dirs _head_dirs_len)
			IF(_head_dirs_len EQUAL 2)
				INSTALL(FILES ${_head} DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}/${dir})
			ENDIF(_head_dirs_len EQUAL 2)
		ENDIF(NOT ARGV2)
	ENDFOREACH(_head)
ENDMACRO ()


MACRO (SC_ADD_GUI_SUBDIR_SOURCES ...)
	SET(prefix ${ARGV0})
	SET(dir ${ARGV1})
	ADD_SUBDIRECTORY(${dir})
	SET(sources "")
	SET(headers "")
	SET(defs "")
	SET(mocs "")
	SET(uis "")
	SET(resources "")
	GET_PROPERTY(sources DIRECTORY ${dir} PROPERTY SOURCES)
	GET_PROPERTY(headers DIRECTORY ${dir} PROPERTY HEADERS)
	GET_PROPERTY(defs DIRECTORY ${dir} PROPERTY DEFS)
	GET_PROPERTY(mocs DIRECTORY ${dir} PROPERTY MOCS)
	GET_PROPERTY(uis DIRECTORY ${dir} PROPERTY UIS)
	GET_PROPERTY(resources DIRECTORY ${dir} PROPERTY RESOURCES)

	ADD_DEFINITIONS(${defs})
	SET(${prefix}_DEFINITION ${defs})

	FOREACH (_src ${sources})
		SET(_src ${dir}/${_src})
		SET(${prefix}_SOURCES ${${prefix}_SOURCES} ${_src})
	ENDFOREACH(_src)

	FILE(RELATIVE_PATH _package_dir ${SC3_PACKAGE_SOURCE_DIR}/libs ${CMAKE_CURRENT_SOURCE_DIR})

	FOREACH (_head ${headers})
		SET(_head ${dir}/${_head})
		SET(${prefix}_HEADERS ${${prefix}_HEADERS} ${_head})
		IF(NOT ARGV2)
			INSTALL(FILES ${_head} DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}/${dir})
		ENDIF(NOT ARGV2)
	ENDFOREACH(_head)

	FOREACH (_moc ${mocs})
		SET(_moc ${dir}/${_moc})
		SET(${prefix}_MOC_HEADERS ${${prefix}_MOC_HEADERS} ${_moc})
		IF(NOT ARGV2)
			INSTALL(FILES ${_moc} DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}/${dir})
		ENDIF(NOT ARGV2)
	ENDFOREACH(_moc)

	FOREACH (_res ${resources})
		SET(_res ${dir}/${_res})
		SET(${prefix}_RESOURCES ${${prefix}_RESOURCES} ${_res})
	ENDFOREACH(_res)

	FOREACH (_ui ${uis})
		SET(_ui ${dir}/${_ui})
		SET(${prefix}_UI ${${prefix}_UI} ${_ui})
		# TODO: Add QT_WRAP_HERE and set the install directory here as well
		# in cmakelists.txt set UI_HEADERS to ""
		SET(_ui_out "")
		SC_QT_WRAP_UI(_ui_out ${_ui})
		IF(NOT ARGV2)
			INSTALL(FILES ${_ui_out} DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}/${dir})
		ENDIF(NOT ARGV2)
	ENDFOREACH(_ui)
ENDMACRO ()


MACRO (SC_ADD_LIBRARY _library_package _library_name)
	SET(_global_library_package SC_${_library_package})

	IF (SHARED_LIBRARIES)
		SET(${_library_package}_TYPE SHARED)
		SET(${_global_library_package}_SHARED 1)
		IF (WIN32)
			ADD_DEFINITIONS(-D${_global_library_package}_EXPORTS)
		ENDIF (WIN32)
	ENDIF (SHARED_LIBRARIES)

	SET(LIBRARY ${_global_library_package})
	SET(LIBRARY_NAME ${_library_name})

	IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)
		CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/config.h)
		CONFIGURE_FILE(${CMAKE_CURRENT_BINARY_DIR}/config.h
		               ${CMAKE_CURRENT_BINARY_DIR}/config.h)
		CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/win32api.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
		SET(${_library_package}_HEADERS
			${${_library_package}_HEADERS}
			${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H}
			${CMAKE_CURRENT_BINARY_DIR}/config.h)
	ELSE (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)
		CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/win32api.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
		SET(${_library_package}_HEADERS
			${${_library_package}_HEADERS}
			${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
	ENDIF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)

	ADD_LIBRARY(seiscomp_${_library_name} ${${_library_package}_TYPE} ${${_library_package}_SOURCES})

	IF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/${_library_name})
		# Only add unittests automatically if the test directory does not contain
		# a CMakeLists.txt.
		IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/${_library_name}/CMakeLists.txt)

			FILE(GLOB SOURCES test/${_library_name}/*.cpp)

			FOREACH(testSrc ${SOURCES})
				GET_FILENAME_COMPONENT(testName ${testSrc} NAME_WE)
				SET(testName test_${_library_name}_${testName})
				ADD_EXECUTABLE(${testName} ${testSrc})

				TARGET_LINK_LIBRARIES(${testName} ${Boost_unit_test_framework_LIBRARY} seiscomp_${_library_name})

				ADD_TEST(
					NAME ${testName}
					WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
					COMMAND ${testName}
				)
			ENDFOREACH(testSrc)
		ENDIF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/${_library_name}/CMakeLists.txt)
	ENDIF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/${_library_name})

	INSTALL(TARGETS seiscomp_${_library_name}
		RUNTIME DESTINATION ${SC3_PACKAGE_BIN_DIR}
		ARCHIVE DESTINATION ${SC3_PACKAGE_LIB_DIR}
		LIBRARY DESTINATION ${SC3_PACKAGE_LIB_DIR}
	)
ENDMACRO ()


MACRO (SC_ADD_PLUGIN_LIBRARY _library_package _library_name _plugin_app)
	SET(_global_library_package SEISCOMP3_PLUGIN_${_library_package})

	SET(${_global_library_package}_SHARED 1)

	ADD_LIBRARY(${_library_name} MODULE ${${_library_package}_SOURCES})
	SET_TARGET_PROPERTIES(${_library_name} PROPERTIES PREFIX "")

	SET(LIBRARY ${_global_library_package})
	SET(LIBRARY_NAME ${_library_name})

	INSTALL(TARGETS ${_library_name}
		DESTINATION ${SC3_PACKAGE_SHARE_DIR}/plugins/${_plugin_app}
	)
ENDMACRO ()


MACRO (SC_ADD_GUI_PLUGIN_LIBRARY _library_package _library_name _plugin_app)
	SET(_global_library_package SEISCOMP3_PLUGIN_${_library_package})

	SET(${_global_library_package}_SHARED 1)

	# Create MOC Files
	IF (${_library_package}_MOC_HEADERS)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_CPP(${_library_package}_MOC_SOURCES ${${_library_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_CPP(${_library_package}_MOC_SOURCES ${${_library_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ENDIF ()
	ENDIF (${_library_package}_MOC_HEADERS)

	# Create UI Headers
	IF (${_library_package}_UI)
		SC_QT_WRAP_UI(${_library_package}_UI_HEADERS ${${_library_package}_UI})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
	ENDIF (${_library_package}_UI)

	# Add resources
	IF (${_library_package}_RESOURCES)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_ADD_RESOURCES(${_library_package}_RESOURCE_SOURCES ${${_library_package}_RESOURCES})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_ADD_RESOURCES(${_library_package}_RESOURCE_SOURCES ${${_library_package}_RESOURCES})
		ENDIF()
	ENDIF (${_library_package}_RESOURCES)

	SET(
		${_library_package}_FILES
			${${_library_package}_SOURCES}
			${${_library_package}_MOC_SOURCES}
			${${_library_package}_UI_HEADERS}
			${${_library_package}_RESOURCE_SOURCES}
	)

	ADD_LIBRARY(${_library_name} MODULE ${${_library_package}_FILES})
	SET_TARGET_PROPERTIES(${_library_name} PROPERTIES PREFIX "")
	IF (SC_GLOBAL_GUI_QT6)
		TARGET_LINK_LIBRARIES(${_library_name} Qt6::Widgets)
	ELSEIF (SC_GLOBAL_GUI_QT5)
		TARGET_LINK_LIBRARIES(${_library_name} Qt5::Widgets)
	ELSE ()
		TARGET_LINK_LIBRARIES(${_library_name} ${QT_LIBRARIES})
	ENDIF()

	SET(LIBRARY ${_global_library_package})
	SET(LIBRARY_NAME ${_library_name})

	INSTALL(TARGETS ${_library_name}
		DESTINATION ${SC3_PACKAGE_SHARE_DIR}/plugins/${_plugin_app}
	)
ENDMACRO ()


MACRO (SC_ADD_GUI_LIBRARY_CUSTOM_INSTALL _library_package _library_name)
	SET(_global_library_package SC_${_library_package})

	IF (SHARED_LIBRARIES)
		IF (WIN32)
			ADD_DEFINITIONS(-D${_global_library_package}_EXPORTS)
		ENDIF (WIN32)
		SET(${_library_package}_TYPE SHARED)
		SET(${_global_library_package}_SHARED 1)
	ENDIF (SHARED_LIBRARIES)

	# Create MOC Files
	IF (${_library_package}_MOC_HEADERS)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_CPP(${_library_package}_MOC_SOURCES ${${_library_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_CPP(${_library_package}_MOC_SOURCES ${${_library_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ENDIF ()
	ENDIF (${_library_package}_MOC_HEADERS)

	# Create UI Headers
	IF (${_library_package}_UI)
		SC_QT_WRAP_UI(${_library_package}_UI_HEADERS ${${_library_package}_UI})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
	ENDIF (${_library_package}_UI)

	# Add resources
	IF (${_library_package}_RESOURCES)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_ADD_RESOURCES(${_library_package}_RESOURCE_SOURCES ${${_library_package}_RESOURCES})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_ADD_RESOURCES(${_library_package}_RESOURCE_SOURCES ${${_library_package}_RESOURCES})
		ENDIF()
	ENDIF (${_library_package}_RESOURCES)

	SET(LIBRARY ${_global_library_package})
	SET(LIBRARY_NAME ${_library_name})

	IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)
		CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/config.h)
		CONFIGURE_FILE(${CMAKE_CURRENT_BINARY_DIR}/config.h
		               ${CMAKE_CURRENT_BINARY_DIR}/config.h)
		CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/win32api.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
		SET(${_library_package}_HEADERS
			${${_library_package}_HEADERS}
			${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H}
			${CMAKE_CURRENT_BINARY_DIR}/config.h)
	ELSE (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)
		CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/win32api.h.cmake
		               ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
		SET(${_library_package}_HEADERS
			${${_library_package}_HEADERS}
			${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_API_H})
	ENDIF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake)

	SET(
	${_library_package}_FILES_
	    ${${_library_package}_SOURCES}
	    ${${_library_package}_MOC_SOURCES}
	    ${${_library_package}_UI_HEADERS}
	    ${${_library_package}_RESOURCE_SOURCES}
	)

	ADD_LIBRARY(seiscomp_${_library_name} ${${_library_package}_TYPE} ${${_library_package}_FILES_})
	IF (SC_GLOBAL_GUI_QT6)
		TARGET_LINK_LIBRARIES(seiscomp_${_library_name} Qt6::Widgets)
	ELSEIF (SC_GLOBAL_GUI_QT5)
		TARGET_LINK_LIBRARIES(seiscomp_${_library_name} Qt5::Widgets)
	ELSE ()
		TARGET_LINK_LIBRARIES(seiscomp_${_library_name} ${QT_LIBRARIES})
	ENDIF()
ENDMACRO ()


MACRO (SC_ADD_GUI_LIBRARY _library_package _library_name)
	SC_ADD_GUI_LIBRARY_CUSTOM_INSTALL(${_library_package} ${_library_name})

	INSTALL(TARGETS seiscomp_${_library_name}
		RUNTIME DESTINATION ${SC3_PACKAGE_BIN_DIR}
		ARCHIVE DESTINATION ${SC3_PACKAGE_LIB_DIR}
		LIBRARY DESTINATION ${SC3_PACKAGE_LIB_DIR}
	)
ENDMACRO ()


MACRO (SC_ADD_EXECUTABLE _package _name)
	IF (${ARGC} GREATER 2)
		SET(bin_dir ${ARGV2})
	ELSE (${ARGC} GREATER 2)
		SET(bin_dir ${SC3_PACKAGE_BIN_DIR})
	ENDIF (${ARGC} GREATER 2)
	ADD_EXECUTABLE(${_name} ${${_package}_SOURCES})
	INSTALL(TARGETS ${_name}
		RUNTIME DESTINATION ${bin_dir}
		ARCHIVE DESTINATION ${SC3_PACKAGE_LIB_DIR}
		LIBRARY DESTINATION ${SC3_PACKAGE_LIB_DIR}
	)

	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)
		INSTALL(FILES config/${_name}.cfg
			DESTINATION ${SC3_PACKAGE_CONFIG_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)

	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
		INSTALL(FILES config/${_name}.xml
			DESTINATION ${SC3_PACKAGE_APP_DESC_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)

	# Install all XML files in apps config dir to etc/descriptions
	#FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/config/*.xml")
	#INSTALL(FILES ${files} DESTINATION ${SC3_PACKAGE_APP_DESC_DIR})

	IF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
		ADD_SUBDIRECTORY(test)
	ENDIF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
ENDMACRO ()


MACRO (SC_ADD_PYTHON_EXECUTABLE _name)
	SET(MAIN_PY "")
	FOREACH(file ${${_name}_FILES})
		IF(NOT MAIN_PY)
			SET(MAIN_PY ${file})
		ENDIF(NOT MAIN_PY)
	ENDFOREACH(file)

	# Pop main_py
	LIST(REMOVE_AT ${_name}_FILES 0)

	INSTALL(FILES ${${_name}_FILES} DESTINATION ${SC3_PACKAGE_BIN_DIR})
	INSTALL(PROGRAMS ${MAIN_PY} RENAME ${${_name}_TARGET} DESTINATION ${SC3_PACKAGE_BIN_DIR})

	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${${_name}_TARGET}.cfg)
		INSTALL(FILES config/${${_name}_TARGET}.cfg
			DESTINATION ${SC3_PACKAGE_CONFIG_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${${_name}_TARGET}.cfg)
	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
		INSTALL(FILES config/${_name}.xml
			DESTINATION ${SC3_PACKAGE_APP_DESC_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
ENDMACRO ()


MACRO (SC_ADD_PYTHON_PROG _name)
	INSTALL(PROGRAMS ${_name}.py RENAME ${_name} DESTINATION ${SC3_PACKAGE_BIN_DIR})
	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)
		INSTALL(FILES config/${_name}.cfg
			DESTINATION ${SC3_PACKAGE_CONFIG_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)
	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
		INSTALL(FILES config/${_name}.xml
			DESTINATION ${SC3_PACKAGE_APP_DESC_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
ENDMACRO ()

MACRO (SC_ADD_TEST_EXECUTABLE _package _name)
	ADD_DEFINITIONS(-DSEISCOMP_TEST_DATA_DIR="${PROJECT_TEST_DATA_DIR}")
	ADD_EXECUTABLE(${_name} ${${_package}_SOURCES})
ENDMACRO ()



MACRO (SC_ADD_GUI_EXECUTABLE _package _name)
	# Create MOC Files
	IF (${_package}_MOC_HEADERS)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_CPP(${_package}_MOC_SOURCES ${${_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_CPP(${_package}_MOC_SOURCES ${${_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ENDIF ()
	ENDIF (${_package}_MOC_HEADERS)

	# Create UI Headers
	IF (${_package}_UI)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_UI(${_package}_UI_HEADERS ${${_package}_UI})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_UI(${_package}_UI_HEADERS ${${_package}_UI})
		ENDIF ()
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
	ENDIF (${_package}_UI)

	# Add resources
	IF (${_package}_RESOURCES)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_ADD_RESOURCES(${_package}_RESOURCE_SOURCES ${${_package}_RESOURCES})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_ADD_RESOURCES(${_package}_RESOURCE_SOURCES ${${_package}_RESOURCES})
		ENDIF ()
	ENDIF (${_package}_RESOURCES)

	SET(
		${_package}_FILES_
			${${_package}_SOURCES}
			${${_package}_MOC_SOURCES}
			${${_package}_UI_HEADERS}
			${${_package}_RESOURCE_SOURCES}
	)

	IF(WIN32)
		ADD_EXECUTABLE(${_name} WIN32 ${${_package}_FILES_})
		TARGET_LINK_LIBRARIES(${_name} ${QT_QTMAIN_LIBRARY})
	ELSE(WIN32)
		ADD_EXECUTABLE(${_name} ${${_package}_FILES_})
	ENDIF(WIN32)

	INSTALL(TARGETS ${_name}
		RUNTIME DESTINATION ${SC3_PACKAGE_BIN_DIR}
		ARCHIVE DESTINATION ${SC3_PACKAGE_LIB_DIR}
		LIBRARY DESTINATION ${SC3_PACKAGE_LIB_DIR}
	)

	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)
		INSTALL(FILES config/${_name}.cfg
			DESTINATION ${SC3_PACKAGE_CONFIG_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.cfg)
	IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)
		INSTALL(FILES config/${_name}.xml
			DESTINATION ${SC3_PACKAGE_APP_DESC_DIR})
	ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config/${_name}.xml)

	IF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
		ADD_SUBDIRECTORY(test)
	ENDIF (SC_GLOBAL_UNITTESTS AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
ENDMACRO ()


MACRO (SC_ADD_GUI_TEST_EXECUTABLE _package _name)
	ADD_DEFINITIONS(-DSEISCOMP_TEST_DATA_DIR="${PROJECT_TEST_DATA_DIR}")

	# Create MOC Files
	IF (${_package}_MOC_HEADERS)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_CPP(${_package}_MOC_SOURCES ${${_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_CPP(${_package}_MOC_SOURCES ${${_package}_MOC_HEADERS} OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)
		ENDIF ()
	ENDIF (${_package}_MOC_HEADERS)

	# Create UI Headers
	IF (${_package}_UI)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_WRAP_UI(${_package}_UI_HEADERS ${${_package}_UI})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_WRAP_UI(${_package}_UI_HEADERS ${${_package}_UI})
		ENDIF ()
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
	ENDIF (${_package}_UI)

	# Add resources
	IF (${_package}_RESOURCES)
		IF (SC_GLOBAL_GUI_QT6)
			QT6_ADD_RESOURCES(${_package}_RESOURCE_SOURCES ${${_package}_RESOURCES})
		ELSEIF (SC_GLOBAL_GUI_QT5)
			QT5_ADD_RESOURCES(${_package}_RESOURCE_SOURCES ${${_package}_RESOURCES})
		ENDIF ()
	ENDIF (${_package}_RESOURCES)

	SET(
		${_package}_FILES_
			${${_package}_SOURCES}
			${${_package}_MOC_SOURCES}
			${${_package}_UI_HEADERS}
			${${_package}_RESOURCE_SOURCES}
	)

	IF(WIN32)
		ADD_EXECUTABLE(${_name} WIN32 ${${_package}_FILES_})
		TARGET_LINK_LIBRARIES(${_name} ${QT_QTMAIN_LIBRARY})
	ELSE(WIN32)
		ADD_EXECUTABLE(${_name} ${${_package}_FILES_})
	ENDIF(WIN32)
	TARGET_LINK_LIBRARIES(${_name} ${QT_LIBRARIES})
	TARGET_LINK_LIBRARIES(${_name} ${QT_QTOPENGL_LIBRARY})
ENDMACRO ()


MACRO (SC_LINK_LIBRARIES _name)
	TARGET_LINK_LIBRARIES(${_name} ${ARGN})
ENDMACRO ()


MACRO (SC_LINK_LIBRARIES_INTERNAL _name)
	FOREACH(_lib ${ARGN})
		TARGET_LINK_LIBRARIES(${_name} seiscomp_${_lib})
	ENDFOREACH(_lib)
ENDMACRO ()


MACRO (SC_LIB_LINK_LIBRARIES _library_name)
	TARGET_LINK_LIBRARIES(seiscomp_${_library_name} ${ARGN})
ENDMACRO ()


MACRO (SC_LIB_LINK_LIBRARIES_INTERNAL _library_name)
	FOREACH(_lib ${ARGN})
		TARGET_LINK_LIBRARIES(seiscomp_${_library_name} seiscomp_${_lib})
	ENDFOREACH(_lib)
ENDMACRO ()


MACRO (SC_SWIG_LINK_LIBRARIES_INTERNAL _module)
	FOREACH(_lib ${ARGN})
		SWIG_LINK_LIBRARIES(${_module} seiscomp_${_lib})
	ENDFOREACH(_lib)
ENDMACRO ()


MACRO (SC_SWIG_GET_MODULE_PATH _out)
	FILE(RELATIVE_PATH ${_out} ${SC3_PACKAGE_SOURCE_DIR}/libs/swig ${CMAKE_CURRENT_SOURCE_DIR})
	SET(${_out} ${SC3_PACKAGE_LIB_DIR}${PYTHON_LIBRARY_SUFFIX}/${${_out}})
ENDMACRO ()


MACRO (SC_LIB_VERSION _library_name _version _soversion)
	SET_TARGET_PROPERTIES(seiscomp_${_library_name} PROPERTIES VERSION ${_version} SOVERSION ${_soversion})
ENDMACRO ()


MACRO (SC_LIB_INSTALL_HEADERS ...)
	IF(${ARGC} GREATER 1)
		SET(_package_dir "${ARGV1}")
	ELSE(${ARGC} GREATER 1)
		FILE(RELATIVE_PATH _package_dir ${SC3_PACKAGE_SOURCE_DIR}/libs ${CMAKE_CURRENT_SOURCE_DIR})
	ENDIF(${ARGC} GREATER 1)

	INSTALL(FILES ${${ARGV0}_HEADERS}
		DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}
	)

	IF (${ARGV0}_MOC_HEADERS)
		INSTALL(FILES ${${ARGV0}_MOC_HEADERS}
			DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}
		)
	ENDIF (${ARGV0}_MOC_HEADERS)

	IF (${ARGV0}_UI_HEADERS)
		INSTALL(FILES ${${ARGV0}_UI_HEADERS}
			DESTINATION ${SC3_PACKAGE_INCLUDE_DIR}/${_package_dir}
		)
	ENDIF (${ARGV0}_UI_HEADERS)
ENDMACRO ()


MACRO (SC_PLUGIN_INSTALL _library_name _plugin_app)
	INSTALL(TARGETS seiscomp_${_library_name}
		DESTINATION ${SC3_PACKAGE_SHARE_DIR}/plugins/${_plugin_app}
	)
ENDMACRO ()


MACRO (SC_RAW_PLUGIN_INSTALL _library_name _plugin_app)
	INSTALL(TARGETS ${_library_name}
		DESTINATION ${SC3_PACKAGE_SHARE_DIR}/plugins/${_plugin_app}
	)
ENDMACRO ()


MACRO (SC_INSTALL_DATA _package _path)
	INSTALL(FILES ${${_package}_DATA}
		DESTINATION ${SC3_PACKAGE_SHARE_DIR}/${_path}
	)
ENDMACRO ()


MACRO (SC_INSTALL_CONFIG _package)
	INSTALL(FILES ${${_package}_CONFIG}
		DESTINATION ${SC3_PACKAGE_CONFIG_DIR})
ENDMACRO ()

MACRO (SC_INSTALL_INIT _module_name _script)
	INSTALL(FILES ${_script} RENAME ${_module_name}.py DESTINATION ${SC3_PACKAGE_INIT_DIR})
ENDMACRO ()
