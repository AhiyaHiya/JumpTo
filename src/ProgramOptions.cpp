#include "HyperDrive/ProgramOptions.h"

namespace ProgramOptions
{
void ParseCommandLineArguments(std::uint32_t argc, char** argv,
    boost::program_options::options_description& outOptions,
    boost::program_options::variables_map& outVariables)
{
    outOptions.add_options()
        ("help,h", "Shows this message")
        ("add,a", boost::program_options::value<std::string>(),"Add a new location")
        ("clean,c", "Clean up any locations that don't exist anymore")
        ("list,l", "List all the saved locations")
        ("remove,r", boost::program_options::value<std::string>(), "Remove a location")
        ("version,v", "Prints the app version")
        ("location", boost::program_options::value<std::string>(), "Go to the specified location. If not specified, the first positional argument is used for this");

    auto positionalArgs = boost::program_options::positional_options_description();
    positionalArgs.add("location", 1);

    boost::program_options::store(
        boost::program_options::command_line_parser(argc, argv)
        .options(outOptions)
        .positional(positionalArgs)
        .run(), outVariables);
    boost::program_options::notify(outVariables);
}
}