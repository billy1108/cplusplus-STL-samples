// Prueba Bitset.cpp                                
// Uso de bitset para demostrar la Criba de Erat�stenes.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cmath> 
using std::sqrt; // prototipo de sqrt

#include <bitset> // definici�n de la clase bitset

int main()
{
   const int TAMANIO = 1024;
   int valor;
   std::bitset< TAMANIO > criba; // crea bitset de 1024 bits
   criba.flip(); // cambia todos los bits en el objeto bitset criba
   criba.reset( 0 ); // restablece el primer bit (n�mero 0)         
   criba.reset( 1 ); // restablece el segundo bit (n�mero 1)        

   // realiza la Criba de Erat�stenes
   int bitFinal = (int) sqrt( static_cast< double > ( criba.size() ) ) + 1;

   // determina todos los n�meros primos del 2 al 1024
   for ( int i = 2; i < bitFinal; i++ )
   {
      if ( criba.test( i ) ) // el bit i est� encendido
      {
         for ( int j = 2 * i; j < TAMANIO; j += i ) 
            criba.reset( j ); // apaga el bit j
      } // fin de if
   } // fin de for

   cout << "Los numeros primos en el rango de 2 a 1023 son:\n";

   // muestra los n�meros primos en el rango de 2 a 1023
   for ( int k = 2, contador = 1; k < TAMANIO; k++ )
   {
      if ( criba.test( k ) ) // el bit k est� encendido
      {
         cout << setw( 5 ) << k;

         if ( contador++ % 12 == 0 ) // contador es un m�ltiplo de 12
            cout << '\n';
      } // fin de if          
   } // fin de for    
   
   cout << endl;

   // obtien el valor del usuario 
   cout << "\nEscriba un valor de 2 a 1023 (-1 para terminar): ";
   cin >> valor;

   // determina si la entrada del usuario es un n�mero primo
   while ( valor != -1 ) 
   {
      if ( criba[ valor ] ) // n�mero primo
         cout << valor << " es un numero primo\n";
      else // no es un n�mero primo
         cout << valor << " no es un numero primo\n";
      
      cout << "\nEscriba un valor de 2 a 1023 (-1 para terminar): ";
      cin >> valor;
   } // fin de while

   return 0;
} // fin de main
