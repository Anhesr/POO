#include <iostream>
#include <string>
#include "persona.h"
	
	Persona :: Persona(std :: string dni,std :: string nombre,std :: string apel,int edad,std :: string dir,std :: string loc,std :: string prov,std :: string pais ){

		dni_=dni;
		nom_=nombre;
		apel_=apel;
		edad_=edad;
		dir_=dir;
		loc_=loc;
		prov_=prov;
		pais_=pais;

	}

	bool Persona :: setEdad(int ed){
		if(ed>=0){
			edad_=ed;
			return(true);
		}
		else{return(false);}
	}

	int Persona :: getEdad(){
		return (edad_);
	}

	
	void Persona :: setNombre(std :: string nom){
		nom_=nom;
	}

	std :: string Persona :: getNombre(){
		return (nom_);
	}

	void Persona :: setApellidos(std :: string apel){
		apel_=apel;
	}

	std :: string Persona :: getApellidos(){
		return (apel_);
	}

	void Persona :: setDNI(std :: string dni){
		dni_=dni;
	}

	std :: string Persona :: getDNI(){
		return (dni_);
	}

	void Persona :: setDireccion(std :: string dir){
		dir_=dir;
	}

	std :: string Persona :: getDireccion(){
		return (dir_);
	}

	void Persona :: setLocalidad(std :: string loc){
		loc_=loc;
	}

	std :: string Persona :: getLocalidad(){
		return (loc_);
	}

	void Persona :: setProvincia(std :: string prov){
		prov_=prov;
	}

	std :: string Persona :: getProvincia(){
		return (prov_);
	}

	void Persona :: setPais(std ::string pais){
		pais_=pais;
	}

	std :: string Persona :: getPais(){
		return (pais_);
	}

	std :: string Persona :: getApellidosyNombre(){
		return (apel_+", "+nom_);
	}
	
	bool Persona :: mayor(){
		if(edad_>=18){return(true);}
		else{return(false);}
	}