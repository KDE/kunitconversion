add_library(KF5UnitConversion)
add_library(KF5::UnitConversion ALIAS KF5UnitConversion)

ecm_qt_declare_logging_category(KF5UnitConversion
    HEADER kunitconversion_debug.h
    IDENTIFIER LOG_KUNITCONVERSION
    CATEGORY_NAME kf.kunitconversion
    DESCRIPTION "kunitconversion"
    EXPORT KUNITCONVERSION
)

target_sources(KF5UnitConversion PRIVATE
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
    thermal_conductivity.cpp
    thermal_flux.cpp
    thermal_generation.cpp
    voltage.cpp
    electrical_current.cpp
    electrical_resistance.cpp
    permeability.cpp
    binary_data.cpp
)

if (WIN32)
    # As stated in http://msdn.microsoft.com/en-us/library/4hwaceh6.aspx M_PI only gets defined
    # when using MSVC if _USE_MATH_DEFINES is defined (this is needed for angle.cpp)
    target_compile_definitions(KF5UnitConversion PRIVATE _USE_MATH_DEFINES)
endif()
ecm_generate_export_header(KF5UnitConversion
    BASE_NAME KUnitConversion
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h
    GROUP_BASE_NAME KF
    VERSION ${KF_VERSION}
    DEPRECATED_BASE_VERSION 0
    DEPRECATION_VERSIONS 5.91
    EXCLUDE_DEPRECATED_BEFORE_AND_AT ${EXCLUDE_DEPRECATED_BEFORE_AND_AT}
)

set(kunitconversion_BUILD_INCLUDE_DIRS ${KUnitConversion_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(KF5UnitConversion PUBLIC "$<BUILD_INTERFACE:${kunitconversion_BUILD_INCLUDE_DIRS}>")
target_include_directories(KF5UnitConversion INTERFACE "$<INSTALL_INTERFACE:${KDE_INSTALL_INCLUDEDIR_KF}/KUnitConversion>")

target_link_libraries(KF5UnitConversion PUBLIC  Qt${QT_MAJOR_VERSION}::Core
                                        PRIVATE Qt${QT_MAJOR_VERSION}::Network
                                                KF5::I18n
)

set_target_properties(KF5UnitConversion PROPERTIES VERSION   ${KUNITCONVERSION_VERSION}
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
    REQUIRED_HEADERS KUnitConversion_HEADERS
)
install(FILES ${KUnitConversion_CamelCase_HEADERS} DESTINATION ${KDE_INSTALL_INCLUDEDIR_KF}/KUnitConversion/KUnitConversion COMPONENT Devel)

install(TARGETS KF5UnitConversion EXPORT KF5UnitConversionTargets ${KF5_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion/kunitconversion_export.h
    ${KUnitConversion_HEADERS}
    DESTINATION ${KDE_INSTALL_INCLUDEDIR_KF}/KUnitConversion/kunitconversion COMPONENT Devel
)

ecm_qt_install_logging_categories(
    EXPORT KUNITCONVERSION
    FILE kunitconversion.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)

if(BUILD_QCH)
    ecm_add_qch(
        KF5UnitConversion_QCH
        NAME KUnitConversion
        BASE_NAME KF5UnitConversion
        VERSION ${KF_VERSION}
        ORG_DOMAIN org.kde
        SOURCES # using only public headers, to cover only public API
            ${KUnitConversion_HEADERS}
        MD_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md"
        LINK_QCHS
            Qt5Core_QCH
        INCLUDE_DIRS
            ${kunitconversion_BUILD_INCLUDE_DIRS}
        BLANK_MACROS
            KUNITCONVERSION_EXPORT
            KUNITCONVERSION_DEPRECATED
            KUNITCONVERSION_DEPRECATED_EXPORT
        TAGFILE_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        QCH_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        COMPONENT Devel
    )
endif()

include(ECMGeneratePriFile)
ecm_generate_pri_file(BASE_NAME KUnitConversion LIB_NAME KF5UnitConversion DEPS "core" FILENAME_VAR PRI_FILENAME INCLUDE_INSTALL_DIR ${KDE_INSTALL_INCLUDEDIR_KF}/KUnitConversion)
install(FILES ${PRI_FILENAME} DESTINATION ${ECM_MKSPECS_INSTALL_DIR})
