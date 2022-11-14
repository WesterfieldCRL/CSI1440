/**
 * file: proj6-sequentialMain3.cpp
 * author: Wesley Anastasi
 * course: CSI 1440
 * assignment: Project 6
 * due date: 11/14/2022
 *
 * date modified: 11/9/2022
 * - created file
 * 
 * sequential Main
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  string name, choice;
  int age;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  //if the user responds yes, opens the input file and 
  cout << "Would you like to read the data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes")
  {
    fileRead = true;
    pfile.open("iperson.txt");
    if( !pfile ) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
  }

  //opens the output file
  opfile.open("operson.txt");

  choice = "yes";

  //reads in data from the input file
  if( fileRead ) {
    getline( pfile, name );
    pfile >> age;
    pfile.ignore(3, '\n');
    if( !pfile ) {
      choice = "no";
    }
  }

  //loops untill the user responds no
  while( choice != "no" ) 
  {
    //prompts user for data
    if( !fileRead ) {
      cout << "Please enter your name followed by your age." << endl;
      getline( cin, name );
      cin >> age;
      cin.ignore(3, '\n');
    } 

    //outputs data to file
    opfile << name << endl;
    opfile << age << endl;

    //prompts user to continue or exit the loop
    if( !fileRead ) 
    {
      cout << "Do you want to read in another person (yes/no)? " << endl;
      cin >> choice;
      cin.ignore(3, '\n');
    } 
    else 
    {
      getline( pfile, name );
      pfile >> age;
      pfile.ignore(3, '\n');
      if( !pfile ) 
      {
        choice = "no";
      }
    }

  }

  return 0;
}