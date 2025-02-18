#pragma once
#include <vector>
#include <string>
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/HeavyPackage.h"
#include "../PackagesLib/PriorityPackage.h"

class FieldAlreadyUsedException : public std::exception
{
public:
	std::string what();
};

class PackageNotFoundException : public std::exception
{
public:
	std::string what();
};

class IncorrectDataGiven : public std::exception
{
public:
	std::string what();
};

enum Type
{
	USABLE,
	UNUSABLE,
	ENFORCED,
};

struct Field
{
	int package = -1;
	Type type = USABLE;
	Field();
};

struct Pack_info
{
	int pack_id;
	char array_id;

	int top_left_x;
	int top_left_y;
	Pack_info(int pack, char array, int given_top_left_x, int given_top_left_y);
};

class Storage_unit : virtual public Package
{
private:
	Field** map;
	std::vector<Pack_info> list;

	std::vector<Package> memory_normal_package;
	std::vector<HeavyPackage> memory_heavy_package;
	std::vector<Storage_unit> memory_storing_package;
	std::vector<PriorityPackage> memory_priority_package;

public:
	Storage_unit(std::string path);
	Storage_unit(std::string package_type, std::ifstream& file);

	Storage_unit(std::string given_id, int x, int y);

	Field** Map();

	Package* Locate_package(Pack_info *pack_info);

	void Set_package(int top_left_x, int top_left_y, Package* package);
	void Set_package(int top_left_x, int top_left_y, HeavyPackage* package);
	void Set_package(int top_left_x, int top_left_y, Storage_unit* package);
	void Set_package(int top_left_x, int top_left_y, PriorityPackage* package);

	bool Is_area_free(int top_left_x, int top_left_y, int width, int length, std::string pack_id); //is priority on the border, is heavy on reinforced

	Pack_info* Seek_package_by_xy(int x, int y);

	void Remove_package_by_xy(int x, int y);

	void Simple_visualisation();

	void Save_file(std::string name);

	void Check_inside_storage_package(Pack_info* pack_info);
	void Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, Package* package);
	void Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, HeavyPackage* package);
	void Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, Storage_unit* package);
	void Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, PriorityPackage* package);


	virtual std::string Save_data();

	void Change_field_type(int top_left_x, int top_left_y, int width, int length, Type field_type);
};
