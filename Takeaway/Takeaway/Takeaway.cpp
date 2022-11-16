#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> 

#include "Menu.h"
#include "Order.h"
#include "Item.h"


using namespace std;

int main()
{
	system("Color 4");
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}
		//Show invalid input if user presses the enter key.
		if (parameters.empty())
		{
			cout << "Invalid input" << endl;
		}
		else
		{
			string command = parameters[0];
			//Call menu's toString function to display the menu.
			if (command.compare("menu") == 0) {
				cout << menu.toString();
			}

			else if (command.compare("add") == 0)
			{
				Item* choice;
				//Sets count to the number of items in the vector using the getItemCount function in the menu class.
				int count = menu.getItemCount();
				//Allow user to add multiple items to the order in the same command.
				for (int i = 1; i < parameters.size(); i++)
				{
					try
					{
						//Stops the user from inputting an invalid integer.
						if (stoi(parameters[i]) <= 0 || stoi(parameters[i]) > count) {
							cout << "Invalid input" << endl;
						}
						else {
							//Sets the choice pointer to the item's position in the vector corresponding to the users input.
							choice = menu.getItem(stoi(parameters[i]));
							order.add(choice);
						}
					}
					//Stops the user from inputting anything other than a integer.
					catch (exception& err)
					{
						cout << "invalid input\n";
					}
				}
			}

			else if (command.compare("remove") == 0)
			{
				//Creating a new vector of integers to store the items in the order.
				vector<int> rItems;
				int count = order.getItemCount();

				for (int i = 1; i < parameters.size(); i++)
				{
					try {
						//Stop user from inputting an invalid integer.
						if (stoi(parameters[i]) <= 0 || stoi(parameters[i]) > count)
						{
							cout << "Invalid input" << endl;
						}
						else
						{
							rItems.push_back(stoi(parameters[i]));
						}
					}
					catch (exception& err)
					{
						cout << "invalid input\n";
					}
				}
				//Reverse the vector from beginning to end.
				sort(rItems.rbegin(), rItems.rend());
				//Loop so that the user can remove multiple items from the order in the same command.
				for (int i = 0; i < rItems.size(); i++)
				{
					order.remove(rItems[i]);
				}
			}

			else if (command.compare("checkout") == 0)
			{
				cout << "===== Checkout =====\n";
				cout << order.toString();
				cout << "Do you want to place your order?\n"
					"Type 'y' to confirm, or 'n' to go back and modify it.\n";

				char input;
				cin >> input;
				//Precautions so that the user inputs the correct data type the program asks for.
				try {
					if (input == 'n' || input == 'N')
					{
						//Allows the user to add or remove more items from their order.
						cout << "Please amend order" << endl;
					}
					else if (input == 'y' || input == 'Y')
					{
						//Prints receipt using the function from the order class and terminates the program gracefully.
						order.printReceipt();
						cout << "Your receipt has been printed. Thank you." << endl;
						break;
					}
					else
					{
						cout << "invalid input" << endl;
						continue;
					}
				}
				catch (exception& err)
				{
					cout << "invalid input\n";
				}
				cin.ignore();
			}

			else if (command.compare("help") == 0)
			{
				cout << "-----Available Commands-----\n"
					"Menu - Display the menu\n"
					"Add - Add an item to order\n"
					"Remove - Remove an item from order\n"
					"Checkout - Display checkout\n";
			}
			else
			{
			cout << "invalid input" << endl;
			}
			parameters.clear();
		}
	}
	cout << "Press any key to quit..." << endl;
	std::getchar();

}