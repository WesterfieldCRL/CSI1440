/**
 * file: proj4-main.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 4
 * due date: 10/3/2022
 *
 * date modified: 10/1/2022
 * - created file
 * 
 * Main for Project 4
 */

#include <iostream>
#include <fstream>
#include "proj4-ItemInfo.hpp"

using namespace std;

int main() 
{
    char buffer[500];
    int itemsCapacity = 2;
    ItemInfo *items = new ItemInfo[itemsCapacity];
    ifstream file ("proj4-productServices.csv");
    int numOfItems = 0;
    int ndx = 0;
    int infoType = 0;

    while (file.get(buffer[ndx]))
    {
        if (buffer[ndx] == ','||buffer[ndx] == '\n')
        {
            buffer[ndx] = '\0';
            switch (infoType)
            {
                case 0:
                items[numOfItems].setItemId(buffer);
                ndx = 0;
                break;
                case 1:
                items[numOfItems].setDescription(buffer);
                ndx = 0;
                break;
                case 2:
                items[numOfItems].setManCost(buffer);
                ndx = 0;
                break;
                case 3:
                items[numOfItems].setSellPrice(buffer);
                ndx = 0;
                break;
                default:
                cout << "something went wrong in the switch statment" << endl;
                break;
            }   
        }
        if (buffer[ndx] == '\n')
        {
            numOfItems++;
            if (numOfItems == itemsCapacity)
            {
                itemsCapacity+=2;
                ItemInfo *temp = items;
                items = new ItemInfo[itemsCapacity];
                for (int i = 0; i < numOfItems; i++)
                {
                    items[i] = temp[i];
                }
                delete [] temp;
            }
        }

        ndx++;
    }

    for (int i = 0; i < numOfItems; i++)
    {
        items[i].displayItemInfo(cout);
    }

    

    return 0;   
}