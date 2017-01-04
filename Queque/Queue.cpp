// queue::front
#include <iostream>       // std::cout
#include <queue>          // std::queue
#include <list>
#include <vector>
using namespace std;

int main ()
{
  std::queue<int, list<int> > myqueue;

  myqueue.push(77);
  myqueue.push(97);
  myqueue.push(16);

  while (!myqueue.empty())
  {
     std::cout << ' ' << myqueue.front() <<endl;
     myqueue.pop();
  }

  std::cout << '\n';

  /*myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " 
	  << myqueue.front() << '\n';*/

  return 0;
}