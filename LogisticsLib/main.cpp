#include "pch.h"
#include "../StorageUnitLib/storage.h"
#include "../PackagesLib/Delivery.h"
#include "Logistics.h"
//aktualnie brudnopis do sprawdzenia działalności

int main()
{
	Storage_unit magazyn("S1", 10, 10);
	Delivery d;
	Package p("n1", 2, 2);
	d.AddPackage(p);
	Logistics l;
	l.setStrategy(make_unique<RandomPlacement>());
	l.unpackDelivery(&magazyn, &d);
	magazyn.Simple_visualisation();
	int x;
	cin >> x;
	return 0;
}