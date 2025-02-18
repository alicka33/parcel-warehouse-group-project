#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include  "Packages.h"
#include  "PriorityPackage.h"
#include  "HeavyPackage.h"
#include  "Exceptions.h"

using namespace std;


class DeliveryManagment
{
private:
	vector<unique_ptr<Package>> deliveryVector;
public:
	DeliveryManagment();
	vector<unique_ptr<Package>> const& GetDeliveryVector() const;
	vector<unique_ptr<Package>>& ReadFileToDeliveryVector(string fileName);

	int StringToInt(string word);
	double StringToDouble(string word);

	void AddRowToDeliveryVector(vector<string> row);

};


