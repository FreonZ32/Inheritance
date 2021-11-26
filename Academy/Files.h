#pragma once
#include"Human.h"

void Save_to_file(const Human* group[], const int size, const string& filename);
Human** Load_from_file(const string& filename);