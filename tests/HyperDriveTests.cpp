
#include <HyperDrive/HyperDrive.h>

#include <gtest/gtest.h>

TEST(HyperDriveTests, AddTo)
{
    auto dataSet = DataSet::Locations();
    
    HyperDrive::AddTo(dataSet, "", "");
}