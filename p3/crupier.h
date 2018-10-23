#include "persona.h"
#include <string>
using namespace std;



class Crupier : public Persona{
	
private:
	string cod_;
public:
	Crupier(string dni,string cod,string nombre="",string apellidos="",int edad=0,string dir="",string loc="",string prov="",string pais="") : Persona(dni,nombre,apellidos,edad,dir,loc,prov,pais){cod_=cod;};
	inline string getCodigo(){return (cod_);};
	inline void setCodigo(string cod){cod_=cod;};

};