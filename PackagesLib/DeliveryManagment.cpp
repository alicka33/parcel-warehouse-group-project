#include "pch.h"
#include "framework.h"
#include "DeliveryManagment.h"

DeliveryManagment::DeliveryManagment()
{

}

vector<unique_ptr<Package>> const& DeliveryManagment::GetDeliveryVector() const
{
	return deliveryVector;
}

/* Reads package infromation from file and stores into delivery - a vector of unique pointers */
vector<unique_ptr<Package>>& DeliveryManagment::ReadFileToDeliveryVector(string fileName)
{
	vector<string> row;
	string line, param;
	//fstream file;
	//file.open(fileName, ios::in);
	ifstream file(fileName);

	// nag³owek ?? 

	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			row.clear();
			stringstream ss(line);
			while (getline(ss, param, ','))
				row.push_back(param);
			AddRowToDeliveryVector(row);
		}
		file.close();
		return deliveryVector;
	}
	else
		throw OpeningFileException();

}

/* Converts string to int */
int DeliveryManagment::StringToInt(string word)
{
	stringstream ss;
	int res;
	ss << word;
	ss >> res;
	return res;
}

/* Converts string to double */
double DeliveryManagment::StringToDouble(string word)
{
	stringstream ss;
	double res;
	ss << word;
	ss >> res;
	return res;
}

// czy tu powinno byæ sprawdzenie czy paczka ju¿ znajduje siê w delivery???
/* Creates the right unique_ptr to the right object based on the first letter in id */
void DeliveryManagment::AddRowToDeliveryVector(vector<string> row)
{
	string id = row[0];
	switch (id[0]) {
	case 'n': deliveryVector.push_back(make_unique<Package>(id, StringToInt(row[1]), StringToInt(row[2]))); break;
	case 'p': deliveryVector.push_back(make_unique<PriorityPackage>(id, StringToInt(row[1]), StringToInt(row[2]))); break;
	case 'h': deliveryVector.push_back(make_unique<HeavyPackage>(id, StringToInt(row[1]), StringToInt(row[2]), StringToDouble(row[3]))); break;
		// potencjalnie default --> wyrzucenie b³êdu
	}
}
