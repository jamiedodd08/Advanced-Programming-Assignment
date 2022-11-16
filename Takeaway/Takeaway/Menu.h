#pragma once
#include "ItemList.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

class Menu :
	public ItemList
{
private:

public:
	Menu(std::string fileName);
	~Menu();
	void load(std::string fileName);
	std::string toString();
	Item* getItem(int index);
	int getItemCount();
};

