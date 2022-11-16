#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Item
{
private:

public:
	Item(std::string& nam, float pri, int cal);
	std::string name;
	int calories;
	float price;
	virtual std::string toString();
	virtual std::string getType() = 0;
	std::string getName();
	float getPrice();
	virtual bool get241() = 0;
};


