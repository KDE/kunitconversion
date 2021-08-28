include(ECMAddTests)

find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Test)

ecm_add_tests(
    valuetest.cpp
    categorytest.cpp
    convertertest.cpp
    LINK_LIBRARIES KF5::UnitConversion KF5::I18n Qt5::Test
)

qt5_add_resources(CURRENCY_TEST_RESOURCES currencytableinittest/data.qrc)
ecm_add_test(
    currencytableinittest.cpp
    ${CURRENCY_TEST_RESOURCES}
    TEST_NAME currencytableinittest
    LINK_LIBRARIES KF5::UnitConversion KF5::I18n Qt5::Test
)
