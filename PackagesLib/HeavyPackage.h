#pragma once
#include "Packages.h"

class HeavyPackage : public Package
{
private:
	float weight;
public:
	HeavyPackage(string id, int length, int width, float weight);
	HeavyPackage();
	HeavyPackage(std::string package_type, std::ifstream& path);
	float GetWeight();
	void SetWeight(float newWeight);
	bool operator==(HeavyPackage givenPackage);
	bool operator<=(HeavyPackage givenPackage);
	bool operator>(HeavyPackage givenPackage);
	string GetInfo();
	std::string Save_data();

};
