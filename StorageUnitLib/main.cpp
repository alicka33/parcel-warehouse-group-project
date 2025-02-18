#include "storage.h"
#include <iostream>
#include "../PackagesLib/HeavyPackage.h"
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/DeliveryManagment.h"
#include "../LogisticsLib/Logistics.h"

//aktualnie brudnopis do sprawdzenia dzia³alnoœci
string GetFileName() {
	cout << "Please eneter file name: " << endl;
	string fileName;
	cin >> fileName;
	return fileName;
}

Storage_unit SetPlatform() {
	int x, y;
	cout << "Enter the lenght of platform" << endl;
	cin >> x;
	cout << "Enter the width of platform" << endl;
	cin >> y;
	Storage_unit platform("S", x, y);
	return platform;
}

//enum class StrategyNames{ r, t, f };
vector<char> strategyNames = { 'r', 't', 'f' };

bool IfValid(vector<char> startegyNames, char strategyName) {
	auto it = find(startegyNames.begin(), strategyNames.end(), strategyName);
	if (it != startegyNames.end())
		return true;
	return false;
}

char GetStrategyName() {
	cout << "Choose strategy (for RANDOM = r, TIGHT = t, FILL = f: " << endl;
	char strategyName;
	do {
		cin >> strategyName;
		strategyName = tolower(strategyName);
	} while (!IfValid(strategyNames, strategyName));
	return strategyName;
}

void ActivateStrategy(Logistics& l, char strategyName)
{
	switch(strategyName) {
	case 'r': l.setStrategy(make_unique<RandomPlacement>());break;
	case 't': l.setStrategy(make_unique<TightPlacement>()); break;
	//case 'f': l.setStrategy(make_unique<FillPlacement>()); break;
	}
}

int main()
{
<<<<<<< HEAD
	DeliveryManagment manager;
	//Delivery delivery(move(manager.ReadFileToDeliveryVector(GetFileName())));
=======
	Storage_unit magazyn("S1", 10, 10);
	Logistics l;
	l.setStrategy(make_unique<TightPlacement>());
>>>>>>> ed80867308e4ec046c5a7e007a8bc57605d0c701

	//Storage_unit magazyn("S1", 10, 10);
	Storage_unit platform = SetPlatform();
	
	Logistics l;
	ActivateStrategy(l, GetStrategyName());
	//l.setStrategy(make_unique<RandomPlacement>());
	
	Delivery d;
	/*Package p1("n1", 10, 4);
	Package p3("x2", 1, 4);
	PriorityPackage p2("p2", 2, 2);*/
	PriorityPackage p1("p1", 4, 1);
	PriorityPackage p2("p2", 4, 1);
	HeavyPackage p3("h3", 4, 1, 1);
	PriorityPackage p4("p4", 4, 1);
	Package p5("n5", 2, 3);
	PriorityPackage p6("p6", 9, 2);
	d.AddPackage(p1);
	d.AddPackage(p2);
<<<<<<< HEAD
	l.unpackDelivery(&platform, &d);
	platform.Simple_visualisation();
=======
	d.AddPackage(p3);
	d.AddPackage(p4);
	d.AddPackage(p5);
	d.AddPackage(p6);
	l.unpackDelivery(&magazyn, &d);
	magazyn.Simple_visualisation();
>>>>>>> ed80867308e4ec046c5a7e007a8bc57605d0c701

	return 0;
}