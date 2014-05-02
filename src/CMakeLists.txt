add_definitions(-DTRANSLATION_DOMAIN="libkunitconversion")

set(kunitconversion_LIB_SRCS
    converter.cpp
    value.cpp
    unit.cpp
    unitcategory.cpp
    length.cpp
    area.cpp
    volume.cpp
    temperature.cpp
    velocity.cpp
    mass.cpp
    pressure.cpp
    energy.cpp
    currency.cpp
    power.cpp
    timeunit.cpp
    fuel_efficiency.cpp
    density.cpp
    acceleration.cpp
    force.cpp
    angle.cpp
    frequency.cpp
)

add_library(KF5UnitConversion ${kunitconversion_LIB_SRCS})
if (MSVC)
    # As stated in http://msdn.microsoft.com/en-us/library/4hwaceh6.aspx M_PI only gets defined
	# when using MSVC if _USE_MATH_DEFINES is defined (this is needed for angle.cpp)
    target_compile_definitions(KF5UnitConversion PRIVATE _USE_MATH_DEFINES)
endif()
generate_export_header(KF5UnitConversion BASE_NAME KUnitConversion EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h)
add_library(KF5::UnitConversion ALIAS KF5UnitConversion)
target_include_directories(KF5UnitConversion PUBLIC "$<BUILD_INTERFACE:${KUnitConversion_BINARY_DIR};${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(KF5UnitConversion INTERFACE "$<INSTALL_INTERFACE:${KF5_INCLUDE_INSTALL_DIR}/KUnitConversion>")

target_link_libraries(KF5UnitConversion PUBLIC  Qt5::Core
                                        PRIVATE Qt5::Xml
                                                Qt5::Network
                                                KF5::I18n #i18n(), ...
)

set_target_properties(KF5UnitConversion PROPERTIES VERSION   ${KUNITCONVERSION_VERSION_STRING}
                                                   SOVERSION ${KUNITCONVERSION_SOVERSION}
                                                   EXPORT_NAME UnitConversion
)

ecm_generate_headers(KUnitConversion_CamelCase_HEADERS
  HEADER_NAMES
  Converter
  Value
  Unit
  UnitCategory

  PREFIX KUnitConversion
  REQUIRED_HEADERS KUnitConversion_namespaced_HEADERS
)
install(FILES ${KUnitConversion_CamelCase_HEADERS} DESTINATION ${KF5_INCLUDE_INSTALL_DIR}/KUnitConversion/KUnitConversion COMPONENT Devel)

install(TARGETS KF5UnitConversion EXPORT KF5UnitConversionTargets ${KF5_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h
  ${KUnitConversion_namespaced_HEADERS}
  DESTINATION ${KF5_INCLUDE_INSTALL_DIR}/KUnitConversion/kunitconversion COMPONENT Devel
)
install(FILES
  ${KUnitConversion_HEADERS}
  DESTINATION ${KF5_INCLUDE_INSTALL_DIR}/KUnitConversion COMPONENT Devel
)

include(ECMGeneratePriFile)
ecm_generate_pri_file(BASE_NAME KUnitConversion LIB_NAME KF5UnitConversion DEPS "core" FILENAME_VAR PRI_FILENAME INCLUDE_INSTALL_DIR ${KF5_INCLUDE_INSTALL_DIR}/KUnitConversion)
install(FILES ${PRI_FILENAME} DESTINATION ${ECM_MKSPECS_INSTALL_DIR})
