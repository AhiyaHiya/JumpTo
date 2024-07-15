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
        ("list,l", "List all the saved locations")
        ("remove,r", boost::program_options::value<std::string>(), "Remove a location")
        ("version,v", "Prints the app version");

    arguments.HiddenOptions.add_options()
        ("location", boost::program_options::value<std::string>(),
            "Go to specified location");

    auto allOptions = boost::program_options::options_description();
    allOptions.add(arguments.AllowedOptions).add(arguments.HiddenOptions);

    auto positionalArgs = boost::program_options::positional_options_description();
    positionalArgs.add("add", 2).add("remove", 1).add("location", 2);

    boost::program_options::store(
        boost::program_options::command_line_parser(argc, argv)
        .options(allOptions)
        .positional(positionalArgs)
        .run(), arguments.Variables);

    boost::program_options::notify(arguments.Variables);
}
}