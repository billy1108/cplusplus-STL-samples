/*PAGINAS SOBRE ARCHIVOS BINARIOS
	http://trevinca.ei.uvigo.es/~jgarcia/TO/cursilloCpp/14_archivos.html

	http://c.conclase.net/curso/?cap=039
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct infoFichero{
	char nombre[25];
	int Bytes;
	float KB;
	float MG;
	float GB;
};

void tamanoFichero(){
	infoFichero datosFichero;
	strcpy(datosFichero.nombre,"uno.mp3");
	ifstream fichero(datosFichero.nombre,ios::binary);

	fichero.seekg(0,ios::end);
	datosFichero.Bytes =fichero.tellg();
	datosFichero.KB = (float)datosFichero.Bytes/1024;
	datosFichero.MG = (float)datosFichero.KB/1024;
	datosFichero.GB = (float)datosFichero.MG/1024;
	fichero.close();

	cout<<"......"<<endl;
	cout<<"Fichero : "<<datosFichero.nombre<<endl;
	cout<<"Bytes: "<<datosFichero.Bytes<<endl;
	cout<<"Kilobytes : "<<datosFichero.KB<<endl;
	cout<<"Megabytes : "<<datosFichero.MG<<endl;
	cout<<"Gigabytes : "<<datosFichero.GB<<endl;
	cout<<"......"<<endl;
}

struct Registro{
	char Nombre[30];
	char Email[40];
	char Telefono[15];
};

void RegistroBinario(){
	Registro Agenda,LeerAgenda;
	ofstream fichero("miagenda.dat",ios::binary);
	strcpy(Agenda.Nombre,"Pepe");
	strcpy(Agenda.Email,"email@email.com");
	strcpy(Agenda.Telefono,"500 00 002");
	fichero.write((char*)&Agenda,sizeof(Registro));
	fichero.close();

	//leer fichero
	ifstream leerfichero("miagenda.dat",ios::binary);
	leerfichero.read((char*)&LeerAgenda,sizeof(Registro));

	cout<< "Nombre : "<<LeerAgenda.Nombre <<endl;
	cout<< "Email : "<<LeerAgenda.Email <<endl;
	cout<< "Telefono : "<<LeerAgenda.Telefono <<endl;
}
void escribir(){
	ofstream fichero("numero.txt");
	for(int x=1;x<=10;x++) fichero << x << endl;
	fichero.close();
}

void leer(){
	ifstream fichero;
	fichero.open("numero.txt");
	// while(fichero.good()) = while(!fichero.eof())
	while(!fichero.eof()) cout<< (char)fichero.get();
	fichero.close();
}
void canviar(){

}
int main(){
	//escribir();
	//leer();
	//tamanoFichero();
	//RegistroBinario();	
}