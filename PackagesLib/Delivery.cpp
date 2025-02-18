#include "pch.h"
#include "framework.h"
#include "Delivery.h"
#include <iostream>


vector<unique_ptr<Package>> const& Delivery::GetDeliveryVector() const
{
	return delivery;
}
