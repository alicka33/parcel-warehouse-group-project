#pragma once
#include <vector>
#include "Packages.h"
#include "PriorityPackage.h"
#include "HeavyPackage.h"
#include "Exceptions.h"
#include <memory>
#include <algorithm>

using namespace std;

class Delivery
{
private:
	vector<unique_ptr<Package>> delivery;
public:
	Delivery(vector<unique_ptr<Package>> d) : delivery(move(d)) {};
	Delivery() {};
	vector<unique_ptr<Package>> const& GetDeliveryVector() const;

	template <typename T>
	bool IfInDelivery(const T& givenPackage);

	template <typename T>
	void AddPackage(const T& newPackage);

	template <typename T>
	void RemovePackage(const T& givenPackage);

	template <typename T>
	unique_ptr<T> TakeOutFirstPackage(const T& givenPackage);

	template <typename T>
	unique_ptr<T> TakeOutGivenPackage(const T& givenPackage);

	template <typename T>
	unique_ptr<T> TakeOutBestPackage(const T& perfectPackage);

};

/* Checks if package is in delivery */
template<typename T>
inline bool Delivery::IfInDelivery(const T& givenPackage)
{
	for (const auto& package : delivery) {
		if (auto derivedPackage = dynamic_cast<T*>(package.get())) {
			if (*derivedPackage == givenPackage)
			{
				return true;
			}
		}
	}
	return false;
}

/* Adds package to delivery */
template<typename T>
inline void Delivery::AddPackage(const T& newPackage)
{
	if (!IfInDelivery(newPackage))
		delivery.push_back(make_unique<T>(newPackage));
}


/* Removes package from delivery */
template<typename T>
inline void Delivery::RemovePackage(const T& givenPackage)
{
	if (IfInDelivery(givenPackage))
	{
		auto it = find_if(delivery.begin(), delivery.end(), [&](const std::unique_ptr<Package>& package) {
			return *package == givenPackage;
			});
		delivery.erase(it);
	}
	else
		throw PackageNotInDeliveryException();
}


/* Takes out first package of equal type from delivery (takes as an agrument the default constructor of Package of the given type */
template<typename T>
inline unique_ptr<T> Delivery::TakeOutFirstPackage(const T& givenPackage)
{
	unique_ptr<T> searchedPackage = nullptr;
	for (const auto& package : delivery)
	{
		if (auto derivedPackage = dynamic_cast<T*>(package.get())) {
			searchedPackage = make_unique<T>(*derivedPackage);
			RemovePackage(*derivedPackage);
			return searchedPackage;
		}
	}
	throw PackageNotInDeliveryException();
}


/* Takes out the given package from delivery */
template<typename T>
inline unique_ptr<T> Delivery::TakeOutGivenPackage(const T& givenPackage)
{

	unique_ptr<T> searchedPackage = nullptr;
	for (const auto& package : delivery) {
		if (auto derivedPackage = dynamic_cast<T*>(package.get())) {
			if (*derivedPackage == givenPackage)
			{
				searchedPackage = make_unique<T>(*derivedPackage);
				RemovePackage(*derivedPackage);
				return searchedPackage;
			}
		}
	}
	throw PackageNotInDeliveryException();
}


/* Takes out the best fitting (closest to perfect) package from delivery */
template<typename T>
inline unique_ptr<T> Delivery::TakeOutBestPackage(const T& perfectPackage)
{
	T bestPackage;
	unique_ptr<T> bestPackagePtr = make_unique<T>(bestPackage);
	for (const auto& package : delivery) {
		if (auto derivedPackage = dynamic_cast<T*>(package.get())) {
			if (*derivedPackage <= perfectPackage && *package > *bestPackagePtr)
			{
				bestPackagePtr = make_unique<T>(*derivedPackage);
			}
		}
	}
	RemovePackage(*bestPackagePtr);
	return bestPackagePtr;
}


