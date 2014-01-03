add_definitions(-DTRANSLATION_DOMAIN="libkunitconversion")

set(kunitconversion_LIB_SRCS
    kcurrencycode.cpp
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
generate_export_header(KF5UnitConversion BASE_NAME KUnitConversion EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h)
add_library(KF5::UnitConversion ALIAS KF5UnitConversion)
target_include_directories(KF5UnitConversion PUBLIC "$<BUILD_INTERFACE:${KUnitConversion_BINARY_DIR}>")
target_include_directories(KF5UnitConversion INTERFACE "$<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>/KUnitConversion")

target_link_libraries(KF5UnitConversion PUBLIC  Qt5::Core
                                        PRIVATE Qt5::Xml
                                                Qt5::Network
                                                KF5::I18n #i18n(), ...
                                                KF5::ConfigCore #only KCurrencyCodePrivate::loadCurrency
)

set_target_properties(KF5UnitConversion PROPERTIES VERSION   ${KUNITCONVERSION_VERSION_STRING}
                                                   SOVERSION ${KUNITCONVERSION_SOVERSION}
                                                   EXPORT_NAME UnitConversion
)

ecm_generate_headers(
  Converter
  Value
  Unit
  UnitCategory

  MODULE_NAME KUnitConversion
  PREFIX KUnitConversion
  REQUIRED_HEADERS KUnitConversion_namespaced_HEADERS
)
ecm_generate_headers(
  KCurrencyCode

  MODULE_NAME KUnitConversion
  REQUIRED_HEADERS KUnitConversion_HEADERS
)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/KUnitConversion DESTINATION ${INCLUDE_INSTALL_DIR} COMPONENT Devel)

install(TARGETS KF5UnitConversion EXPORT KF5UnitConversionTargets ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h
  ${KUnitConversion_namespaced_HEADERS}
  DESTINATION ${INCLUDE_INSTALL_DIR}/KUnitConversion/kunitconversion COMPONENT Devel
)
install(FILES
  ${KUnitConversion_HEADERS}
  DESTINATION ${INCLUDE_INSTALL_DIR}/KUnitConversion COMPONENT Devel
)
