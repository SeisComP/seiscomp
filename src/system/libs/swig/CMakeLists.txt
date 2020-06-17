INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(WRAPPER_MODULES config)

SET(WRAPPER_MODULE_config_EXTRA_SC_LIBS config)

SET(build_lib_python_seiscomp_dir ${CMAKE_BINARY_DIR}/lib/python/seiscomp)
FILE(MAKE_DIRECTORY ${build_lib_python_seiscomp_dir})
FILE(GENERATE OUTPUT ${build_lib_python_seiscomp_dir}/__init__.py CONTENT "")

FOREACH (wrapper_module ${WRAPPER_MODULES})
        SET(
                ${wrapper_module}_SOURCES
                        ${wrapper_module}_python_wrap.cxx
                        ${WRAPPER_MODULE_${wrapper_module}_EXTRA_FILES}
        )
        ADD_LIBRARY(_${wrapper_module} MODULE ${${wrapper_module}_SOURCES})
        SET_TARGET_PROPERTIES(_${wrapper_module} PROPERTIES PREFIX "")
        TARGET_LINK_LIBRARIES(_${wrapper_module} ${PYTHON_LIBRARIES})
        TARGET_LINK_LIBRARIES(_${wrapper_module} ${WRAPPER_MODULE_${wrapper_module}_EXTRA_LIBS})
        SC_LINK_LIBRARIES_INTERNAL(_${wrapper_module} ${WRAPPER_MODULE_${wrapper_module}_EXTRA_SC_LIBS})

        ADD_CUSTOM_TARGET(link_build_lib_python_seiscomp_${wrapper_module} ALL
                COMMAND ${CMAKE_COMMAND} -E create_symlink
                        ${CMAKE_CURRENT_SOURCE_DIR}/${wrapper_module}.py
                        ${build_lib_python_seiscomp_dir}/${wrapper_module}.py
                COMMAND ${CMAKE_COMMAND} -E create_symlink
                        ${CMAKE_BINARY_DIR}/lib/_${wrapper_module}.so
                        ${build_lib_python_seiscomp_dir}/_${wrapper_module}.so
        )
ENDFOREACH (wrapper_module)

SC_SWIG_GET_MODULE_PATH(_module_path)
SET(_module_path ${SC3_PACKAGE_PYTHON_LIB_DIR}/seiscomp)

FOREACH (wrapper_module ${WRAPPER_MODULES})
        INSTALL(
                TARGETS _${wrapper_module}
                LIBRARY DESTINATION ${_module_path}
        )

        INSTALL(
                FILES ${CMAKE_CURRENT_SOURCE_DIR}/${wrapper_module}.py
                DESTINATION ${_module_path}
        )

        INSTALL(
                FILES ${CMAKE_CURRENT_BINARY_DIR}/${wrapper_module}.pyc
                DESTINATION ${_module_path}
                OPTIONAL
        )

        INSTALL(
                FILES ${CMAKE_CURRENT_BINARY_DIR}/${wrapper_module}.pyo
                DESTINATION ${_module_path}
                OPTIONAL
        )

        ADD_CUSTOM_COMMAND(
                TARGET _${wrapper_module}
                POST_BUILD
                COMMAND ${CMAKE_SOURCE_DIR}/py-compile ARGS --python \"${PYTHON_EXECUTABLE}\" --destdir ${CMAKE_CURRENT_BINARY_DIR} ${wrapper_module}.py
        )
ENDFOREACH (wrapper_module)

