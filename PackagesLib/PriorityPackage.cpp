#include "pch.h"
#include "framework.h"
#include "PriorityPackage.h"


PriorityPackage::PriorityPackage(string id, int lenght, int width) : Package(id, lenght, width)
{
}

PriorityPackage::PriorityPackage()
{
	this->id = "p";
	this->length = 0;
	this->width = 0;
}

PriorityPackage::PriorityPackage(std::string package_type, std::ifstream& path)
{
	id = package_type;
	path >> width;
	path >> length;
}

/* Returns information about the priority package */
string PriorityPackage::GetInfo()
{
	stringstream ss;
	ss << "Priority Package | id: " << id << " | length: " << length << " | width: " << width << endl;
	return ss.str();
}

std::string PriorityPackage::Save_data()
{
	std::stringstream anwser;

	anwser << id;
	anwser << " ";
	anwser << width;
	anwser << " ";
	anwser << length;

	return(anwser.str());
}
