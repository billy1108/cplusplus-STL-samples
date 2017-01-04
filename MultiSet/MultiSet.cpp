// multiset::count
#include <iostream>
#include <set>
#include <vector>
using namespace std; 
// g++ nombre_del_archivo.cpp -o ejeç
int existe(int a[],int comparar){
	int j=0;
  while(j<14){
    if(comparar==a[j]){
      return 1;//si existe
    }
    j++;
  }
  return 0;//no existe
}
int main ()
{
  int myints[]={10,73,12,22,73,73,12};
  int myints2[]={45,20,10,73,12,77,22};
  std::vector<int> v;
  int i=0,j=0,cont;
  while(i<7){
  	cont=0;
  	while(j<7 && cont==0){
  		if(myints[i]==myints2[j]){
  			v.push_back(myints[i]);
  			cont++;
  		}
  		j++;
  	}
  	i++;
  }
std::vector<int>::iterator it = v.begin();
while(it != v.end() ){
	cout << *it<<endl;
	it++;
}
/*
  std::multiset<int> mymultiset (myints,myints+5);
  std::cout << "73 appears " << mymultiset.count(73) 
	  << " times in mymultiset.\n";*/

  return 0;
}