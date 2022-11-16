#include "Order.h"
#include <iomanip>
#include <algorithm>

//Function to add items into the vector.
void Order::add(Item* choice)
{
	items.push_back(choice);
	std::cout << choice->getName() << " added to your order!" << std::endl;
}

//Function to remove items from the vector.
void Order::remove(int index)
{
	std::cout << items[index - 1]->getName() << " removed from your order!" << std::endl;
	items.erase(items.begin() + index - 1);
}

//Function to calculate the total price of the order.
void Order::calculateTotal()
{
	int count = 0;
	int& rCount = count;
	total = 0;
	savings = 0;
	//Loop through the items in the order.
	for (auto i : items)
	{
		//If an item is 2-4-1 the add to the count of 2-4-1 items.
		if (i->get241() == true)
		{
			rCount++;
			//If there is 2 2-4-1 items then take away the price of the item and add the price to the savings.
			if (rCount == 2)
			{
				total -= i->getPrice();
				savings += i->getPrice();
				//Set 2-4-1 count back to zero.
				rCount = 0;
			}
		}
		//If the item is not 2-4-1 then add the price to the total.
		total += i->getPrice();
	}
}

//Function to display the order to the console.
std::string Order::toString()
{
	//Call calculateTotal function to work out the total price and savings of the order.
	calculateTotal();
	std::string orderStr;
	std::string input;
	int count = 0;

	std::stringstream ss;
	//Loop through the items in the order and add to the count so it can display the item index.
	for (auto i : items)
	{
		count++;
		ss << "(" << std::to_string(count) << ") " << i->toString() << "\n";
	}
	ss << "-------------\n";
	//If savings is not zero then add the correct information to the stringstream.
	if (savings != 0)
	{
		ss << "2-4-1 discount applied! Savings: \x9C" << std::setprecision(2) << std::fixed << savings << "\n";
	}
	ss << "Total: \x9C" << std::setprecision(2) << std::fixed << total << "\n\n";
	return ss.str();
}

//Function to write the receipt to a .txt file.
void Order::printReceipt()
{
	std::ofstream file("receipt");
	std::string receipt;
	//Call the order toString function the get the information for the receipt.
	receipt = toString();
	replace(receipt.begin(), receipt.end(), '\x9C', '£');
	file << receipt;
	file.close();
}

int Order::getItemCount()
{
	int count = 0;
	for (auto i : items)
	{
		count++;
	}
	return count;
}