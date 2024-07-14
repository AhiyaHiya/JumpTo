
#include "HyperDrive/HyperDrive.h"
#include "HyperDrive/ProgramOptions.h"

#include <cstdint>
#include <iostream>

std::int32_t main(std::int32_t argc, char** argv)
{
    boost::program_options::options_description options("HyperDrive options");
    boost::program_options::variables_map variables;
    try
    {
        ProgramOptions::ParseCommandLineArguments(argc, argv, options, variables);

        if (variables.empty() || variables.count("help"))
        {
            std::cout << options << "\n";
            return 0;
        }

        auto dataSet = DataSet::LoadDefaultFile();

        if (variables.count("add"))
        {
            HyperDrive::AddTo(dataSet, "name", "path");
            return 0;
        }
        if (variables.count("clean"))
        {
            HyperDrive::Clean(dataSet);
            return 0;
        }
        if (variables.count("list"))
        {
            HyperDrive::List(dataSet);
            return 0;
        }
        if (variables.count("location"))
        {
            HyperDrive::GoTo("location", dataSet);
            return 0;
        }
        if (variables.count("version"))
        {
            std::cout << std::format("HyperDrive version: {}.{}.{}\n",
                VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
            return 0;
        }
    }
    catch (const boost::program_options::error& ex)
    {
        std::cout << "Error: " << ex.what() << "\n";
        std::cout << options << "\n";
        return -1;
    }
    catch (...)
    {
        std::cout << "Unknown exception \n";
        return -2;
    }

    return 0;
}