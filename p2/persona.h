#include <string>
#ifndef PERSONA_H
#define PERSONA_H
using namespace std;

class  Persona{
//esta clase gestiona los datos de personas
private:

	string dni_;
	string nom_;
	string apel_;
	int edad_;
	string dir_;
	string loc_;
	string prov_;
	string pais_;

public:

	Persona(string dni,string nombre="",string apel="",int edad=0,string dir ="",string loc="",string prov="",string pais ="");

	bool setEdad(int ed);
	int getEdad();

	void setNombre(string nom);
	string getNombre();

	void setApellidos(string apel);
	string getApellidos();

	void setDNI(string dni);
	string getDNI();

	void setDireccion(string dir);
	string getDireccion();

	void setLocalidad(string loc);
	string getLocalidad();

	void setProvincia(string prov);
	string getProvincia();

	void setPais(string pais);
	string getPais();

	string getApellidosyNombre();

	bool mayor();
	

};

#endif