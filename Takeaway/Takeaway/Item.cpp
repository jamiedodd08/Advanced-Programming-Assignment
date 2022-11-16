#include "Item.h"
#include <iomanip>

Item::Item(std::string& nam, float pri, int cal)
{
	name = nam;
	calories = cal;
	price = pri;
}

//Function to display the item information to the console.
std::string Item::toString()
{
	std::stringstream ss;
	ss << name << ": \x9C" << std::setprecision(2) << std::fixed << price << ", " << calories << " cal ";
	return ss.str();	
}

//Function to get the name of the item.
std::string Item::getName()
{
	return name;
}

//Fucntion to get the price of the item. Used in the calculateTotal function in Order.
float Item::getPrice()
{
	return price;
}

