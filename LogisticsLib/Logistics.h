#pragma once
#include "../StorageUnitLib/storage.h"
#include "../PackagesLib/Packages.h"
#include "../PackagesLib/Delivery.h"


using namespace std;

class PlacementStrategy {
public:
	virtual void placePackages(Storage_unit* storage, Delivery* delivery) = 0;
	virtual ~PlacementStrategy() {}
};

class RandomPlacement : public PlacementStrategy {
public:
	void placePackage(Storage_unit* storage, Delivery* delivery, Package package) {
		int x = rand() % storage->GetWidth();
		int y = rand() % storage->GetLength();
		storage->Set_package(x, y, &package);
	}

	void placePackage(Storage_unit* storage, Delivery* delivery, HeavyPackage package) {
		int x = rand() % storage->GetWidth();
		int y = rand() % storage->GetLength();
		storage->Set_package(x, y, &package);
	}

	void placePackage(Storage_unit* storage, Delivery* delivery, PriorityPackage package) {
		int x = rand() % storage->GetWidth();
		int y = rand() % storage->GetLength();
		if (x == 0 || y == 0 || x == storage->GetWidth() - package.GetWidth() || y == storage->GetLength() - package.GetLength()) {
			storage->Set_package(x, y, &package);
		}
		throw FieldAlreadyUsedException();
	}

	void placePackages(Storage_unit* storage, Delivery* delivery) {
		while (!delivery->GetDeliveryVector().empty()) {
			try {
				PriorityPackage p;
				unique_ptr<PriorityPackage> package(move(delivery->TakeOutFirstPackage(p)));
				this->placePackage(storage, delivery, *package);
			}
			catch (PackageNotInDeliveryException) {
				try {
					HeavyPackage p;
					unique_ptr<HeavyPackage> package(move(delivery->TakeOutFirstPackage(p)));
					this->placePackage(storage, delivery, *package);
				}
				catch (PackageNotInDeliveryException) {
					try {
						Package p;
						unique_ptr<Package> package(move(delivery->TakeOutFirstPackage(p)));
						this->placePackage(storage, delivery, *package);
					}
					catch (PackageNotInDeliveryException) {
						return;
					}
				}
			}
		}
	}
};

class TightPlacement : public PlacementStrategy {
	void placePackage(Storage_unit* storage, Delivery* delivery, Package package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				try {
					storage->Set_package(i, j, &package);
					return;
				}
				catch (FieldAlreadyUsedException) {
					continue;
				}
			}
		}
	}

	void placePackage(Storage_unit* storage, Delivery* delivery, HeavyPackage package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				try {
					storage->Set_package(i, j, &package);
					return;
				}
				catch (FieldAlreadyUsedException) {
					continue;
				}
			}
		}
	}
	
	void placePackage(Storage_unit* storage, Delivery* delivery, PriorityPackage package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				if (i == 0 || j == 0 || i == storage->GetWidth() - package.GetWidth() || j == storage->GetLength() - package.GetLength()) {
					try {
						storage->Set_package(i, j, &package);
						return;
					}
					catch (FieldAlreadyUsedException) {
						continue;
					}
				}
			}
		}
	}

	void placePackages(Storage_unit* storage, Delivery* delivery) {
		while (!delivery->GetDeliveryVector().empty()) {
			try {
				PriorityPackage p;
				unique_ptr<PriorityPackage> package(move(delivery->TakeOutFirstPackage(p)));
				this->placePackage(storage, delivery, *package);
			}
			catch (PackageNotInDeliveryException) {
				try {
					HeavyPackage p;
					unique_ptr<HeavyPackage> package(move(delivery->TakeOutFirstPackage(p)));
					this->placePackage(storage, delivery, *package);
				}
				catch (PackageNotInDeliveryException) {
					try {
						Package p;
						unique_ptr<Package> package(move(delivery->TakeOutFirstPackage(p)));
						this->placePackage(storage, delivery, *package);
					}
					catch (PackageNotInDeliveryException) {
						return;
					}
				}
			}
		}
	}
};

class FillPlacement : public PlacementStrategy {
	void placePackages(Storage_unit* storage, Delivery* delivery) {
		while (!delivery->GetDeliveryVector().empty()) {
			try {
				PriorityPackage p;
				unique_ptr<PriorityPackage> package(move(delivery->TakeOutFirstPackage(p)));
				this->placePackage(storage, delivery, *package);
			}
			catch (PackageNotInDeliveryException) {
				try {
					HeavyPackage p;
					unique_ptr<HeavyPackage> package(move(delivery->TakeOutFirstPackage(p)));
					this->placePackage(storage, delivery, *package);
				}
				catch (PackageNotInDeliveryException) {
					try {
						Package p;
						unique_ptr<Package> package(move(delivery->TakeOutFirstPackage(p)));
						this->placePackage(storage, delivery, *package);
					}
					catch (PackageNotInDeliveryException) {
						return;
					}
				}
			}
		}
	}
	void placePackage(Storage_unit* storage, Delivery* delivery, Package package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				try {
					storage->Set_package(i, j, &package);
					return;
				}
				catch (FieldAlreadyUsedException) {
					continue;
				}
			}
		}
	}

	void placePackage(Storage_unit* storage, Delivery* delivery, HeavyPackage package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				try {
					storage->Set_package(i, j, &package);
					return;
				}
				catch (FieldAlreadyUsedException) {
					continue;
				}
			}
		}
	}

	void placePackage(Storage_unit* storage, Delivery* delivery, PriorityPackage package) {
		for (int i = 0; i < storage->GetWidth(); i++) {
			for (int j = 0; j < storage->GetLength(); j++) {
				if (i == 0 || j == 0 || i == storage->GetWidth() - package.GetWidth() || j == storage->GetLength() - package.GetLength()) {
					try {
						storage->Set_package(i, j, &package);
						return;
					}
					catch (FieldAlreadyUsedException) {
						continue;
					}
				}
			}
		}
	}
};


class Logistics
{
private:
	std::unique_ptr<PlacementStrategy> strat{};
public:
	explicit Logistics() {};

	void setStrategy(std::unique_ptr<PlacementStrategy> strat_) {
		strat = std::move(strat_);
	}
	void unpackDelivery(Storage_unit* storage, Delivery* delivery) const
	{
		strat->placePackages(storage, delivery);
	}
};

