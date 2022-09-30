/**
 * file: proj4-testmain.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 4
 * due date: 10/03/2022
 *
 * date modified: 9/26/2022
 * - created file
 * 
 * Testmain
 */

#include <iostream>
#include <fstream>


using namespace std;

int main() 
{
    fstream output ("testOutput.txt");

    output.put('\t');
    output.put('v');

    return 0;   
}