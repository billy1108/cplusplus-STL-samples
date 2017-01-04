// priority_queue::push/pop
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <string>
#include <map>
using namespace std;

class Persona {
private:
	int codigo;
	string nombres;
	int edad;
public:
	void setCodigo(int codigo){
		this->codigo=codigo;
	}
	int getCodigo(){
		return codigo;
	}
	void setNombres(string nombres){
		this->nombres=nombres;
	}
	string getNombres(){
		return nombres;
	}
	void setEdad(int edad){
		this->edad=edad;
	}
	int getEdad(){
		return edad;
	}
	Persona(int codigo, string nombres, int edad){
		setCodigo(codigo);
		setNombres(nombres);
		setEdad(edad);
	}
};

int main ()
{
  std::priority_queue<int> mypq;
  multimap<int,Persona> mPer;

  Persona per1(1,"Juan",30), per2(2,"Maria",50),
	  per3(3,"Pedro",10), per4(4,"Rosa",30);

  mypq.push(per1.getEdad());
  mypq.push(per2.getEdad());
  mypq.push(per3.getEdad());
  mypq.push(per4.getEdad());
  //mypq : 30,50,10,30
  mPer.insert(pair<int,Persona>(per1.getEdad(),per1));
  mPer.insert(pair<int,Persona>(per2.getEdad(),per2));
  mPer.insert(pair<int,Persona>(per3.getEdad(),per3));
  mPer.insert(pair<int,Persona>(per4.getEdad(),per4));
  
  std::cout << "Orden de atencion...\n";
  multimap<int,Persona>::iterator it=mPer.begin();
  while (!mypq.empty())
  {
     std::cout << mypq.top() << ' ';
	 it=mPer.find (mypq.top());
	 cout << (it->second).getNombres() << endl;
	 mPer.erase(it);
     mypq.pop();
  }
  std::cout << '\n';

  return 0;
}