#include "Beverage.h"

Beverage::Beverage(int vol, float abv, std::string& nam, float pri, int cal) : Item(nam, pri, cal)
{
	volume = vol;
	alcByVol = abv;
}

//Function to display the relevant information to a beverage item.
std::string Beverage::toString()
{
	std::string beverage = Item::toString();
	//Putting alByVol into a stringstream so the function can display the alcByVol float in the string.
	std::stringstream ss;
	ss << alcByVol;
	std::string abv(ss.str());

	//If alcByVol is zero then do not add abv to the string.
	if (alcByVol == 0)
	{
		beverage += "(" + std::to_string(volume) + "ml)";
	}
	else
	{
		beverage += "(" + std::to_string(volume) + "ml, " + abv +  "% abv)";
	}
	return beverage;
}

//Function to get the type of the item. (beverage)
std::string Beverage::getType()
{
	return type;
}

bool Beverage::get241()
{
	return 0;
}