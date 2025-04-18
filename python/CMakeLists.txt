# SPDX-FileCopyrightText: 2024 Manuel Alcaraz Zambrano <manuelalcarazzam@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

set(bindings_library "KUnitConversion")

set(wrapped_header ${CMAKE_SOURCE_DIR}/python/bindings.h)
set(typesystem_file ${CMAKE_SOURCE_DIR}/python/bindings.xml)

set(generated_sources
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_module_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_converter_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_unit_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_unitcategory_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_updatejob_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion/kunitconversion_value_wrapper.cpp)

set(qt_libs Qt6::Core)

ecm_generate_python_bindings(
    PACKAGE_NAME ${bindings_library}
    VERSION ${KF_VERSION}
    WRAPPED_HEADER ${wrapped_header}
    TYPESYSTEM ${typesystem_file}
    GENERATED_SOURCES ${generated_sources}
    DEPENDENCIES KF6::UnitConversion
    QT_VERSION ${REQUIRED_QT_VERSION}
    HOMEPAGE_URL "https://invent.kde.org/frameworks/kunitconversion"
    ISSUES_URL "https://bugs.kde.org/describecomponents.cgi?product=frameworks-kunitconversion"
    AUTHOR "The KDE Community"
    README ../README.md
)

target_link_libraries(${bindings_library} PRIVATE KF6UnitConversion)

execute_process(COMMAND ${Python_EXECUTABLE} -Esc "import sysconfig; print(sysconfig.get_path('platlib', vars={'platbase': '${CMAKE_INSTALL_PREFIX}', 'base': '${CMAKE_INSTALL_PREFIX}'}))" OUTPUT_VARIABLE sysconfig_output)

string(STRIP ${sysconfig_output} PYTHON_INSTALL_DIR)

install(TARGETS ${bindings_library} LIBRARY DESTINATION "${PYTHON_INSTALL_DIR}")
