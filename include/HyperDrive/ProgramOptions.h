#pragma once

#include <boost/program_options.hpp>

#include <cstdint>

namespace ProgramOptions
{
void ParseCommandLineArguments(std::uint32_t argc, char** argv,
    boost::program_options::options_description& outOptions,
    boost::program_options::variables_map& outVariables);
}
