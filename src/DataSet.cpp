#include "JumpTo/DataSet.h"

#include <nlohmann/json.hpp>

#ifdef _WIN32
#include <shlobj.h> // For SHGetFolderPath
#elif defined(__APPLE__)
#include <unistd.h>
#else
#include <unistd.h>
#endif

#include <cstdint>
#include <filesystem>
#include <fstream>

using namespace std::string_literals;

namespace DataSet
{
void CreateJsonFile(const std::string& filePath)
{
    auto jsonData = nlohmann::json();
    auto emptyMap = std::map<std::string, std::string>();
    jsonData = emptyMap;

    // Write JSON to file
    auto file = std::ofstream(filePath);
    if (file.is_open())
    {
        file << jsonData.dump(4); // Pretty print with 4 spaces
        file.close();
    }
    else
    {
        auto message = std::format("Unable to open file for writing: {}", filePath);
        throw std::runtime_error(message);
    }
}

auto GetAppDataFilename() -> std::string
{
    const auto appDataPath = std::filesystem::path(GetAppDataPath());
    const auto filePath = std::filesystem::path(appDataPath / "hyperdrive_data.json"s);
    return filePath.string();
}

auto GetAppDataPath() -> std::string
{
    auto appDataPath = std::string();
    auto appFolderName = "JumpTo"s;
#ifdef _WIN32
    char path[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
    {
        appDataPath = std::format("{}\\{}", path, appFolderName);
    }
#elif defined(__APPLE__)
    const char* home = getenv("HOME");
    if (home != nullptr)
    {
        appDataPath = std::format("{}/Library/Application Support/{}", home, appFolderName);
    }
#else
    const char* home = getenv("HOME");
    if (home != nullptr)
    {
        appDataPath = std::format("{}/.{}", home, appFolderName);
    }
#endif
    return appDataPath;
}

auto LoadDefaultFile() -> Locations
{
    const auto appDataPath = GetAppDataPath();
    const auto jsonFilePath = GetAppDataFilename();
    if (std::filesystem::exists(jsonFilePath) == false)
    {
        if (!std::filesystem::exists(appDataPath))
        {
            std::filesystem::create_directories(appDataPath);
        }
        CreateJsonFile(jsonFilePath);
    }

    return LoadFromFile(jsonFilePath);
}

auto LoadFromFile(const std::string& fileName) -> Locations
{
    auto fileStream = std::ifstream(fileName);
    auto json = nlohmann::json();
    fileStream >> json;
    return json.get<std::map<std::string, std::string>>();
}

void SaveToFile(const Locations& dataSet, const std::string& fileName)
{
    auto json = nlohmann::json(dataSet);
    auto fileStream = std::ofstream(fileName);
    fileStream << json;
}

}
