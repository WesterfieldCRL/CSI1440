/**
 * file: proj8-bFileSort.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 8
 * due date: 10/24/2022
 *
 * date modified: 10/23/2022
 * - created file
 * 
 * Main file
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("sortedInts", ios::in | ios::out | ios::binary);
    fstream temp("sortedInts", ios::in | ios::binary);
    int input;
    int x;

    //wouldnt write to file when empty if anything else is done first
    //so I am using a sperate fstream to check if it is empty
    if (temp.peek() == EOF)
    {
        cout << "Please enter an Integer" << endl;
        cin >> input;
        file.write((char*)&input,sizeof(int));
    }
    else
    {

        file.seekg(0,ios::end);
        int size = file.tellg()/4;

        for (int i = 0; i < size; i++)
        {
            file.seekg(i*sizeof(int),ios::beg);
            file.read((char *) &x, sizeof(int));
            cout << x << " ";     
        }

        cout << endl << "Please enter an Integer" << endl;
        cin >> input;

        int i;
        bool placedNum = false;
        for (i = 1; i <= size+1 && !placedNum; i++)
        {
            file.seekg((-1*i)*sizeof(int),ios::end);
            file.read((char*) &x, sizeof(int));
            if (input >= x)
            {
                placedNum = true;
                file.write((char*)&input,sizeof(int));
            }
            else
            {
                file.write((char*)&x,sizeof(int));
            }   
        }

        if (!placedNum)
        {
            file.seekg(0,ios::beg);
            file.write((char*)&input,sizeof(int));
        }

    }

    file.close();

    return 0;
}