#include <string>
#include <list>
#include <fstream>
#include "jugador.h"

void Jugador :: setApuestas(){
	std :: string n=getDNI()+".txt";
	ifstream f(n.c_str());

	//if(!f) std :: cout << "ERROR de apertura";
	
	apuestas a;


	f >> a.tipo >> a.valor >> a.cantidad;

	apuesta_.push_back(a);

	

	f.close();
	
}