#pragma once

#include <map>
#include <string>

namespace DataSet
{
void CreateJsonFile(const std::string& filePath);
auto GetAppDataPath() -> std::string;
auto LoadDefaultFile() -> std::map<std::string, std::string>;
auto LoadFromFile(const std::string& fileName) -> std::map<std::string, std::string>;
void SaveToFile(const std::map<std::string, std::string>& dataSet, const std::string& fileName);
}