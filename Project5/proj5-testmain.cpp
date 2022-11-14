/**
 * file: proj5-testmain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/15/2022
 * - created file
 * 
 * Test main
 */

#include <iostream>
#include "proj5-BUAthleteList.hpp"

using namespace std;

int main() 
{
    srand(time(0));

    BUAthleteList list;

    //creating the list
    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%10;
        list.addNCAAAthlete(temp,"temp","temp","temp");
    }

    cout << "testing sort by ID" << endl;

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getID() << " ";
    }

    cout << endl;

    list.sortByID();

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getID() << " ";
    }
    cout << endl;

    cout << "testing sort by Position" << endl;


    for (int i = 0; i < 13; i++)
    {
        int temp = rand()%11;
        switch (temp)
        {
        case 0:
            list[i].setPosition(OL);
            break;
        case 1:
            list[i].setPosition(QB);
            break;
        case 2:
            list[i].setPosition(RB);
            break;
        case 3:
            list[i].setPosition(WR);
            break;
        case 4:
            list[i].setPosition(TE);
            break;
        case 5:
            list[i].setPosition(DL);
            break;
        case 6:
            list[i].setPosition(DE);
            break;
        case 7:
            list[i].setPosition(LB);
            break;
        case 8:
            list[i].setPosition(CB);
            break;
        case 9:
            list[i].setPosition(S);
            break;
        case 10:
            list[i].setPosition(K);
            break;
        default:
            list[i].setPosition(K);
            break;
        }
    }

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getPosition() << " ";
    }

    cout << endl;

    list.sortByPosition();

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getPosition() << " ";
    }

    cout << endl;

    cout << "testing sort by Evaluation" << endl;

    for (int i = 0; i < 13; i++)
    {
        int temp =  rand()%10;
        list[i].setEvaluation(temp);
    }

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getEvaluation() << " ";
    }

    cout << endl;

    list.sortByEvaluation();

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getEvaluation() << " ";
    }

    cout << endl;

    list[0].setID(0);
    list[1].setID(1);
    list[2].setID(2);
    list[3].setID(3);
    list[4].setID(4);
    list[5].setID(5);
    list[6].setID(6);
    list[7].setID(7);
    list[8].setID(8);
    list[9].setID(9);
    list[10].setID(10);
    list[11].setID(11);
    list[12].setID(12);

    cout << "testing findById" << endl;

    for (int i = 0; i < 13; i++)
    {
        cout << list[i].getID() << " ";
    }
    cout << endl;

    cout << "should give 12" << endl;
    cout << list.findById(12) << endl;
    cout << "should give 5" << endl;
    cout << list.findById(5) << endl;
    cout << "should give 0" << endl;
    cout << list.findById(0) << endl;

    cout << endl;

    cout << "testing toString" << endl;

    cout << list.toString();

    return 0;   
}