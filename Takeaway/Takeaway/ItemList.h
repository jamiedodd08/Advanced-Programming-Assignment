#pragma once
#include <vector>
#include "Item.h"

class ItemList
{
private:

public:
	std::vector<Item*> items;
	virtual std::string toString() = 0;
	virtual int getItemCount() = 0;
};

