#include "HyperDrive/ProgramOptions.h"

namespace ProgramOptions
{
void ParseCommandLineArguments(std::uint32_t argc, char** argv, Arguments& arguments)
{
    arguments.AllowedOptions.add_options()
        ("help,h", "Shows this message")
        ("add,a", boost::program_options::value<std::vector<std::string>>()->multitoken(),
            "Add a new location")
        ("clean,c", "Clean up any locations that don't exist anymore")
        ("get,g", boost::program_options::value<std::string>(), "Get a location by key")
        ("list,l", "List all the saved locations")
        ("remove,r", boost::program_options::value<std::string>(), "Remove a location")
        ("version,v", "Prints the app version");


    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, arguments.AllowedOptions),
        arguments.Variables);

    if (arguments.Variables.count("add")
        + arguments.Variables.count("list")
        + arguments.Variables.count("remove")
        + arguments.Variables.count("version") > 1)
    {
        throw std::runtime_error("Error: Only one option can be selected at a time");
    }
}
}