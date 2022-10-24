#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream test("sortedInts", ios::in | ios::out | ios::binary | fstream::trunc);
    int x = 21;

    test.write((char *) &x, sizeof(int));
    x = 30;
    test.write((char *) &x, sizeof(int));
    x = 41;
    test.write((char *) &x, sizeof(int));
    x = 97;
    test.write((char *) &x, sizeof(int));
    x = 104;
    test.write((char *) &x, sizeof(int));


    test.close();

    return 0;
}