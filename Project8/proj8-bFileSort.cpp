/**
 * file: proj8-bFileSort.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 8
 * due date: 10/24/2022
 *
 * date modified: 10/21/2022
 * - created file
 * 
 * Main file
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream test("testFile", ios::in | ios::out);
    int x = 97;
    char temp[10];

    test.write(reinterpret_cast<char*>(&x), sizeof(int));

    test.read(reinterpret_cast<char*>(&x),sizeof(int));

    cout << x << endl;

    test.close();

    return 0;
}