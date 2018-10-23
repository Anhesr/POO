#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"
#include <string>




bool Ruleta :: addJugador(Jugador j){
	list <Jugador>::iterator i;
	for(i=jugadores_.begin(); i != jugadores_.end(); ++i){
		if(j.getDNI()==i->getDNI()){return false;}
	}

	jugadores_.push_back(j);

	string n=j.getDNI()+".txt";

	ifstream entrada(n.c_str());

	if(entrada){return true;}

	entrada.close();

	ofstream salida(n.c_str());
	return true;
	salida.close();
}