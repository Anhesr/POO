#include <iostream>
#include <ctime>
#include "dados.h"

//Fichero principal del programa con las llamadas a funciones

int main(){
	Dados d;
	int d1,d2,nlan;
	int ve1[5],ve2[5];
	std::cout << "Introduzca el numero de lanzamientos" << std::endl;
	std::cin >> nlan;
	for (int i = 0 ;i<nlan ; i++){
		d.lanzamiento();
	}

	std::cout << "Introduzca un valor a asignar en el dado 1" << std::endl;
	std :: cin >> d1;
	std::cout << "Introduzca un valor a asignar en el dado 2" << std::endl;
	std :: cin >> d2;

	if (d.setDado1(d1)==true){
		std::cout << "dado 1 = " << d.getDado1()<< std::endl ;
	}
	std :: cin >> d2;
	if (d.setDado2(d2)==true){
		std::cout << "dado 2 = " << d.getDado2()<< std::endl ;
	}

	std::cout << "La suma es = " << d.getSuma()<< std::endl ;

	std::cout << "Numero de lanzamientos dado 1 = " << d.getLanzamientos1()<< std::endl ;
	std::cout << "Numero de lanzamientos dado 2 = " << d.getLanzamientos2()<< std::endl ;
	std::cout << "Media dado 1= " << d.getMedia1()<< std::endl ;
	std::cout << "Media dado 2 = " << d.getMedia2()<< std::endl ;
	d.getUltimos1(ve1);
	d.getUltimos2(ve2);
	std::cout << "Ultimos 5 lanzamientos de cada uno de los vectores" << std::endl;
	for (int i = 0 ;i<5 ; i++){
		std::cout << "v1=" << ve1[i] << std::endl;
		std::cout << "v2=" << ve2[i] << std::endl;
	}


}