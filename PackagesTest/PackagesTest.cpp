#include "pch.h"
#include "CppUnitTest.h"
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/PriorityPackage.h"
#include "../PackagesLib/HeavyPackage.h"
#include "../PackagesLib/Delivery.h"
#include "../PackagesLib/DeliveryManagment.h"
#include<string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PackagesTest
{
	TEST_CLASS(Packages)
	{
	public:

		TEST_METHOD(GetLengthInt)
		{
			Package package = Package("1", 2, 3);
			Assert::AreEqual(2, package.GetLength());
		}
		
		TEST_METHOD(GetWidth)
		{
			Package package = Package("1", 2, 3);
			Assert::AreEqual(3, package.GetWidth());
		}

		TEST_METHOD(Setlength)
		{
			Package package = Package("1", 2, 3);
			package.SetLength(4);
			Assert::AreEqual(4, package.GetLength());
		}

		TEST_METHOD(SetWidth)
		{
			Package package = Package("1", 2, 3);
			package.SetWidth(4);
			Assert::AreEqual(4, package.GetWidth());
		}

		TEST_METHOD(comparisonTrue)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("1", 2, 3);
			bool result = package1 == package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonFalse)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 5, 3);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonFalse2)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 2, 3);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonSmallerTrue)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 5, 4);
			bool result = package1 <= package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonSmallerFalse1)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 1, 1);
			bool result = package1 <= package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonSmallerFalse2)
		{
			Package package1 = Package("1", 2, 3);
			Package package2 = Package("2", 5, 1);
			bool result = package1 <= package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonBiggerTrue)
		{
			Package package1 = Package("2", 5, 3);
			Package package2 = Package("1", 2, 1);
			bool result = package1 > package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonBiggerFalse)
		{
			Package package1 = Package("1", 2, 2);
			Package package2 = Package("2", 5, 1);
			bool result = package1 > package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(GetInfo)
		{
			Package package = Package("n1", 2, 3);
			string info = package.GetInfo();
			string result = "Normal Package | id: n1 | length: 2 | width: 3\n";
			Assert::AreEqual(result, info); 
		} 
	};

	TEST_CLASS(PriorityPackages)
	{
	public:

		TEST_METHOD(GetInfo)
		{
			PriorityPackage prioPackage = PriorityPackage("p1", 2, 3);
			string info = prioPackage.GetInfo();
			string result = "Priority Package | id: p1 | length: 2 | width: 3\n";
			Assert::AreEqual(result, info);
		}
	};

	TEST_CLASS(HeavyPackages)
	{
	public:

		TEST_METHOD(GetWeight)
		{
			float a = 5.0;
			HeavyPackage package = HeavyPackage("h1", 2, 4, a);
			Assert::AreEqual(a, package.GetWeight());
		}

		TEST_METHOD(SetWeight)
		{
			HeavyPackage package = HeavyPackage("h1", 2, 4, 4.f);
			package.SetWeight(2.f);
			Assert::AreEqual(2.f, package.GetWeight());
		}

		TEST_METHOD(havyComparisonTrue)
		{
			HeavyPackage package1 = HeavyPackage("h1", 2, 4, 2.f);
			HeavyPackage package2 = HeavyPackage("h1", 2, 4, 2.f);
			bool result = package1 == package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(havyComparisonFalse)
		{
			HeavyPackage package1 = HeavyPackage("h1", 2, 3, 1.f);
			HeavyPackage package2 = HeavyPackage("h2", 4, 2, 3.f);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(havyComparisonFalse2)
		{
			HeavyPackage package1 = HeavyPackage("h1", 2, 3, 1.f);
			HeavyPackage package2 = HeavyPackage("h1", 2, 3, 3.f);
			bool result = package1 == package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonSmallerTrue)
		{
			HeavyPackage package1 = HeavyPackage("1", 2, 3, 1.f);
			HeavyPackage package2 = HeavyPackage("2", 5, 4, 3.f);
			bool result = package1 <= package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonSmallerFalse1)
		{
			HeavyPackage package1 = HeavyPackage("2", 5, 4, 3.f);
			HeavyPackage package2 = HeavyPackage("1", 2, 3, 1.f);
			bool result = package1 <= package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonSmallerFalse2)
		{
			HeavyPackage package1 = HeavyPackage("1", 2, 3, 3.f);
			HeavyPackage package2 = HeavyPackage("1", 2, 3, 1.f);
			bool result = package1 <= package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(comparisonBiggerTrue)
		{
			HeavyPackage package1 = HeavyPackage("2", 5, 4, 3.f);
			HeavyPackage package2 = HeavyPackage("1", 2, 3, 1.f);
			bool result = package1 > package2;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(comparisonBiggerFalse)
		{
			HeavyPackage package1 = HeavyPackage("1", 2, 3, 1.f);
			HeavyPackage package2 = HeavyPackage("2", 5, 4, 3.f);
			bool result = package1 > package2;
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(GetInfo)
		{
			HeavyPackage prioPackage = HeavyPackage("h1", 2, 3, 5.f);
			string info = prioPackage.GetInfo();
			string result = "Heavy Package | id: h1 | length: 2 | width: 3 | weight: 5\n";
			Assert::AreEqual(result, info);
		}
	};

	
	TEST_CLASS(Deliveries)
	{
	public:

		TEST_METHOD(IfInDeliveryTrue)
		{
			Package normal("n1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<Package>("n1", 1, 2));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(true, delivery.IfInDelivery(normal));
		}

		TEST_METHOD(IfInDeliveryFalse)
		{
			Package normal("n1", 1, 3);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<Package>("n1", 1, 2));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(false, delivery.IfInDelivery(normal));
		}

		TEST_METHOD(IfInDeliveryTruePrio)
		{
			PriorityPackage prio("p1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<PriorityPackage>("p1", 1, 2));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(true, delivery.IfInDelivery(prio));
		}

		TEST_METHOD(IfInDeliveryFalsePrio)
		{
			PriorityPackage prio("p1", 3, 2);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<PriorityPackage>("p1", 1, 2));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(false, delivery.IfInDelivery(prio));
		}

		TEST_METHOD(IfInDeliveryTrueHeavy)
		{
			HeavyPackage heavy("h1", 1, 2, 9);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<HeavyPackage>("h1", 1, 2, 9));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(true, delivery.IfInDelivery(heavy));
		}

		TEST_METHOD(IfInDeliveryFalseHeavy)
		{
			HeavyPackage heavy("h1", 1, 2, 8);
			vector<unique_ptr<Package>> deliveryVector;
			deliveryVector.push_back(make_unique<HeavyPackage>("h1", 1, 2, 9));
			Delivery delivery(move(deliveryVector));
			Assert::AreEqual(false, delivery.IfInDelivery(heavy));
		}

		TEST_METHOD(AddPackageNormal)
		{
			Package normal("n1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			Assert::AreEqual(true, delivery.IfInDelivery(normal));
		}

		TEST_METHOD(AddPackagePrio)
		{
			PriorityPackage prio("p1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(prio);
			Assert::AreEqual(true, delivery.IfInDelivery(prio));
		}

		TEST_METHOD(AddPackageHeavy)
		{
			HeavyPackage heavy("h1", 1, 2, 9);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(heavy);
			Assert::AreEqual(true, delivery.IfInDelivery(heavy));
		}

		TEST_METHOD(RemovePackageNormal)
		{
			Package normal("n1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			Assert::AreEqual(true, delivery.IfInDelivery(normal));
			delivery.RemovePackage(normal);
			Assert::AreEqual(false, delivery.IfInDelivery(normal));

		}

		TEST_METHOD(RemovePackagePrio)
		{
			PriorityPackage prio("p1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(prio);
			Assert::AreEqual(true, delivery.IfInDelivery(prio));
			delivery.RemovePackage(prio);
			Assert::AreEqual(false, delivery.IfInDelivery(prio));
		}

		TEST_METHOD(RemovePackageHeavy)
		{
			HeavyPackage heavy("h1", 1, 2, 9);
			HeavyPackage heavy2("h2", 1, 2, 8);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(heavy);
			delivery.AddPackage(heavy2);
			Assert::AreEqual(true, delivery.IfInDelivery(heavy));
			delivery.RemovePackage(heavy);
			Assert::AreEqual(false, delivery.IfInDelivery(heavy));
			Assert::AreEqual(true, delivery.IfInDelivery(heavy2));
		}


		TEST_METHOD(TakeOutFirstPackageNormal)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			Package normal2("n2", 5, 6);
			Package n;
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			delivery.AddPackage(prio);
			delivery.AddPackage(normal2);
			unique_ptr<Package> resultPtr = delivery.TakeOutFirstPackage(n);
			Package result = *resultPtr;
			bool ifEqual = normal == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(normal));
		}

		TEST_METHOD(TakeOutFirstPackagePrio)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			PriorityPackage prio2("p2", 2, 3);
			PriorityPackage p;
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			delivery.AddPackage(prio);
			delivery.AddPackage(prio2);
			unique_ptr<PriorityPackage> resultPtr = delivery.TakeOutFirstPackage(p);
			PriorityPackage result = *resultPtr;
			bool ifEqual = prio == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(prio));

		}

		TEST_METHOD(TakeOutFirstPackageHeavy)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			HeavyPackage heavy("h1", 1, 2, 9);
			HeavyPackage heavy2("h2", 3, 7, 9);
			HeavyPackage h;
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(heavy);
			unique_ptr<HeavyPackage> resultPtr = delivery.TakeOutFirstPackage(h);
			HeavyPackage result = *resultPtr;
			bool ifEqual = heavy == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(heavy));
		}

		TEST_METHOD(TakeOutGivenPackageNormal)
		{
			Package normal("n1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			Assert::AreEqual(true, delivery.IfInDelivery(normal));
			unique_ptr<Package> resultPtr = delivery.TakeOutGivenPackage(normal);
			Package result = *resultPtr;
			bool ifEqual = normal == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(normal));
		}

		TEST_METHOD(TakeOutGivenPackagePrio)
		{
			PriorityPackage prio("p1", 1, 2);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(prio);
			unique_ptr<PriorityPackage> resultPtr = delivery.TakeOutGivenPackage(prio);
			PriorityPackage result = *resultPtr;
			bool ifEqual = prio == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(prio));
			
		}

		TEST_METHOD(TakeOutGivenPackageHeavy)
		{
			HeavyPackage heavy("h1", 1, 2, 9);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(heavy);
			unique_ptr<HeavyPackage> resultPtr = delivery.TakeOutGivenPackage(heavy);
			HeavyPackage result = *resultPtr;
			bool ifEqual = heavy == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(heavy));
		}
		
		TEST_METHOD(TakeOutBestPackageNormal)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			HeavyPackage heavy("h1", 1, 2, 3);
			Package normal2("n2", 5, 2);
			Package perfect("n3", 5, 6);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			delivery.AddPackage(prio);
			delivery.AddPackage(heavy);
			delivery.AddPackage(normal2);
			unique_ptr<Package> resultPtr = delivery.TakeOutBestPackage(perfect);
			Package result = *resultPtr;
			bool ifEqual = normal2 == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(normal2));
		}

		TEST_METHOD(TakeOutBestPackagePrio)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			HeavyPackage heavy("h1", 1, 2, 3);
			PriorityPackage prio2("p2", 5, 2);
			PriorityPackage perfect("p3", 5, 6);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			delivery.AddPackage(prio);
			delivery.AddPackage(prio);
			delivery.AddPackage(heavy);
			delivery.AddPackage(prio2);
			unique_ptr<PriorityPackage> resultPtr = delivery.TakeOutBestPackage(perfect);
			PriorityPackage result = *resultPtr;
			bool ifEqual = prio2 == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(prio2));

		}

		TEST_METHOD(TakeOutBestPackageHeavy)
		{
			Package normal("n1", 1, 2);
			PriorityPackage prio("p1", 1, 2);
			HeavyPackage heavy("h1", 1, 2, 3);
			HeavyPackage heavy2("h2", 5, 2, 7);
			HeavyPackage perfect("h3", 5, 6, 9);
			vector<unique_ptr<Package>> deliveryVector;
			Delivery delivery(move(deliveryVector));
			delivery.AddPackage(normal);
			delivery.AddPackage(prio);
			delivery.AddPackage(heavy);
			delivery.AddPackage(heavy2);
			unique_ptr<HeavyPackage> resultPtr = delivery.TakeOutBestPackage(perfect);
			HeavyPackage result = *resultPtr;
			bool ifEqual = heavy2 == result;
			Assert::AreEqual(true, ifEqual);
			Assert::AreEqual(false, delivery.IfInDelivery(heavy2));
		}

	};
	TEST_CLASS(DeliveryManagments)
	{
	public:
		TEST_METHOD(StringToInt)
		{
			string s = "1";
			DeliveryManagment manager;
			Assert::AreEqual(1, manager.StringToInt(s));
		}

		TEST_METHOD(StringToDouble)
		{
			string s = "1";
			DeliveryManagment manager;
			double d = 1.f;
			Assert::AreEqual(d, manager.StringToDouble(s));
		}

		TEST_METHOD(AddRowToDeliveryVector)
		{
			DeliveryManagment manager;
			vector<string> row = { "n1", "1", "2" };
			manager.AddRowToDeliveryVector(row);
			int size = manager.GetDeliveryVector().size();
			Assert::AreEqual(1, size);

		}

		TEST_METHOD(AddRowToDeliveryVectorMultiple)
		{
			DeliveryManagment manager;
			vector<string> row = { "n1", "1", "2" };
			vector<string> row2 = { "p1", "1", "2" };
			vector<string> row3 = { "h1", "1", "2", "3"};
			manager.AddRowToDeliveryVector(row);
			manager.AddRowToDeliveryVector(row2);
			manager.AddRowToDeliveryVector(row3);
			int size = manager.GetDeliveryVector().size();
			Assert::AreEqual(3, size);

		}
	};
} 
