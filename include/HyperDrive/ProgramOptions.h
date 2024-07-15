#pragma once

#include <boost/program_options.hpp>

#include <cstdint>

namespace ProgramOptions
{
struct Arguments
{
    boost::program_options::options_description AllowedOptions = boost::program_options::options_description("Allowed options");
    boost::program_options::options_description HiddenOptions = boost::program_options::options_description("Hidden options");
    boost::program_options::variables_map Variables;
};

void ParseCommandLineArguments(std::uint32_t argc, char** argv, Arguments& arguments);
}
