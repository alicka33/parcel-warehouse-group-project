#include "pch.h"
#include "CppUnitTest.h"

#include "../StorageUnitLib/storage.cpp"
#include "../PackagesLib/Packages.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace storage_tests
{
	TEST_CLASS(initialization_related)
	{
	public:
		TEST_METHOD(initialization)
		{
			Storage_unit magazyn("S1", 10, 10);
		}
		TEST_METHOD(initialization_with_path)
		{
			Storage_unit magazyn("..\StorageUnitLib\save_files\zapis_save_file.txt");
		}

		TEST_METHOD(incorrect_adding_normal_packages)
		{
			Assert::ExpectException<FieldAlreadyUsedException>([]() {
				Package p1("n1", 1, 1);
				Package p2("n2", 1, 1);
				Storage_unit magazyn("S1", 10, 10);
				magazyn.Set_package(0, 0, &p1);
				magazyn.Set_package(0, 0, &p2);
				});
		}
		TEST_METHOD(adding_normal_packages)
		{
			Package p1("n1", 1, 1);
			Storage_unit magazyn("S1", 10, 10);
			magazyn.Set_package(0, 0, &p1);
			Assert::AreEqual(magazyn.Map()[0][0].package, 0);
			Assert::AreEqual(magazyn.Map()[1][0].package, -1);
		}
		TEST_METHOD(incorrect_adding_heavy_packages)
		{
			Assert::ExpectException<FieldAlreadyUsedException>([]() {
				HeavyPackage p1("h1", 1, 1, 8);
				Storage_unit magazyn("S1", 10, 10);
				magazyn.Set_package(0, 0, &p1);
			});
		}
		TEST_METHOD(adding_heavy_packages)
		{
			HeavyPackage p1("h1", 1, 1, 8);
			Storage_unit magazyn("S1", 10, 10);
			magazyn.Change_field_type(0, 0, 10, 10, ENFORCED);
			magazyn.Set_package(0, 0, &p1);
			Assert::AreEqual(magazyn.Map()[0][0].package, 0);
			Assert::AreEqual(magazyn.Map()[1][0].package, -1);
		}

		TEST_METHOD(incorrect_adding_priority_packages)
		{
			Assert::ExpectException<FieldAlreadyUsedException>([]() {
				PriorityPackage p1("p1", 1, 1);
				Storage_unit magazyn("S1", 10, 10);
				magazyn.Set_package(2, 2, &p1);
				});
		}

		TEST_METHOD(adding_priority_packages)
		{
			PriorityPackage p1("p1", 1, 1);
			Storage_unit magazyn("S1", 10, 10);
			magazyn.Set_package(0, 0, &p1);
			Assert::AreEqual(magazyn.Map()[0][0].package, 0);
			Assert::AreEqual(magazyn.Map()[1][0].package, -1);
		}

		TEST_METHOD(incorrect_adding_Storage_packages)
		{
			Assert::ExpectException<FieldAlreadyUsedException>([]() {
				Storage_unit p1("S1", 1, 1);
				Storage_unit magazyn("S1", 10, 10);
				magazyn.Set_package(0, 0, &p1);
				});
		}
		TEST_METHOD(adding_Storage_packages)
		{
			Storage_unit p1("S1", 1, 1);
			Storage_unit magazyn("S2", 10, 10);
			magazyn.Change_field_type(0, 0, 10, 10, ENFORCED);
			magazyn.Set_package(0, 0, &p1);
			Assert::AreEqual(magazyn.Map()[0][0].package, 0);
			Assert::AreEqual(magazyn.Map()[1][0].package, -1);
		}
		TEST_METHOD(adding_packages_to_Storage_packages)
		{
			Storage_unit p1("S1", 1, 1);
			Storage_unit magazyn("S2", 10, 10);
			Package p2("n1", 1, 1);

			magazyn.Change_field_type(0, 0, 10, 10, ENFORCED);
			magazyn.Set_package(0, 0, &p1);
			Pack_info* info = magazyn.Seek_package_by_xy(0, 0);
			magazyn.Set_package_inside_storage_package(info, 0, 0, &p2);
		}
		TEST_METHOD(removing_package)
		{
			Package p1("n1", 2, 2);
			Storage_unit magazyn("S1", 10, 10);
			magazyn.Set_package(0, 0, &p1);
			Assert::AreEqual(magazyn.Map()[0][0].package, 0);
			magazyn.Remove_package_by_xy(1, 0);
			Assert::AreEqual(magazyn.Map()[0][0].package, -1);
		}
		TEST_METHOD(saving)
		{
			Storage_unit p1("S1", 1, 1);
			Storage_unit magazyn("S2", 10, 10);
			Package p2("n1", 1, 1);

			magazyn.Change_field_type(0, 0, 10, 10, ENFORCED);
			magazyn.Set_package(0, 0, &p1);
			Pack_info* info = magazyn.Seek_package_by_xy(0, 0);
			magazyn.Set_package_inside_storage_package(info, 0, 0, &p2);
			magazyn.Save_file("test_data.txt");
		}
	};
}