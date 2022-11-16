#include "Appetiser.h"

Appetiser::Appetiser(bool sharea, bool tForO, std::string& nam, float pri, int cal) : Item(nam, pri, cal)
{
	shareable = sharea;
	twoForOne = tForO;
}

//Function to display the relevant information to a Appetiser item.
std::string Appetiser::toString()
{
	std::string appetiser = Item::toString();

	//If the item is shareable then add (shareable) to the string.
	if (shareable == true)
	{
		appetiser += "(shareable)";
	}
	//If the item is two for one then add (2-4-1) to the string.
	if (twoForOne == true)
	{
		appetiser += "(2-4-1)";
	}
	return appetiser;
}

//Function to get the type of the item. (appetiser)
std::string Appetiser::getType()
{
	return type;
}

//Function to get the bool twoForOne. Used in the calculateTotal function in Order.
bool Appetiser::get241()
{
	return twoForOne;
}
