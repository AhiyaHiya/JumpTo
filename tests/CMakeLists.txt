
enable_testing()

add_executable(HyperDriveTests
    "HyperDriveTests.cpp"
)

target_link_libraries(HyperDriveTests
    PRIVATE
        HyperDriveLib
        GTest::GTest
        GTest::Main
)
