#pragma once
#include "Item.h"

class MainCourse :
    public Item
{
private:

public:
    MainCourse(std::string& nam, float pri, int cal);
    std::string type = "mainCourse";
    std::string getType();
    bool get241();
};

