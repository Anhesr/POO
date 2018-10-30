#include "jugador.h"
#include "crupier.h"
#include <string>
#include <fstream>
#include <list>
#include <stdlib.h>  
#ifndef RULETA_H
#define RULETA_H

using namespace std;

class Ruleta{
private:
	int banca_;
	int bola_;
	list<Jugador> jugadores_;
	Crupier crupier_;
public:

	inline Ruleta(Crupier a) : crupier_(a){
		bola_=-1;
		banca_=1000000;
		srand(time(NULL));
	};
	
	int getBola(){return bola_;};
	int getBanca(){return banca_;};
	bool setBanca(int m){
		if(m<0){return false ;}
		banca_=m;
		return true;
	};
	bool setBola(int m){
		if((m>36)||(m<0)){return false ;};
		bola_=m;
		return true;
	};
	inline Crupier getCrupier(){return crupier_;};
	inline void setCrupier(Crupier c){crupier_=c;};


	bool addJugador(Jugador j);

	inline list<Jugador> getJugadores(){return jugadores_;};

	int deleteJugador(int dni);

	int deleteJugador(string dni){

	list<Jugador>::iterator i;

		if(jugadores_.empty()){
			return(-1);
		}


		for(i=jugadores_.begin(); i != jugadores_.end(); ++i){
			if((dni) == (i->getDNI())) {
				jugadores_.erase(i);
				return(1);
			}
		}
		return(-2);
	};

	int deleteJugador(Jugador j){

	list<Jugador>::iterator i;

		if(jugadores_.empty()){
			return(-1);
		}


		for(i=jugadores_.begin(); i != jugadores_.end(); ++i){
			if((j.getDNI()) == (i->getDNI())) {
				jugadores_.erase(i);
				return(1);
			}
		}
		return(-2);
	};

	void  escribeJugadores(){
		list<Jugador>::iterator i;

		ofstream salida("jugadores.txt");

		for(i=jugadores_.begin(); i != jugadores_.end(); ++i){
			salida << i->getDNI()+"," << i->getCodigo()+"," << i->getNombre()+","<< i->getApellidos()+","<< i->getDireccion()+"," << i->getLocalidad()+"," << i->getProvincia()+"," << i->getPais()+"," << i->getDinero() << endl; 
		}

		salida.close();
	}
	void leeJugadores(){

		Jugador j("","");
		char line[200];

		ifstream entrada("jugadores.txt");

		while (entrada.getline(line,200,',')){
			j.setDNI(line);

			entrada.getline(line,200,',');
			j.setCodigo(line);

			entrada.getline(line,200,',');
			j.setNombre(line);

			entrada.getline(line,200,',');
			j.setApellidos(line);

			entrada.getline(line,200,',');
			j.setDireccion(line);

			entrada.getline(line,200,',');
			j.setLocalidad(line);

			entrada.getline(line,200,',');
			j.setProvincia(line);

			entrada.getline(line,200,',');
			j.setPais(line);

			entrada.getline(line,200);
			j.setDinero(atoi(line));

			jugadores_.push_back(j);
		}
	}

	void giraRuleta(){
		bola_=rand()%37;
	}

	void getPremios(){
		
	}
};

#endif