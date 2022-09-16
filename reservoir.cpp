#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

double get_east_storage(std::string date){

    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    string filedate;
    double eastSt, eastEl, westEl, westSt, answer;
    
    while(fin >> filedate >> eastSt) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n');

        if(date == filedate){
            answer = eastSt;
        }
    }
    return answer;
}

double get_min_east(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    string filedate;

    double eastSt, eastEl, westEl, westSt;

    double min = INT_MAX;

    while(fin >> filedate >> eastSt) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt < min)
            min = eastSt;
    }
    std::cout<<"Min Storage in East Basin: "<< min<<std::endl;
    return 0;
}

double get_max_east(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    string filedate;

    double eastSt;

    double max = -INT_MAX;

    while(fin >> filedate >> eastSt) { 
        fin.ignore(INT_MAX, '\n');
        if(eastSt > max)
            max = eastSt;
    }
    std::cout<<"Max Storage in East Basin: "<< max<<std::endl;
    return 0;
}

std::string compare_basins(std::string date){
    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one

    string filedate;
    double eastSt, eastEl, westEl, westSt;
    
    while(fin >> filedate >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n');

        if(filedate == date){

            if(eastEl > westEl)
                return "East\n";
            else if(eastEl < westEl)
                return "West\n";
            else
                return "Equal\n";
           
            }
    }
    fin.close();
    return 0;
}
