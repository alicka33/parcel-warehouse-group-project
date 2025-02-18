#pragma once
#include<string>
#include<sstream>
#include <fstream>
using namespace std;

class Package
{
protected:
	int length, width; // int, poniewa� wielko��i te b�d� okre�lone w ilo�ci p�l
	string id;
public:
	// ustawienie domy�lnych na 0, 0, 0  ??? mia�o by sens dla findBestPackage 
	Package(string id, int length, int width);
	Package();
	Package(std::string package_type, std::ifstream& path);
	// przeci�zenie dla ka�ej z funckji 
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

