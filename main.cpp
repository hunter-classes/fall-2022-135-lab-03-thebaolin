#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"
using namespace std;


int main()
{
  
  cout<< "01/01/2018 " << get_east_storage("01/01/2018")<<endl;
  get_min_east();
  get_max_east();
  cout<< "01/01/2018 " << compare_basins("01/01/2018")<<endl;
  reverse_order("05/29/2018", "06/02/2018");

  return 0;
}
