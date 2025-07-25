cmake_minimum_required(VERSION 3.16)

set(KF_VERSION "6.17.0") # handled by release scripts
set(KF_DEP_VERSION "6.16.0") # handled by release scripts
project(KUnitConversion VERSION ${KF_VERSION})

include(FeatureSummary)
find_package(ECM 6.16.0  NO_MODULE)
set_package_properties(ECM PROPERTIES TYPE REQUIRED DESCRIPTION "Extra CMake Modules." URL "https://commits.kde.org/extra-cmake-modules")
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(ECMGenerateExportHeader)
include(ECMSetupVersion)
include(ECMGenerateHeaders)
include(ECMQtDeclareLoggingCategory)
include(ECMDeprecationSettings)
include(ECMGenerateQDoc)

set(EXCLUDE_DEPRECATED_BEFORE_AND_AT 0 CACHE STRING "Control the range of deprecated API excluded from the build [default=0].")

set(REQUIRED_QT_VERSION 6.7.0)
find_package(Qt6 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Core Network)

option(BUILD_PYTHON_BINDINGS "Build Python bindings" ON)

# Only Linux and FreeBSD CI has the relevant packages
if (ANDROID OR APPLE OR WIN32 OR HAIKU OR NOT BUILD_SHARED_LIBS)
    set(BUILD_PYTHON_BINDINGS OFF)
endif()

if (BUILD_PYTHON_BINDINGS)
    find_package(Python3 3.9 REQUIRED COMPONENTS Interpreter Development)
    find_package(Shiboken6 REQUIRED)
    find_package(PySide6 REQUIRED)
endif()

add_feature_info(PYTHON_BINDINGS ${BUILD_PYTHON_BINDINGS} "Python bindings")

set(CMAKECONFIG_INSTALL_DIR "${KDE_INSTALL_CMAKEPACKAGEDIR}/KF6UnitConversion")

set(kunitconversion_version_header "${CMAKE_CURRENT_BINARY_DIR}/src/kunitconversion_version.h")
ecm_setup_version(PROJECT VARIABLE_PREFIX KUNITCONVERSION
                        VERSION_HEADER "${kunitconversion_version_header}"
                        PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/KF6UnitConversionConfigVersion.cmake"
                        SOVERSION 6)

# I18n
find_package(KF6I18n ${KF_DEP_VERSION} REQUIRED)
add_definitions(-DTRANSLATION_DOMAIN=\"kunitconversion6\")
ki18n_install(po)

ecm_set_disabled_deprecation_versions(
    QT 6.10.0
    KF 6.16.0
)

add_subdirectory(src)
if (BUILD_TESTING)
    add_subdirectory(autotests)
endif()
# create a Config.cmake and a ConfigVersion.cmake file and install them
include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/KF6UnitConversionConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/KF6UnitConversionConfig.cmake"
    INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/KF6UnitConversionConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/KF6UnitConversionConfigVersion.cmake"
    DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
    COMPONENT Devel
)
install(EXPORT KF6UnitConversionTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE KF6UnitConversionTargets.cmake NAMESPACE KF6:: )
install(FILES
    ${kunitconversion_version_header}
    DESTINATION ${KDE_INSTALL_INCLUDEDIR_KF}/KUnitConversion COMPONENT Devel
)

include(ECMFeatureSummary)
ecm_feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

if (BUILD_PYTHON_BINDINGS)
    include(ECMGeneratePythonBindings)
    add_subdirectory(python)
endif()
