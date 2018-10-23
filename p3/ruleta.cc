#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"
#include <string>




bool Ruleta :: addJugador(Jugador j){
	list <Jugador>::iterator i;
	for(i=jugadores_.begin(); i != jugadores.end(); ++i){
		if(j.getDNI()==*i){return false;}
	}

	jugadores.push_back(j);
	string n=j.getDNI()+".txt";

	ifstream f(n);

	if(!f){return true;}
	f.close();

	ofstream f(n);
	return true;
	f.close();
}