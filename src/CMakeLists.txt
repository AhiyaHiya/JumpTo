add_library(HyperDriveLib STATIC
    "DataSet.cpp"
    "JumpTo.cpp"
    "ProgramOptions.cpp"
)

target_link_libraries(HyperDriveLib
    PUBLIC
        HyperDriveInterface
        Boost::program_options
        nlohmann_json::nlohmann_json
)
