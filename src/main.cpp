
#include "HyperDrive/HyperDrive.h"
#include "HyperDrive/ProgramOptions.h"

#include <cstdint>
#include <iostream>

std::int32_t main(std::int32_t argc, char** argv)
{
    auto arguments = ProgramOptions::Arguments();
    try
    {
        ProgramOptions::ParseCommandLineArguments(argc, argv, arguments);

        if (arguments.Variables.count("help") || argc == 1)
        {
            std::cout << arguments.AllowedOptions << "\n";
            return 0;
        }

        const auto dataFullFilename = DataSet::GetAppDataFilename();
        auto dataSet = DataSet::LoadDefaultFile();

        if (arguments.Variables.count("add"))
        {
            std::cout << "Add called\n";
            const auto args = arguments.Variables["add"].as<std::vector<std::string>>();
            const auto name = args.at(0);
            const auto path = args.at(1);
            if (HyperDrive::AddTo(dataSet, name, path))
            {
                DataSet::SaveToFile(dataSet, dataFullFilename);
            }
            return 0;
        }
        if (arguments.Variables.count("clean"))
        {
            std::cout << "Clean called\n";
            HyperDrive::Clean(dataSet);
            DataSet::SaveToFile(dataSet, dataFullFilename);
            return 0;
        }
        if (arguments.Variables.count("list"))
        {
            std::cout << "List called\n";
            HyperDrive::List(dataSet);
            return 0;
        }
        if (arguments.Variables.count("remove"))
        {
            std::cout << "Remove called\n";
            const auto name = arguments.Variables["remove"].as<std::string>();
            dataSet.erase(name);
            DataSet::SaveToFile(dataSet, dataFullFilename);
            return 0;
        }
        if (arguments.Variables.count("version"))
        {
            std::cout << "Version called\n";
            std::cout << std::format("HyperDrive version: {}.{}.{}\n",
                VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
            return 0;
        }
        if (argc == 2)
        {
            std::cout << "Get location called\n";
            const auto location = std::string(argv[1]);
            const auto path = HyperDrive::Get(location, dataSet);
            std::cout << path << "\n";
            return 0;
        }
    }
    catch (const boost::program_options::error& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        std::cerr << arguments.AllowedOptions << "\n";
        return -1;
    }
    catch (std::invalid_argument& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return -2;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return -3;
    }
    catch (...)
    {
        std::cout << "Unhandled exception \n";
        return -4;
    }

    return 0;
}