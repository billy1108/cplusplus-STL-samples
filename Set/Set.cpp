// set::find
#include <iostream>
#include <set>
using namespace std;
int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; i++)
	  myset.insert(i*10);    // set: 10 20 30 40 50

  myset.insert(35);// set : 10 20 30 35 40 50 
  
  it=myset.find(20);
  myset.erase (it);
  myset.erase (myset.find(40));
//set : 10 30 35 50
  myset.insert(35);
  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}