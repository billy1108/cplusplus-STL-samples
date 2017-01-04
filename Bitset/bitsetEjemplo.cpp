#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main(int argc, char const *argv[])
{
	bitset<5> uno;// "00000"
	cout << uno.flip()<<endl;//"00100"
	cout << uno.reset(2) <<endl;//11011
	cout << uno.test(1) <<endl;//0
	return 0;
}