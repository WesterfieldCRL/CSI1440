/**
 * file: proj4-ItemInfo.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 4 
 * due date: 10/03/2022
 *
 * date modified: 9/22/2022
 * - created file
 * 
 * date modified: 9/26/2022
 *  - finished implementing most of the functions
 * 
 * ItemInfo function implementation
 */

#include "proj4-ItemInfo.hpp"

void ItemInfo::setItemId(const char *num)
{
    this->itemId = atoi(num);
}
    
void ItemInfo::setDescription(const char *cstr)
{
    for (int i = 0; i < 40 || cstr[i] != '\0'; i++)
    {
        this->description[i] = cstr[i];
    }
}

void ItemInfo::setManCost(const char *num)
{
    this->manCost = atoi(num);
}

void ItemInfo::setSellPrice(const char *num)
{
    this->sellPrice = atoi(num);
}

int ItemInfo::getItemId()
{
    return this->itemId;
}

const char *ItemInfo::getDescription()
{
    return this->description;
}

double ItemInfo::getManCost()
{
    return this->manCost;
}

double ItemInfo::getSellPrice()
{
    return this->sellPrice;
}

void ItemInfo::toAmazonJSON(ostream &out)
{
    
}

void ItemInfo::displayItemInfo(ostream &out)
{

}

double ItemInfo::calcProfit()
{

}

double stuCstrToDbl(const char *num)
{

}

void stuDblToCstr(char *cstr, double num)
{

}

void stuCstrCpy(char *dest, const char *src)
{

}

int stuCstrLen(const char *src)
{

}

ostream& printCString(ostream &out, const char *src)
{
    
}
