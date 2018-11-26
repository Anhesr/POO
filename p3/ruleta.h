#include "jugador.h"
#include "crupier.h"
#include <string>
#include <fstream>
#include <list>
#include <stdlib.h> 
#include <iostream>
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
		entrada.close();
	}

	void giraRuleta(){
		bola_=rand()%37;
	}

	void getPremios(){


		list<Jugador>::iterator i; 
		string nom;
		int par[18]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
		int rojo[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
		for(i=jugadores_.begin(); i != jugadores_.end(); ++i){

			string n=i->getDNI()+".txt";
			ifstream f(n.c_str());

			char line[200];
			list<apuestas> aux;
			apuestas a;

			while (f.getline(line,200,',')){
				a.tipo=atoi(line);

				f.getline(line,200,',');
				a.valor=line;
		
				f.getline(line,200);
				a.cantidad=atoi(line);

				aux.push_back(a);
			}

			list<apuestas>::iterator k; 
			for(k=aux.begin(); k != aux.end(); ++k){
				switch(k->tipo){

					case 1:
						nom=k->valor;
						if(atoi(nom.c_str())==(getBola())){
							i->setDinero((i->getDinero())+((k->cantidad)*35));
							setBanca(getBanca()-(k->cantidad*35));
						}
						else{
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
						}
						break;


					case 2:

						if((k->valor) == "rojo"){
							for(int i=0;i<18;i++){
								if(getBola()==rojo[i]){
								i- > setDinero((i->getDinero())+(k->cantidad));
								setBanca(getBanca()-(k->cantidad));
								break;									
								}
							}
						}


						if(getBola()==0){
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
							break;
						}


						if(k->valor=="negro"){
							i->setDinero((i->getDinero())+(k->cantidad));
							setBanca(getBanca()-(k->cantidad));
							break;
						}

						else{
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
						}
						break;

					case 3:


						if(getBola()==0){
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
							break;
						}

						for(int l=0;l<18;l++){
							if((getBola() == par[l])&&(k->valor=="par")){
								cout<< i->getDinero() <<endl;
								i->setDinero((i->getDinero())+(k->cantidad));
								setBanca(getBanca()-(k->cantidad));
								cout<< i->getDinero() <<endl;
								break;
							}
						}

						if(k->valor=="impar"){
							i->setDinero((i->getDinero())+(k->cantidad));
							setBanca(getBanca()-(k->cantidad));
							break;
						}
						else{
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));							
						}
						break;


					case 4:
						if(getBola()==0){
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
						}

						if((getBola()<= 18)&&(k->valor == "bajo")){
							i->setDinero((i->getDinero())+(k->cantidad));
							setBanca(getBanca()-(k->cantidad));
							break;							
						}
						if((getBola()>= 19)&&(k->valor == "alto")){
							i->setDinero((i->getDinero())+(k->cantidad));
							setBanca(getBanca()-(k->cantidad));
							break;							
						}
						else{
							i->setDinero((i->getDinero())-(k->cantidad));
							setBanca(getBanca()+(k->cantidad));
						}
						break;
				}
			}

			f.close();
		}
	}
};

#endif