add_library(HyperDriveInterface INTERFACE
    "JumpTo/DataSet.h"
    "JumpTo/JumpTo.h"
    "JumpTo/ProgramOptions.h"
)

target_include_directories(HyperDriveInterface
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)
