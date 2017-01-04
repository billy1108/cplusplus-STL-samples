// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>
#include <list>
#include <string>

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
	Persona(int codigo, string nombres){
		setCodigo(codigo);
		setNombres(nombres);
	}
};

int main ()
{
	//simular una cola de atencion preferencial
	//segun edad
	//mostrar los nombres de las personas
	//en el oden que seran atendidos
  std::stack<Persona, list<Persona> > mystack;

  Persona per1(1,"Juan"), per2(2,"Maria"),
	  per3(3,"Pedro");

  mystack.push(per1);
  mystack.push(per2);
  mystack.push(per3);

  std::cout << "Popping out elements...\n";
  while (!mystack.empty())
  {
	  std::cout << mystack.top().getCodigo()
		  << ' ' << mystack.top().getNombres() 
		  << endl;
    mystack.pop();
  }

  


  std::cout << '\n';

  return 0;
}