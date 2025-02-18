#include "storage.h"
#include <iostream>
#include <fstream>
#include <sstream>

Field::Field()
{
	package = -1;
	type = USABLE;
}

Pack_info::Pack_info(int pack, char array, int given_top_left_x, int given_top_left_y)
{
	pack_id = pack;
	array_id = array;
	top_left_x = given_top_left_x;
	top_left_y = given_top_left_y;
}


Storage_unit::Storage_unit(std::string path)
{
	//wymiary planszy
	//rodzaj pól
	//lokalizacja i dane o paczkach

	std::ifstream file(path);

	struct stat info;

	if (stat("save_files", &info) != 0)
	{
		throw IncorrectDataGiven();
	}

	file >> id;
	file >> length;
	file >> width;

	map = new Field * [width];

	for (int i = 0; i < width; i++)
	{
		map[i] = new Field[length];
	}

	// set map
	int type;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < length; y++)
		{
			file >> type;
			map[x][y].type = (Type)type;
		}
	}
	//
	int packages_amount;
	int t_l_x;
	int t_l_y;
	file >> packages_amount;
	std::string package_type;

	for (int i = 0; i < packages_amount; i++)
	{
		file >> t_l_x;
		file >> t_l_y;
		file >> package_type;
		if (package_type[0] == 'h')
		{
			HeavyPackage current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else if (package_type[0] == 'S')
		{
			Storage_unit current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else if (package_type[0] == 'p')
		{
			PriorityPackage current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else //if (package_type == 'n')
		{
			Package current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
	}
	file.close();
}

Storage_unit::Storage_unit(std::string pack_id, std::ifstream& file)
{
	id = pack_id;
	file >> length;
	file >> width;

	map = new Field * [width];

	for (int i = 0; i < width; i++)
	{
		map[i] = new Field[length];
	}

	// set map
	int type;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < length; y++)
		{
			file >> type;
			map[x][y].type = (Type)type;
		}
	}
	//
	int packages_amount;
	int t_l_x;
	int t_l_y;
	file >> packages_amount;
	std::string package_type;

	for (int i = 0; i < packages_amount; i++)
	{
		file >> t_l_x;
		file >> t_l_y;
		file >> package_type;
		if (package_type[0] == 'h')
		{
			HeavyPackage current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else if (package_type[0] == 'S')
		{
			Storage_unit current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else if (package_type[0] == 'p')
		{
			PriorityPackage current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}
		else //if (package_type[0] == 'n')
		{
			Package current_pack(package_type, file);
			Set_package(t_l_x, t_l_y, &current_pack);
		}

	}
}

Storage_unit::Storage_unit(std::string given_id, int x, int y)
{
	id = given_id;
	length = x;
	width = y;
	map = new Field * [x];

	for (int i = 0; i < x; i++)
	{
		map[i] = new Field[y];
	}
}


Field** Storage_unit::Map()
{
	return map;
}

void Storage_unit::Set_package(int top_left_x, int top_left_y, Package* package)
{
	if (package->GetId()[0] != 'n')
	{
		throw IncorrectDataGiven();
	}

	if (!Is_area_free(top_left_x, top_left_y, package->GetWidth(), package->GetLength(), package->GetId()))
	{
		throw FieldAlreadyUsedException();
	}
	memory_normal_package.push_back(*package);
	list.push_back(Pack_info(memory_normal_package.size() - 1, package->GetId()[0], top_left_x, top_left_y));

	for (int x = top_left_x; x < top_left_x + package->GetWidth(); x++)
	{
		for (int y = top_left_y; y < top_left_y + package->GetLength(); y++)
		{
			map[x][y].package = list.size() - 1;
		}
	}
}

void Storage_unit::Set_package(int top_left_x, int top_left_y, HeavyPackage* package)
{
	if (package->GetId()[0] != 'h')
	{
		throw IncorrectDataGiven();
	}

	if (!Is_area_free(top_left_x, top_left_y, package->GetWidth(), package->GetLength(), package->GetId()))
	{
		throw FieldAlreadyUsedException();
	}
	memory_heavy_package.push_back(*package);
	list.push_back(Pack_info(memory_heavy_package.size() - 1, package->GetId()[0], top_left_x, top_left_y));

	for (int y = top_left_y; y < top_left_y + package->GetLength(); y++)
	{
		for (int x = top_left_x; x < top_left_x + package->GetWidth(); x++)
		{
			map[x][y].package = list.size() - 1;
		}
	}
}

void Storage_unit::Set_package(int top_left_x, int top_left_y, Storage_unit* package)
{
	if (package->GetId()[0] != 'S')
	{
		throw IncorrectDataGiven();
	}
	if (!Is_area_free(top_left_x, top_left_y, package->GetWidth(), package->GetLength(), package->GetId()))
	{
		throw FieldAlreadyUsedException();
	}
	memory_storing_package.push_back(*package);
	list.push_back(Pack_info(memory_storing_package.size() - 1, package->GetId()[0], top_left_x, top_left_y));

	for (int y = top_left_y; y < top_left_y + package->GetLength(); y++)
	{
		for (int x = top_left_x; x < top_left_x + package->GetWidth(); x++)
		{
			map[x][y].package = list.size() - 1;
		}
	}
}

void Storage_unit::Set_package(int top_left_x, int top_left_y, PriorityPackage* package)
{
	if (package->GetId()[0] != 'p')
	{
		throw IncorrectDataGiven();
	}
	if (!Is_area_free(top_left_x, top_left_y, package->GetWidth(), package->GetLength(), package->GetId()))
	{
		throw FieldAlreadyUsedException();
	}
	memory_priority_package.push_back(*package);
	list.push_back(Pack_info(memory_priority_package.size() - 1, package->GetId()[0], top_left_x, top_left_y));

	for (int y = top_left_y; y < top_left_y + package->GetLength(); y++)
	{
		for (int x = top_left_x; x < top_left_x + package->GetWidth(); x++)
		{
			map[x][y].package = list.size() - 1;
		}
	}
}

bool Storage_unit::Is_area_free(int top_left_x, int top_left_y, int given_width, int given_length, std::string pack_id)
{
	if (top_left_x + given_width > width || top_left_y + given_length > length)
	{
		return false;
	}

	for (int y = top_left_y; y < top_left_y + given_length; y++)
	{
		for (int x = top_left_x; x < top_left_x + given_width; x++)
		{
			if (map[x][y].package != -1 || 
				map[x][y].type == UNUSABLE ||
				((pack_id[0] == 'h' || pack_id[0] == 'S') && map[x][y].type != ENFORCED))
			{
				return false;
			}
		}
	}
	if (pack_id[0] == 'p')
	{
		if (!(top_left_x == 0 ||
			top_left_y == 0 ||
			top_left_x + given_width == width ||
			top_left_y + given_length == length
			))
		{
			return false;
		}
	}
	return true;
}

void Storage_unit::Simple_visualisation()
{
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[x][y].package != -1)
			{
				std::cout << Locate_package(&list[map[x][y].package])->GetId() << "\t";
			}
			else
			{
				std::cout << "O" << "\t";
			}
		}
		std::cout << "\n";
	}
}

Pack_info* Storage_unit::Seek_package_by_xy(int x, int y)
{
	//pinpoint any point of the package

	for (int i = 0; i < list.size(); i++)
	{
		if (&list[i] == &list[map[x][y].package])
		{
			return &list[i];
		}
	}
	throw PackageNotFoundException();
}

void Storage_unit::Remove_package_by_xy(int x, int y)
{
	Pack_info* pack = Seek_package_by_xy(x, y);
	int width = -1;
	int length = -1;

	if (pack->array_id == 'S')
	{
		width = memory_storing_package[pack->pack_id].GetWidth();
		length = memory_storing_package[pack->pack_id].GetLength();
		memory_storing_package.erase(memory_storing_package.begin() + pack->pack_id);
	}
	else if (pack->array_id == 'h')
	{
		width = memory_heavy_package[pack->pack_id].GetWidth();
		length = memory_heavy_package[pack->pack_id].GetLength();
		memory_heavy_package.erase(memory_heavy_package.begin() + pack->pack_id);
	}
	else if (pack->array_id == 'n')
	{
		width = memory_normal_package[pack->pack_id].GetWidth();
		length = memory_normal_package[pack->pack_id].GetLength();
		memory_normal_package.erase(memory_normal_package.begin() + pack->pack_id);
	}
	else if (pack->array_id == 'p')
	{
		width = memory_priority_package[pack->pack_id].GetWidth();
		length = memory_priority_package[pack->pack_id].GetLength();
		memory_priority_package.erase(memory_priority_package.begin() + pack->pack_id);
	}
	else
	{
		throw PackageNotFoundException();
	}

	for (int y = pack->top_left_y; y < length + pack->top_left_y; y++)
	{
		for (int x = pack->top_left_x; x < width + pack->top_left_x; x++)
		{
			map[x][y].package = -1;
		}
	}

	for (int i = 0; i < list.size(); i++)
	{
		if (&pack->pack_id == &list[i].pack_id)
		{
			list.erase(list.begin() + i);
		}
	}
}


void Storage_unit::Save_file(std::string name)
{
	struct stat info;

	if (stat("save_files", &info) != 0)
	{
		system("mkdir save_files");
	}
	std::ofstream file("save_files/" + name + "_save_file.txt");

	//dane Paczki
	//rodzaj paczek w œrodku
	//dane paczek

	file << Save_data();


	file.close();
}

std::string Storage_unit::Save_data()
{
	std::stringstream anwser;

	anwser << id;
	anwser << " ";
	anwser << width;
	anwser << " ";
	anwser << length << "\n";

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			anwser << map[x][y].type << " ";
		}
		anwser << "\n";
	}

	anwser << "\n" << list.size() << "\n\n";

	for (Pack_info x : list)
	{
		anwser << x.top_left_x << " ";
		anwser << x.top_left_y << " ";
		anwser << Locate_package(&x)->Save_data() << "\n" << "\n";

	}

	return(anwser.str());

}

Package* Storage_unit::Locate_package(Pack_info* pack_info)
{
	if (pack_info->array_id == 'S')
	{
		return &memory_storing_package[pack_info->pack_id];
	}
	else if (pack_info->array_id == 'h')
	{
		return &memory_heavy_package[pack_info->pack_id];
	}
	else if (pack_info->array_id == 'n')
	{
		return &memory_normal_package[pack_info->pack_id];
	}
	else if (pack_info->array_id == 'p')
	{
		return &memory_priority_package[pack_info->pack_id];
	}
	else
	{
		throw PackageNotFoundException();
	}
}


void Storage_unit::Check_inside_storage_package(Pack_info* pack_info)
{
	if (pack_info->array_id != 'S')
	{
		throw IncorrectDataGiven();
	}
	memory_storing_package[pack_info->pack_id].Simple_visualisation();
}

void Storage_unit::Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, Package* package)
{
	if (pack_info->array_id != 'S')
	{
		throw IncorrectDataGiven();
	}
	memory_storing_package[pack_info->pack_id].Set_package(top_left_x, top_left_y, package);
}
void Storage_unit::Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, HeavyPackage* package)
{
	if (pack_info->array_id != 'S')
	{
		throw IncorrectDataGiven();
	}
	memory_storing_package[pack_info->pack_id].Set_package(top_left_x, top_left_y, package);
}

void Storage_unit::Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, Storage_unit* package)
{
	if (pack_info->array_id != 'S')
	{
		throw IncorrectDataGiven();
	}
	memory_storing_package[pack_info->pack_id].Set_package(top_left_x, top_left_y, package);
}

void Storage_unit::Set_package_inside_storage_package(Pack_info* pack_info, int top_left_x, int top_left_y, PriorityPackage* package)
{
	if (pack_info->array_id != 'S')
	{
		throw IncorrectDataGiven();
	}
	memory_storing_package[pack_info->pack_id].Set_package(top_left_x, top_left_y, package);
}

void Storage_unit::Change_field_type(int top_left_x, int top_left_y, int width, int length, Type field_type)
{
	for (int y = top_left_y; y < length + top_left_y; y++)
	{
		for (int x = top_left_x; x < width + top_left_x; x++)
		{
			map[x][y].type = field_type;
		}
	}
}