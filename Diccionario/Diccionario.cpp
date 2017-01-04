#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string,string> dic;
	map<string,string>::iterator it;

	dic.insert ( pair<string,string>("computador",
		"maquina electronica ....") );
	dic.insert ( pair<string,string>("programa",
		"conjunto de intrucciones ....") );
	dic["printer"]="periferico externo";
	/*dic.insert ( pair<string,string>("printer",
		"periferico externo") );*/

	cout << "Palabras del diccionario:\n";
	for (it=dic.begin(); it!=dic.end(); ++it)
		cout << it->first << " => " << it->second << '\n';

	string palabra;
	cout << "Ingrese palabra a buscar: ";
	cin >> palabra;

	it=dic.find(palabra);
	cout << "significado: ";
	cout << it->second << endl;

	//mostrar la cantidad de palabras existentes en 
	//el diccionario por alfabeto
	//A -> 5
	//B -> 8



}