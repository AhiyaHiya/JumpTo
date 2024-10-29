
#include <JumpTo/JumpTo.h>

#include <gtest/gtest.h>

#include <string>

using namespace std::string_literals;

namespace HyperDriveTests
{
TEST(NoThrow, AddTo)
{
    auto dataSet = DataSet::Locations();

    ASSERT_THROW(JumpTo::AddTo(dataSet, ""s, ""s), std::invalid_argument) <<
        "This function should not continue with invalid parameters";
}

TEST(NoThrow, Clean)
{
    auto dataSet = DataSet::Locations();

    ASSERT_NO_THROW(JumpTo::Clean(dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}

TEST(NoThrow, GoTo)
{
    auto dataSet = DataSet::Locations();
    ASSERT_NO_THROW(JumpTo::Get("someUnknownLocation"s, dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}

TEST(NoThrow, List)
{
    auto dataSet = DataSet::Locations();
    ASSERT_NO_THROW(JumpTo::List(dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}

TEST(Boundary, AddTo)
{
    auto dataSet = DataSet::Locations();

    ASSERT_NO_THROW(JumpTo::AddTo(dataSet, ""s, ""s)) <<
        "If this function doesn't succeed, it should exit gracefully";
}

TEST(Boundary, Clean)
{
    auto dataSet = DataSet::Locations();

    ASSERT_NO_THROW(JumpTo::Clean(dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}

TEST(Boundary, GoTo)
{
    auto dataSet = DataSet::Locations();
    ASSERT_NO_THROW(JumpTo::Get("someUnknownLocation"s, dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}

TEST(Boundary, List)
{
    auto dataSet = DataSet::Locations();
    ASSERT_NO_THROW(JumpTo::List(dataSet)) <<
        "With an empty dataset, this function should return gracefully";
}
}