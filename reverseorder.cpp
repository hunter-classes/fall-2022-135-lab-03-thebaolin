#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

void reverse_order(std::string date1, std::string date2){

    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    int j = 0;
    string date;
    double eastSt, eastEl, westEl, westSt;
    double westElevation[365];
    string datesArr[365];
    bool start = false;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n'); 
      
      if(date1 == date)
        start = true;
      if(start){
        datesArr[j] = date; //storing date in array
        westElevation[j] = westEl; //storing elevation in another array
        j++;
      }
      if(date2 == date)
        start = false;
  }
  fin.close();

  for(int i = j - 1; i >= 0; i--) //reverse for loop
    cout << datesArr[i] << " " << westElevation[i] << endl;

  fin.close();
}