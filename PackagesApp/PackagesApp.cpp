#include "../PackagesLib/pch.h"
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/PriorityPackage.h"
#include "../PackagesLib/HeavyPackage.h"
#include "../PackagesLib/Delivery.h"
#include "../PackagesLib/DeliveryManagment.h"
#include <iostream>

using namespace std;

int main()
{

    //Package normal("n1", 1, 2);
    //Package normal2("n1", 2, 2);
    //Package normal3("n1", 3, 4);
    //Package normal4("n1", 3, 5);
    //PriorityPackage prio("p1", 2, 3);
    //HeavyPackage heavy("h4", 4, 5, 3);
    //vector<unique_ptr<Package>>deliveryVector;
    ////unique_ptr<Package> packagePtr(new Package(p1));
    //deliveryVector.push_back(make_unique<Package>("n1", 1, 2));
    //deliveryVector.push_back(make_unique<HeavyPackage>("h5", 4, 5, 6));
    //deliveryVector.push_back(make_unique<PriorityPackage>("p1", 2, 3));
    //deliveryVector.push_back(make_unique<PriorityPackage>("p2", 4, 6));
    //deliveryVector.push_back(make_unique<Package>("n2", 1, 1));
    //deliveryVector.push_back(make_unique<Package>("n3", 6, 7));
    //deliveryVector.push_back(make_unique<HeavyPackage>("h4", 4, 5, 3));
    
   // Delivery delivery(move(deliveryVector));
   // //delivery.AddPackage(normal);
   // //cout << delivery.GetDeliveryVector().size();
   // //cout << delivery.IfInDelivery(prio);
   // Package n;
   // PriorityPackage p;
   // HeavyPackage h;
   // cout << delivery.IfInDelivery(heavy);
   // cout << delivery.GetDeliveryVector().size();
   //// cout << delivery.TakeOutFirstPackage(h)->GetInfo();
   // //cout << delivery.TakeOutFirstPackage(h)->GetInfo();
   // delivery.RemovePackage(heavy);
   // cout << delivery.GetDeliveryVector().size();
   // cout << delivery.IfInDelivery(heavy);
    //cout << delivery.GetDeliveryVector().size();
    //PriorityPackage p = delivery.TakeOutBestPackage2(prio).get();
    //unique_ptr<Package> foundPackage = delivery.TakeOutBestPackagePtr(prio);
    //cout << delivery.IfInDeliveryTemp(heavy);
    
    //DeliveryManagment manager;
    ////Delivery delivery(move(manager.ReadFileToDeliveryVector("\PackagesLib\x64\Debug\File.txt"))); // --> błąd przy wczytywaniu
    ////Delivery delivery(move(manager.ReadFileToDeliveryVector("PackageFile.csv"))); // --> błąd przy wczytywaniu
    ////cout << delivery.GetDeliveryVector().size();
    ////cout << delivery.IfInDelivery(normal);
    //return 0;
}

//TODO:
// 3. strategy
// 5. consty unsined????
// zaktualizować readme 