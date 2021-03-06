#include "persona.h"
#include <string>
#include <list>
#include <fstream>
#include <stdlib.h>
#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;

struct apuestas{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador : public Persona{
private:
	int dinero_;
	string codj_;
	list <apuestas> apuesta_;
public:
	Jugador(string dni,string codigo,string nombre="",string apellidos="",int edad =0,string dir="",string loc="",string prov="",string pais="") : Persona(dni,nombre,apellidos,edad,dir,loc,prov,pais){dinero_=1000; codj_=codigo;};
	inline string getCodigo(){return codj_;};
	inline void setCodigo(string cod){codj_=cod;};
	inline int getDinero(){return dinero_;};
	inline void setDinero(int dinero){dinero_=dinero;};
	inline list <apuestas> getApuestas(){return(apuesta_);};
	void setApuestas(){
	string n=getDNI()+".txt";
	ifstream f(n.c_str());

	char line[200];

		apuestas a;

		while (f.getline(line,200,',')){
			a.tipo=atoi(line);

			f.getline(line,200,',');
			a.valor=line;
		
			f.getline(line,200);
			a.cantidad=atoi(line);

			apuesta_.push_back(a);
		}

		f.close();
	};
};

#endif