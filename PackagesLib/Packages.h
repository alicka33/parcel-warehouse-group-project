#pragma once
#include<string>
#include<sstream>
#include <fstream>
using namespace std;

class Package
{
protected:
	int length, width; // int, poniewa¿ wielkoœæi te bêd¹ okreœlone w iloœci pól
	string id;
public:
	// ustawienie domyœlnych na 0, 0, 0  ??? mia³o by sens dla findBestPackage 
	Package(string id, int length, int width);
	Package();
	Package(std::string package_type, std::ifstream& path);
	// przeci¹zenie dla ka¿ej z funckji 
	string GetId();
	int GetLength();
	int GetWidth();
	int GetArea();
	void SetLength(int newLength);
	void SetWidth(int newWidth);
	bool operator==(Package givenPackage);
	bool operator<=(Package givenPackage);
	bool operator>(Package givenPackage);
	virtual string GetInfo();
	virtual std::string Save_data();
	void Turn();

};

