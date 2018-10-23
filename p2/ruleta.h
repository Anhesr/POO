#include <string>
#include <iostream>
#include "crupier.h"
#include "jugador.h"

using namespace std;

class Ruleta{
private:
	int banca_;
	int bola_;
	list <Jugador> jugadores_;
	Crupier crupier_;
public:
	Ruleta(Crupier a) : crupier_(a){
		bola_=-1;
		banca_=1000000;
	}
	int getBola(){return bola_;};
	int getBanca(){return banca_;};
	bool setBanca(int m){
		if(m<0){return false ;}
		banca_=m;
		return true;
	}
	bool setBola(int m){
		if((m>36)||(m<0)){return false ;}
		bola_=m;
		return true;
	}
	Crupier getCrupier(){return crupier_;};
	void setCrupier(Crupier c){crupier_=c;};
};