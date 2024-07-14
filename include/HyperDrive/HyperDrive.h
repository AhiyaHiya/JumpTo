#pragma once

#include "HyperDrive/DataSet.h"

namespace HyperDrive
{
void AddTo(DataSet::Locations& dataSet, DataSet::Name name, DataSet::Path path);
void Clean(DataSet::Locations& dataSet);
void GoTo(const DataSet::Location& location, const DataSet::Locations& dataSet);
void List(const DataSet::Locations& dataSet);
}