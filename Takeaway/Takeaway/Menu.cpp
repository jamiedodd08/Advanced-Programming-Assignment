#include "Menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Menu::Menu(std::string fileName)
{
	load(fileName);
}

//Function to load the menu from .csv file and create objects of the classes dependent on their type.
void Menu::load(std::string fileName)
{
	std::ifstream inFile(fileName);

	if (inFile.is_open())

	{
		std::string line;
		while (getline(inFile, line))
		{
			//Create new vector to store the words from the .csv seperately.
			std::vector <std::string> words;
			//Reading the file line by line.
			std::stringstream ss(line);
			//Token to take the words.
			std::string token;

			while (std::getline(ss, token, ','))
			{
				//Storing the words into the vector.
				words.push_back(token);
			}
			//Switch case to create an object dependent on the type stated in the .csv file.
			switch (line[0])
			{
			case 'a':
			{
				//Creates a new object and takes the correct parameters for the class constructor.
				items.push_back(new Appetiser(words[4] == "y", words[5] == "y", words[1], std::stof(words[2]), std::stoi(words[3])));
				break;
			}
			case 'm':
			{
				items.push_back(new MainCourse(words[1], std::stof(words[2]), std::stoi(words[3])));
				break;
			}
			case 'b':
			{
				items.push_back(new Beverage(std::stoi(words[6]), std::stof(words[7]), words[1], std::stof(words[2]), std::stoi(words[3])));
				break;
			}
			}
		}
	}
}

//Destructor to deallocate memory addresses of pointers from the vector of items.
Menu::~Menu()
{
	for (auto i : items)
	{
		delete i;
		items.clear();
	}
}

//Function to display the menu to the console.
std::string Menu::toString()
{
	int count = 0;
	int& rCount = count;
	std::string itemStr;

	itemStr += "----------------Appetisers---------------- \n";
	for (auto i : items)
	{
		//Using the getType function from the item class to display the correct header for the menu display.
		if (i->getType() == "appetiser")
		{
			//Adding to count each loop so the item number can be displayed along side the item in the menu.
			rCount++;
			itemStr += "(" + std::to_string(rCount) + ") " + i->toString() += "\n";
		}
	}

	itemStr += "----------------Main dishes---------------- \n";
	for (auto i : items)
	{
		if (i->getType() == "mainCourse")
		{
			rCount++;
			itemStr += "(" + std::to_string(rCount) + ") " + i->toString() += "\n";
		}
	}

	itemStr += "----------------Beverages---------------- \n";
	for (auto i : items)
	{
		if (i->getType() == "beverage")
		{
			rCount++;
			itemStr += "(" + std::to_string(rCount) + ") " + i->toString() += "\n";
		}
	}
	return itemStr;
}

//Function to get the items index, used when adding items to the order so the user gets the correct item.
Item* Menu::getItem(int index)
{
	return items[index - 1];
}

//Function to get the number of items in the vector, used when removing items from the order to stop the user from inputting a larger integer than the amount of items.
int Menu::getItemCount()
{
	int count = 0;
	for (auto i : items)
	{
		count++;
	}
	return count;
}

