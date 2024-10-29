#pragma once

#include "JumpTo/DataSet.h"

#include <string>

namespace JumpTo
{
// Returns true if operation succeeded
bool AddTo(DataSet::Locations& dataSet, DataSet::Name name, DataSet::Path path);
void Clean(DataSet::Locations& dataSet);
std::string Get(const DataSet::Location& location, const DataSet::Locations& dataSet);
void List(const DataSet::Locations& dataSet);
}