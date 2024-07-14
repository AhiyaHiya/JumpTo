add_library(HyperDriveInterface INTERFACE
    "HyperDrive/DataSet.h"
    "HyperDrive/HyperDrive.h"
    "HyperDrive/ProgramOptions.h"
)

target_include_directories(HyperDriveInterface
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)
