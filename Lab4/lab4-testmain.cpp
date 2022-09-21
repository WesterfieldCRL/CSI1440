#include <iostream>
#include "lab4-IntArray.h"

using namespace std;

int main() {

    srand(time(0));
    IntArray Int1;
    IntArray Int2;
    cout << "Initial values: " << endl;
    cout << "Capacity: " << Int1.getCapacity() << " should have 5" << endl;
    cout << "Size: " << Int1.getSize() << " should have 0" << endl << endl;

    cout << "Add some values: " << endl;
    cout << "After one value: " << endl;
    Int1.insertVal(rand()%10);
    cout << "Capacity: " << Int1.getCapacity() << " should have 5" << endl;
    cout << "Size: " << Int1.getSize() << " should have 1" << endl << endl;

    cout << "After 5 values: " << endl;
    Int1.insertVal(rand()%10);
    Int1.insertVal(rand()%10);
    Int1.insertVal(rand()%10);
    Int1.insertVal(rand()%10);
    cout << "Capacity: " << Int1.getCapacity() << " should have 10" << endl;
    cout << "Size: " << Int1.getSize() << " should have 5" << endl << endl;

    cout << "After 6 values: " << endl;
    Int1.insertVal(6);
    cout << "Capacity: " << Int1.getCapacity() << " should have 10" << endl;
    cout << "Size: " << Int1.getSize() << " should have 6" << endl << endl;

    cout << "Remove a value: " << endl;
    cout << "Removed: " << Int1.removeVal() << " should have 6" << endl;

    cout << "Capacity: " << Int1.getCapacity() << " should have 10" << endl;
    cout << "Size: " << Int1.getSize() << " should have 5" << endl << endl;

    IntArray Int3(Int2);


   return 0;
}