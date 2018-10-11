#include "persona.h"
#include <string>
#include <list>
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
	Jugador(string dni,string codigo,string nombre="",string apellidos="",int edad =0,string dir="",string loc="",string prov="",string pais="") : Persona(dni,nombre,apellidos,edad,dir,loc,prov,pais){dinero_=1000;};
	inline string getCodigo(){return codj_;};
	inline void setCodigo(string cod){codj_=cod;};
	inline int getDinero(){return dinero_;};
	inline void setDinero(int dinero){dinero_=dinero;};
	list <apuestas> getApuestas(){return(apuesta);};
	void setApuestas();
};

