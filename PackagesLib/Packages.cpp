#include "pch.h"
#include "framework.h"
#include "Packages.h"

Package::Package(string id, int lenght, int width)
{
	this->id = id;
	this->length = lenght;
	this->width = width;
}

Package::Package()
{
	this->id = "n";
	this->length = 0;
	this->width = 0;
}

Package::Package(std::string package_type, std::ifstream& path)
{
	id = package_type;
	path >> width;
	path >> length;
}


string Package::GetId()
{
	return id;
}

int Package::GetLength()
{
	return length;
}

int Package::GetWidth()
{
	return width;
}

int Package::GetArea()
{
	return length * width;
}

void Package::SetLength(int newLenght)
{
	length = newLenght;
}

void Package::SetWidth(int newWidth)
{
	width = newWidth;
}

/* Compares if two normal packages are equal */
bool Package::operator==(Package givenPackage)
{
	if (id == givenPackage.GetId() && length == givenPackage.GetLength() && width == givenPackage.GetWidth())
		return true;
	return false;
}

/* Compares if lenght, weight && area parameters are smaller ir equal then the ones of givenPackage */
bool Package::operator<=(Package givenPackage)
{
	if (length <= givenPackage.GetLength() && width <= givenPackage.GetWidth() && GetArea() <= givenPackage.GetArea())
		return true;
	return false;
}

/* Compares if the package is bigger then givenPackage */
bool Package::operator>(Package givenPackage)
{
	if ((length > givenPackage.GetLength() || width > givenPackage.GetWidth()) && GetArea() > givenPackage.GetArea())
		return true;
	return false;
}

/* Returns information about the package */
string Package::GetInfo()
{
	stringstream ss;
	ss << "Normal Package | id: " << id << " | length: " << length << " | width: " << width << endl;
	return ss.str();
}

std::string Package::Save_data()
{
	std::stringstream anwser;

	anwser << id;
	anwser << " ";
	anwser << width;
	anwser << " ";
	anwser << length;

	return(anwser.str());
}

void Package::Turn()
{
	int help;
	help = length;
	length = width;
	width = help;
}