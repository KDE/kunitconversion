# SPDX-FileCopyrightText: 2024 Manuel Alcaraz Zambrano <manuelalcarazzam@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

find_package(KF6 6.3 REQUIRED COMPONENTS UnitConversion)

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

set(dependencies Qt6::Core)

PythonBindings(
    TARGETNAME "KF6UnitConversion"
    PACKAGE_NAME ${bindings_library}
    WRAPPED_HEADER ${wrapped_header}
    TYPESYSTEM ${typesystem_file}
    GENERATED_SOURCES ${generated_sources}
    DEPENDENCIES ${dependencies}
    PYPROJECT "pyproject.toml")