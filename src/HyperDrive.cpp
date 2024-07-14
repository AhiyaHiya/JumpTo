#include "HyperDrive/HyperDrive.h"

#include <filesystem>
#include <format>
#include <iostream>

namespace HyperDrive
{
void AddTo(DataSet::Locations& dataSet, DataSet::Name name, DataSet::Path path)
{
    if (dataSet.contains(name))
    {
        std::cout << "Location already exists: " << name << "\n";
        return;
    }
    std::filesystem::path resolvedPath;
    if (path == ".")
    {
        resolvedPath = std::filesystem::current_path();
    }
    if (path == "..")
    {
        auto cwd = std::filesystem::current_path();
        resolvedPath = cwd.parent_path();
    }
    resolvedPath = std::filesystem::path(path).string();

    dataSet[name] = resolvedPath.string();
}
void Clean(DataSet::Locations& dataSet)
{
    throw std::runtime_error("Not implemented");
}

void GoTo(const DataSet::Location& location, const DataSet::Locations& dataSet)
{
    throw std::runtime_error("Not implemented");
}

void List(const DataSet::Locations& dataSet)
{
    if (dataSet.empty())
    {
        printf("No locations stored\n");
        return;
    }

    for (const auto& [name, path] : dataSet)
    {
        auto message = std::format("{} : {}", name, path);
        printf("%s\n", message.c_str());
    }
}
}