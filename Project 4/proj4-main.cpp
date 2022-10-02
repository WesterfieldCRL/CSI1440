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

    //gets data from csv and puts it in items
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
                    infoType++;
                break;
                case 1:
                    items[numOfItems].setDescription(buffer);
                    ndx = 0;
                    infoType++;
                break;
                case 2:
                    items[numOfItems].setManCost(buffer);
                    ndx = 0;
                    infoType++;
                break;
                case 3:
                    items[numOfItems].setSellPrice(buffer);
                    ndx = 0;
                    infoType = 0;
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
                break;
                default:
                    cout << "something went wrong in the switch statment" << endl;
                break;
            }
        }
        else
        {
            ndx++;
        }
    }
    //if there was no newline char before the end of file
    //this will make sure that this accounts for that
    if (infoType == 3)
    {
        buffer[ndx] = '\0';
        items[numOfItems].setSellPrice(buffer);
        ndx = 0;
        infoType = 0;
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

    //sorts by profit
    for (int i = 0; i < numOfItems-1; i++)
    {
        if (items[i].getSellPrice()-items[i].getManCost() < items[i+1].getSellPrice()-items[i+1].getManCost())
        {
            ItemInfo temp = items[i+1];
            items[i+1] = items[i];
            items[i] = temp;
        }
    }

    //outputs json format to screen
    cout.put('"');
    cout.put('W');
    cout.put('e');
    cout.put('s');
    cout.put('l');
    cout.put('e');
    cout.put('y');
    cout.put('S');
    cout.put('t');
    cout.put('o');
    cout.put('r');
    cout.put('e');
    cout.put('"');
    cout.put(':');
    cout.put(' ');
    cout.put('[');   
    for (int i = 0; i < numOfItems; i++)
    {
        cout.put('\n');
        cout.put('\t');
        cout.put('"');
        cout.put('I');
        cout.put('t');
        cout.put('e');
        cout.put('m');
        cout.put(' ');
        cout.put('#');
        cout.put((i+1)+'0');
        cout.put('"');
        cout.put(' ');
        items[i].toAmazonJSON(cout);
        if (i <numOfItems - 1)
        {
            cout.put(',');
        }
    }
    cout.put('\n');
    cout.put(']');
    
    delete [] items;

    return 0;   
}