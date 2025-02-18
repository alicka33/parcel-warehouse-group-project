#pragma once
#include "Packages.h"

class PriorityPackage : public Package
{
public:
	PriorityPackage(string id, int length, int width);
	PriorityPackage();
	PriorityPackage(std::string package_type, std::ifstream& path);
	string GetInfo();
	std::string Save_data();

};
