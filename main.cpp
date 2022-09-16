#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"
using namespace std;


int main()
{
  cout<<"TASK A\n";
  cout<< "05/20/2018 " << get_east_storage("05/20/2018")<<endl;

  cout<<"\nTASK B\n";
  get_min_east();
  get_max_east();

  cout<<"\nTASK C\n";
  cout<< "01/05/2018 " << compare_basins("01/05/2018");
  cout<< "09/14/2018 " << compare_basins("09/14/2018");
  cout<< "09/15/2018 " << compare_basins("09/15/2018");

  cout<<"\nTASK D\n";
  reverse_order("05/29/2018", "06/02/2018");

  return 0;
}
