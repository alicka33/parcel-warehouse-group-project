#pragma once
#include<iostream>

using namespace std;

class EmptyDeliveryException : public exception
{
public:
	string what()
	{
		return "Empty delivery!";
	}
};

class PackageNotInDeliveryException : public exception
{
public:
	string what()
	{
		return "No such package in delivery!";
	}
};

class OpeningFileException : public exception
{
public:
	string what()
	{
		return "File could not be opened!";
	}
};
