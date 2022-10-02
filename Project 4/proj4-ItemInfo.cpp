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
    //creating char arrays so I dont have to write a million out.put's
    char start[14] = "{\n\t\"itemId\": ";
    char descrip[20] = ",\n\t\"description\": \"";
    char manP[17] = "\",\n\t\"manPrice\": ";
    char sellP[17] = ",\n\t\"sellPrice\": ";
    //just using the already made functions to output and do the work
    printCString(out,start);
    stuDblToCstr(start,this->itemId);
    printCString(out,start);
    printCString(out,descrip);
    printCString(out,this->description);
    printCString(out,manP);
    stuDblToCstr(start,this->manCost);
    printCString(out,start);
    printCString(out,sellP);
    stuDblToCstr(start,this->sellPrice);
    printCString(out,start);
    out.put('\n');
    out.put('}');
    out.put('\n');
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
    //loops through the nonDecimal part adding each number
    //if/when it gets to a decimal, changes how its being processed
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
    int nonDecimal = num;
    int ndx;
    char tempArray[500];
    int isDecimal = 0;
    bool isNegative = false;
    if (num < 0)
    {
        isNegative=true;
        nonDecimal*=-1;
        num *= -1;
    }
    for (ndx = 0; nonDecimal > 0; ndx++)
    {
        tempArray[ndx] = nonDecimal%10 + '0';
        nonDecimal/=10;
    }

    for (int i = 0; i < ndx; i++)
    {

        cstr[i] = tempArray[ndx-i-1];
    }
    //because of the way floating point values are stored
    //Ex: 2.3 actually is stored as 2.2999999999998
    //so I am just pulling two decimal points out
    //because you cannot get all decimal points out with 100% accuracy
    //or, if there is a way I could not find it

    //add decimal place
    cstr[ndx] = '.';
    ndx++;
    //loops twice
    for (int i = 0; i < 2; i++)
    {
        //removes everything but the decimals
        nonDecimal = num;
        num -= nonDecimal;
        //extracting first decimal point
        num *= 10;
        nonDecimal = num;
        if (nonDecimal != 0)
        {
            cstr[ndx] = nonDecimal + '0';
            num -= nonDecimal;
            ndx++;
        }
        else
        {
            isDecimal++;
        }
    }

    //if there where no decimal points on the end
    //overwrite the . with the \0
    if (isDecimal >= 2)
    {
        ndx--;
    }

    cstr[ndx] = '\0';
    
    //if negative, move everything up by one and add a negative sign
    if (isNegative)
    {
        for (int i = ndx; i >= 0; i--)
        {
            cstr[i+1] = cstr[i];
        }
        cstr[0] = '-';
    }
    else if(ndx == 0)
    {
        cstr[0] = '0';
        cstr[1] = '\0';
    }

}

void stuCstrCpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int stuCstrLen(const char *src)
{
    int length = 0;
    for (int i = 0; src[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

ostream& printCString(ostream &out, const char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
    {
        out.put(src[i]);
    }
    return out;
}
