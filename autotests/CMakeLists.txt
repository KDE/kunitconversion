include(ECMAddTests)

find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Test)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_BINARY_DIR}/src")

ecm_add_tests(
    valuetest.cpp
    categorytest.cpp
    convertertest.cpp
    LINK_LIBRARIES KF5::UnitConversion Qt5::Test
)
