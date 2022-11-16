#pragma once
#include "Item.h"
class Beverage :
    public Item
{
private:
    int volume;
    float alcByVol;
public:
    Beverage(int vol, float abv, std::string& nam, float pri, int cal);
    std::string toString();
    std::string type = "beverage";
    std::string getType();
    virtual bool get241();
};

