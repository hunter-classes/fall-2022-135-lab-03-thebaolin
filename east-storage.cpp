#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){

    ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    string date, eastSt, eastEl, westEl, westSt;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

    // for example, to print the date and East basin storage:
    std::cout << date << " " << eastSt << std::endl;
}


}

