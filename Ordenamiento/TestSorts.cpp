#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#include "SelectionSort.h"

template<typename RI>
  void dump_table(RI first, RI last);

int main() {

  vector<int> a_vec;
  int num_items;
  int num_alea;

	srand(time(0));

  cout << "Ingrese tamaño del vector: ";
  cin >> num_items;

	for (int i = 0; i < num_items; i++) {
		num_alea=rand() % 100;
    a_vec.push_back(num_alea);
  }

	cout << "\nVector inicial: " << endl;
	dump_table(a_vec.begin(), a_vec.end());

  vector<int> copya_vec = a_vec;
	selectionSort(copya_vec.begin(), copya_vec.end());

	cout << "\nVector ordenado: " << endl;
  dump_table(copya_vec.begin(), copya_vec.end());

	return 0;
}

template<typename RI>
  void dump_table(RI first, RI last) {
		for (RI item =first; item != last; ++item)
			cout << (*item) << " ";
		cout << endl;
}
