#include "pch.h"
#include "framework.h"
#include "HeavyPackage.h"

HeavyPackage::HeavyPackage(string id, int length, int width, float weight) : Package(id, length, width)
{
	this->weight = weight;
}

HeavyPackage::HeavyPackage()
{
	this->id = "h";
	this->length = 0;
	this->width = 0;
	this->weight = 0.0;
}

HeavyPackage::HeavyPackage(std::string package_type, std::ifstream& path)
{
	id = package_type;
	path >> width;
	path >> length;
	path >> weight;
}

float HeavyPackage::GetWeight()
{
	return weight;
}

void HeavyPackage::SetWeight(float newWeight)
{
	weight = newWeight;
}

/* Compares if two heavy packages are equal */
bool HeavyPackage::operator==(HeavyPackage givenPackage)
{
	if (id == givenPackage.GetId() and length == givenPackage.GetLength() and width == givenPackage.GetWidth() and weight == givenPackage.GetWeight())
		return true;
	return false;
}

/* Compares if heavy package is smaller or equal then givenPackage */
bool HeavyPackage::operator<=(HeavyPackage givenPackage)
{
	if (length <= givenPackage.GetLength() and width <= givenPackage.GetWidth() and weight <= givenPackage.GetWeight() and GetArea() <= givenPackage.GetArea())
		return true;
	return false;
}

/* Compares if two heavy package is bigger then givenPackage */
bool HeavyPackage::operator>(HeavyPackage givenPackage)
{
	if ((length > givenPackage.GetLength() or width > givenPackage.GetWidth()) and GetArea() > givenPackage.GetArea() or (GetArea() == givenPackage.GetArea() and weight > givenPackage.GetWeight()))
		return true;
	return false;
}

/* Returns information about the heavy package */
string HeavyPackage::GetInfo()
{
	stringstream ss;
	ss << "Heavy Package | id: " << id << " | length: " << length << " | width: " << width << " | weight: " << weight << endl;
	return ss.str();
}

std::string HeavyPackage::Save_data()
{
	std::stringstream anwser;

	anwser << id;
	anwser << " ";
	anwser << width;
	anwser << " ";
	anwser << length;
	anwser << " ";
	anwser << weight;

	return(anwser.str());
}

