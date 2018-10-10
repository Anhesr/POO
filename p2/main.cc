#include <iostream>
#include <string>
#include "persona.h"

int main(){
	std :: string a="hola";
	Persona p(a);
	p.setEdad(5);
	std :: cout<< p.getEdad()<< std :: endl;

}