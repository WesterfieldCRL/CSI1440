/**
 * file: proj5-main.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 5
 * due date: 10/17/2022
 *
 * date modified: 10/16/2022
 * - created file
 * 
 * Main
 */

#include <iostream>
#include <fstream>
#include "proj5-BUAthleteList.hpp"

using namespace std;

int main() 
{
    BUAthleteList list;
    ifstream NCAAAfile ("proj5-NCAAAthlete.csv");
    ifstream arandaFile ("proj5-BUAthlete.csv");
    int id;
    int eval;
    int ndx;
    Position pos;
    string name;
    string LOI;
    string school;

    while (getline(NCAAAfile,name,','))
    {
        id = stoi(name);
        getline(NCAAAfile,name,',');
        getline(NCAAAfile,LOI,',');
        getline(NCAAAfile,school);
        list.addNCAAAthlete(id,name,LOI,school);
    }

    list.sortByID();

    while (getline(arandaFile,name,','))
    {
        id = stoi(name);
        getline(arandaFile,name,',');
        if (name == "OL")
        {
            pos = OL;
        }
        else if (name == "QB")
        {
            pos = QB;
        }
        else if (name == "RB")
        {
            pos = RB;
        }
        else if (name == "WR")
        {
            pos = WR;
        }
        else if (name == "TE")
        {
            pos = TE;
        }
        else if (name == "DL")
        {
            pos = DL;
        }
        else if (name == "DE")
        {
            pos = DE;
        }
        else if (name == "LB")
        {
            pos = LB;
        }
        else if (name == "CB")
        {
            pos = CB;
        }
        else if (name == "S")
        {
            pos = S;
        }
        else if (name == "K")
        {
            pos = K;
        }
        else
        {
            cout << "Invalid position" << endl;
        }
        getline(arandaFile,name);
        eval = stoi(name);

        ndx = list.findById(id);
        list[ndx].setPosition(pos);
        list[ndx].setEvaluation(eval);

    }

    list.sortByEvaluation();
    list.sortByPosition();

    cout << list.toString();


    return 0;   
}