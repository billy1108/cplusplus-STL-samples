// swap multimaps
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
using namespace std;
int existe(string tenporal[],string comparar){
  int j=0;
  while(j<100){
    if(comparar==tenporal[j]){
      return 1;//si existe
    }
    j++;
  }
  return 0;//no existe
}
int main (){
  multimap<string,string> foo;
  string tenporal[100];//me almacena las llaves
  foo.insert(make_pair("amo","Dueño de algo."));
  foo.insert(make_pair("amo","Conjugación de amar."));
  foo.insert(make_pair("amo","Hola que ase"));
  foo.insert(make_pair("amo","Anto toda una loquilla"));
  foo.insert(make_pair("bala","Proyectil esférico de metal"));
  foo.insert(make_pair("bala","Conjugación del verbo balar"));
  foo.insert(make_pair("barro","granillos de color rojizo que salen en el rostro"));
  foo.insert(make_pair("barro","la arcilla mojada"));
  foo.insert(make_pair("beso","Acción de besar"));
  foo.insert(make_pair("beso","Golpe violento que mutuamente se dan dos personas en la cara"));
  foo.insert(make_pair("bien","algo o alguien bueno"));
  foo.insert(make_pair("bien","patrimonio de una persona"));

  ofstream fichero("diccionarioHomografo.txt");
  int i=0;// recorre el string tenporal 
  std::multimap<string,string>::iterator it=foo.begin();
  
  for (it; it!=foo.end(); ++it){
    if(existe(tenporal,(*it).first)!=1){
      tenporal[i]=(*it).first;
      std::multimap<string,string>::iterator it2=foo.begin();//buscar las demas coincidencias
      fichero <<  (*it).first << " => " ;
      while(it2 != foo.end() ){
        if(tenporal[i]==(*it2).first){
          fichero  <<(*it2).second <<endl; 
        }
        it2++;
      }
      fichero << '\n';
    }
    i++;
  }


  return 0;
}