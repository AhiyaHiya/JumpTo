
#include "HyperDrive/DataSet.h"

#include <boost/program_options.hpp>

#include <cstdint>
#include <iostream>

void ListLocations(auto dataSet)
{
    if (dataSet.empty())
    {
        printf("No locations stored\n");
        return;
    }

    for (const auto& [locationName, path] : dataSet)
    {
        auto message = std::format("{} : {}", locationName, path);
        printf("%s\n", message.c_str());
    }
}

std::int32_t main(std::int32_t argc, char** argv)
{
    auto options = boost::program_options::options_description("Program options");
    options.add_options()
        ("help,h", "produce help message")
        ("add,a", boost::program_options::value<std::string>(),"Add a location")
        ("clean,c", "Clean up any locations that don't exist anymore")
        ("list,l", "List all of the locations")
        ("remove,r", boost::program_options::value<std::string>(), "Remove given location")
        ("location", boost::program_options::value<std::string>(), "Location");

    auto positionalArgs = boost::program_options::positional_options_description();
    positionalArgs.add("location", 1);

    auto variables = boost::program_options::variables_map();
    try
    {
        boost::program_options::store(
            boost::program_options::command_line_parser(argc, argv)
            .options(options)
            .positional(positionalArgs)
            .run(), variables);
        boost::program_options::notify(variables);
    }
    catch (const boost::program_options::error& ex)
    {
        std::cout << "Error: " << ex.what() << "\n";
        std::cout << options << "\n";
        return 0;
    }
    

    if(variables.empty() || variables.count("help"))
    {
        std::cout << options << "\n";
        return 0;
    }

    // Normal program operation
    // Load up data entries
    auto dataSet = DataSet::LoadDefaultFile();

    if (variables.count("add"))
    {
        printf("Add called\n");
        return 0;
    }
    if (variables.count("clean"))
    {
        printf("Clean called\n");
        return 0;
    }
    if (variables.count("list"))
    {
        ListLocations(dataSet);
        return 0;
    }
    if (variables.count("location"))
    {
        printf("Location called\n");
        return 0;
    }

    return 0;
}