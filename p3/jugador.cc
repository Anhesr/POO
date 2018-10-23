#include <string>
#include <list>
#include <fstream>
#include "jugador.h"

void Jugador :: setApuestas(){

	string n=getDNI()+".txt";
	ifstream f(n.c_str());

	//if(!f) std :: cout << "ERROR de apertura";
	
	apuestas a;

/*
	while (getline(f,line,',')){

	cout << line << endl; 
	}
	printf("%i,%i",a.tipo,a.cantidad);
	apuesta_.push_back(a);
*/
	

	f.close();
	
}