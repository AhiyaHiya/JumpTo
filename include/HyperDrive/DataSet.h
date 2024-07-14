#pragma once

#include <map>
#include <string>

namespace DataSet
{
using Name = std::string;
using Path = std::string;
using Location = std::string;
using Locations = std::map<Name, Path>;

void CreateJsonFile(const std::string& filePath);
auto GetAppDataPath() -> std::string;
auto LoadDefaultFile() -> Locations;
auto LoadFromFile(const std::string& fileName) -> Locations;
void SaveToFile(const Locations& dataSet, const std::string& fileName);
}