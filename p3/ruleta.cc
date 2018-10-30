#include "ruleta.h"
#include "persona.h"
#include "crupier.h"
#include <string>
#include <fstream>
#include <list>




bool Ruleta :: addJugador(Jugador j){
	std::list<Jugador>::iterator i;
	for(i=jugadores_.begin(); i != jugadores_.end(); ++i){
		if(j.getDNI()==i->getDNI()){return false;}
	}

	jugadores_.push_back(j);

	std :: string n=j.getDNI()+".txt";

	std::ifstream entrada(n.c_str());

	if(entrada){return true;}

	entrada.close();

	std::ofstream salida(n.c_str());
	return true;
	salida.close();

	return true;
}
