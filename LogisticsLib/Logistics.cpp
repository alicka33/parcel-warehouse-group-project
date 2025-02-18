#include "../LogisticsLib/pch.h"
//#include "../LogisticsLib/Logistics.h"
//
//
//Logistics::Logistics()
//{
//}
//
//void RandomPlacement::placePackages(Storage_unit* storage, Delivery* delivery)
//{
//	std::cout << "aaaaaa\n";
//	srand(time(0));
//	while (!delivery->GetDeliveryVector().empty()) {
//		Package p;
//		delivery->TakeOutFirstPackage(p);
//		for (int i = 0; i < 10; i++) {
//			int x = rand() % storage->GetWidth();
//			int y = rand() % storage->GetLength();
//			try {
//				storage->Set_package(x, y, &p);
//				break;
//			}
//			catch (FieldAlreadyUsedException) {
//				continue;
//			}
//		}
//	}
//}
