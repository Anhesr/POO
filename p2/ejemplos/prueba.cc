#include <iostream>
#include <fstream>
using namespace std;

void prueba();

int main(){

   prueba();

}

void prueba(){

ofstream salida("prueba.txt");

if(!salida) cout << "ERROR de apertura";

salida << "10 " << "47.28 "<< " Esto es un ejemplo";

salida.close();

int a;
float b;
char cad[800];

ifstream entrada("prueba.txt");

if(!entrada) cout << "ERROR de apertura";

entrada >> a >> b >> cad;

cout << a << b << cad << endl; 

entrada.close();



}