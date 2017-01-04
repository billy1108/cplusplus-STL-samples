#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
using namespace std;

int existe(string guardando[],int i){
	int j=0;
	while(j<108){
		while(guardando[i]==guardando[j]){
			return 1;//si existe
		}
		j++;
	}
	return 0;//no existe
}

int main(int argc, char const *argv[]){
	map<string, int> mapa;// creando mi contendor forkey
	string so[108];
	string guardando[108];
	//Lllenando de archivo a string
	ifstream f( "entradaNumero.txt" );
	int i=0;
	if ( f.is_open() ) {
	 	getline( f, so[i] );
		while( !f.eof() ) {
			i++;
		 	getline(f,so[i]); 
		}
	}
	f.close();
	i=0;
	//Guardando en mapa
	while(i<108){
		guardando[i] = so[i];
		
		if( existe(guardando,i) == 1 ){//sino existe llenara el MAPA
			int contador = 0,j=i;
			while(j<108){
				if( guardando[i] == so[j] ){
					contador++;
				}
				j++;
			}
			mapa.insert( pair<string,int>(guardando[i],contador) );
		}
		i++;
	}
	//mostrar
	map<string, int>::iterator it = mapa.begin();
	while( it != mapa.end() ){
		cout <<setw(15)<< it->first << " : " <<setw(4)<< it->second <<endl;
		it++;
	}
	//escribir archivo
	ofstream fichero("salidaNumero.txt");
	map<string, int>::iterator itp = mapa.begin();
	while( itp != mapa.end() ){
		fichero << setw(15) <<  itp->first << " : " << setw(4) << itp->second <<endl;
		itp++;
	}
	return 0;
}