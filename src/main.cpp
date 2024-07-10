
#include "HyperDrive/DataSet.h"

#include <boost/program_options.hpp>

#include <cstdint>
#include <iostream>

std::int32_t main(std::int32_t argc, char** argv)
{
    auto options = boost::program_options::options_description("Program options");
    options.add_options()
        ("help", "produce help message")
        ("add", "Add a location")
        ("clean", "Clean up any locations that don't exist anymore")
        ("list", "List all of the locations");

    auto positionalArgs = boost::program_options::positional_options_description();
    positionalArgs.add("location", -1); // -1 means all positional arguments are assigned to location

    auto variables = boost::program_options::variables_map();
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv)
        .options(options)
        .positional(positionalArgs)
        .run(), variables);
    boost::program_options::notify(variables);

    if(variables.empty() || variables.count("help"))
    {
        std::cout << options << "\n";
        return 0;
    }

    // Normal program operation
    // Load up data entries
    auto dataSet = DataSet::LoadDefaultFile();

    if (variables.count("list"))
    {
        if(dataSet.empty())
        {
            printf("No locations stored\n");
            return 0;
        }

        for (const auto& [locationName, path] : dataSet)
        {
            auto message = std::format("{} : {}", locationName, path);
            printf("%s\n", message.c_str());
        }

        return 0;
    }

    return 0;
}