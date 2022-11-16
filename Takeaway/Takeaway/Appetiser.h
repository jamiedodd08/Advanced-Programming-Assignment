#pragma once
#include "Item.h"

class Appetiser :
    public Item
{
private:
    bool shareable;
    bool twoForOne;
public:
    Appetiser(bool sharea, bool tForOne, std::string& nam, float pri, int cal);
    std::string toString();
    std::string type = "appetiser";
    std::string getType();
    bool get241();
};

