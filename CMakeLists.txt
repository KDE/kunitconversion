cmake_minimum_required(VERSION 3.16)

set(KF_VERSION "5.89.0") # handled by release scripts
set(KF_DEP_VERSION "5.87.0") # handled by release scripts
project(KUnitConversion VERSION ${KF_VERSION})

include(FeatureSummary)
find_package(ECM 5.87.0  NO_MODULE)
set_package_properties(ECM PROPERTIES TYPE REQUIRED DESCRIPTION "Extra CMake Modules." URL "https://commits.kde.org/extra-cmake-modules")
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

set(REQUIRED_QT_VERSION 5.15.2)
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Core Network)
include(KDEInstallDirs)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(GenerateExportHeader)
include(ECMSetupVersion)
include(ECMGenerateHeaders)
include(ECMQtDeclareLoggingCategory)

set(CMAKECONFIG_INSTALL_DIR "${KDE_INSTALL_CMAKEPACKAGEDIR}/KF5UnitConversion")

ecm_setup_version(PROJECT VARIABLE_PREFIX KUNITCONVERSION
                        VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/kunitconversion_version.h"
                        PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/KF5UnitConversionConfigVersion.cmake"
                        SOVERSION 5)

# QCH
include(ECMAddQch)
option(BUILD_QCH "Build API documentation in QCH format (for e.g. Qt Assistant, Qt Creator & KDevelop)" OFF)
add_feature_info(QCH ${BUILD_QCH} "API documentation in QCH format (for e.g. Qt Assistant, Qt Creator & KDevelop)")
if (BUILD_QCH)
    ecm_install_qch_export(
        TARGETS KF5UnitConversion_QCH
        FILE KF5UnitConversionQchTargets.cmake
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        COMPONENT Devel
    )
    set(PACKAGE_INCLUDE_QCHTARGETS "include(\"\${CMAKE_CURRENT_LIST_DIR}/KF5UnitConversionQchTargets.cmake\")")
endif()

# I18n
find_package(KF5I18n ${KF_DEP_VERSION} REQUIRED)
add_definitions(-DTRANSLATION_DOMAIN=\"kunitconversion5\")
ki18n_install(po)
add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x050f02)
add_definitions(-DKF_DISABLE_DEPRECATED_BEFORE_AND_AT=0x055100)

add_subdirectory(src)
if (BUILD_TESTING)
    add_subdirectory(autotests)
endif()
# create a Config.cmake and a ConfigVersion.cmake file and install them
include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/KF5UnitConversionConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/KF5UnitConversionConfig.cmake"
    INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/KF5UnitConversionConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/KF5UnitConversionConfigVersion.cmake"
    DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
    COMPONENT Devel
)
install(EXPORT KF5UnitConversionTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE KF5UnitConversionTargets.cmake NAMESPACE KF5:: )
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/kunitconversion_version.h
    DESTINATION ${KDE_INSTALL_INCLUDEDIR_KF5} COMPONENT Devel
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
