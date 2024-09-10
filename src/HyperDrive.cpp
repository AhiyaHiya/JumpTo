#include "HyperDrive/HyperDrive.h"

#include <filesystem>
#include <format>
#include <iostream>

namespace HyperDrive
{
bool AddTo(DataSet::Locations& dataSet, DataSet::Name name, DataSet::Path path)
{
    if (name.empty())
    {
        throw std::invalid_argument("Name parameter is empty and is required");
    }
    if (path.empty())
    {
        throw std::invalid_argument("Path parameter is empty and is required");
    }
    if (dataSet.contains(name))
    {
        std::cout << "Location already exists: " << name << "\n";
        return false;
    }

    std::filesystem::path resolvedPath;
    auto printMessage = [](std::string_view name, std::string_view location)
        {
            std::cout << "Added location \"" << name << "\" for " << location << "\n";
        };
    if (path == ".")
    {
        const auto currentPath = std::filesystem::current_path().string();
        dataSet[name] = currentPath;
        printMessage(name, currentPath);
        return true;
    }
    if (path == "..")
    {
        const auto cwd = std::filesystem::current_path();
        const auto parent = cwd.parent_path().string();
        dataSet[name] = parent;
        printMessage(name, parent);
        return true;
    }

    auto unverifiedPath = std::filesystem::path(path);
    if (!std::filesystem::exists(unverifiedPath))
    {
        throw std::runtime_error("Path not found");
    }
    if (!std::filesystem::is_directory(unverifiedPath))
    {
        throw std::runtime_error("Path does not point to folder");
    }
    const auto locationPath = std::filesystem::path(path).string();
    dataSet[name] = locationPath;
    printMessage(name, locationPath);
    return true;
}
void Clean(DataSet::Locations& dataSet)
{
    throw std::runtime_error("Not implemented");
}

std::string Get(const DataSet::Location& location, const DataSet::Locations& dataSet)
{
    if (!dataSet.contains(location))
    {
        std::cout << "Location not found: " << location << "\n";
        return "";
    }
    return dataSet.at(location);
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