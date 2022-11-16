#pragma once
#include "ItemList.h"
#include "Menu.h"
#include <fstream>

class Order :
    public ItemList
{
private:
    float total;
    float savings;
public:
    void calculateTotal();
    void printReceipt();
    std::string toString();
    void add(Item *choice);
    void remove(int index);
    int getItemCount();
};

