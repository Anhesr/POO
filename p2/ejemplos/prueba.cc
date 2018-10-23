#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void prueba();

int main(){

   prueba();

}

void prueba(){

/*ofstream salida("prueba.txt");

if(!salida) cout << "ERROR de apertura";

salida << "10," << "47.28,"<< "ejemplo";


salida.close();*/


int a;
float b;
string cad="";
string line="";

ifstream entrada("prueba.txt");

if(!entrada) cout << "ERROR de apertura";


entrada.close();



}