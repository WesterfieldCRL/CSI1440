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
    this->itemId = stuCstrToDbl(num);
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
    this->manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num)
{
    this->sellPrice = stuCstrToDbl(num);
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
    out.put('\t');
    out.put('\t');
    char temp[20] = "\"itemId\": \0";
    for (int i = 0; temp[i] != '\0'; i++)
    {
        out.put(temp[i]);
    }
    stuDblToCstr(temp,this->itemId);
}

void ItemInfo::displayItemInfo(ostream &out)
{

}

double ItemInfo::calcProfit()
{
    return -1;
}

double stuCstrToDbl(const char *num)
{
    double returnValue = 0;
    double decimalPart = 0;
    int decimalDivisor = 1;
    bool isNegative = false;
    bool isDecimal = false;
    int i = 0;
    if (num[0] == '-')
    {
        isNegative=true;
        i = 1;
    }
    while(num[i] != '\0')
    {
        if (isDecimal)
        {
            decimalPart *= 10;
            decimalPart += num[i] - '0';
            decimalDivisor *= 10;
        }
        else if (num[i] == '.')
        {
            isDecimal = true;
        }
        else if (!isDecimal)
        {
            returnValue*=10;
            returnValue+=num[i]-'0';
        }
        i++;
    }
    decimalPart/=decimalDivisor;
    returnValue += decimalPart;
    if (isNegative)
    {
        returnValue*=-1;
    }
    return returnValue;
}

void stuDblToCstr(char *cstr, double num)
{
    for (int i = 0; num > 0; i++)
    {
        //cstr[i] = 
    }
}

void stuCstrCpy(char *dest, const char *src)
{

}

int stuCstrLen(const char *src)
{
    return -1;
}

ostream& printCString(ostream &out, const char *src)
{
    return out;
}
