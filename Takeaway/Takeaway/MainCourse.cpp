#include "MainCourse.h"

MainCourse::MainCourse(std::string& nam, float pri, int cal) : Item (nam, pri, cal)
{

}

//Function to get the type of the item. (MainCourse)
std::string MainCourse::getType()
{
	return type;
}

bool MainCourse::get241()
{
	return 0;
}
