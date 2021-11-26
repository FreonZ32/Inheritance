#pragma once
#include"Human.h"
#include"Professional_area.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"
#include"Stdafx.h"

void Save_to_file(const Human* group[], const int size, const string& filename);
//void Print(const Human* group[], const int size);
Human** Load_from_file(const string& filename);
Human* HumanFactory(const string& human_type);