#include "dados.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>

//Fichero en el que se incluyen las funciones para simular el lanzamiento de dos dados

int Dados :: getDado1() {

	return(d1_);
}
int Dados :: getDado2() {

	return(d2_);
}

void Dados :: lanzamiento(){

	d1_=(rand()%6)+1;
	d2_=(rand()%6)+1;
	med1_=med1_+d1_;
	med2_=med2_+d2_;
	nlan1_++;
	nlan2_++;
	//en el vector 1
	v1_[4]=v1_[3];
	v1_[3]=v1_[2];
	v1_[2]=v1_[1];
	v1_[1]=v1_[0];
	v1_[0]=d1_;
	//en el vector 2
	v2_[4]=v2_[3];
	v2_[3]=v2_[2];
	v2_[2]=v2_[1];
	v2_[1]=v2_[0];
	v2_[0]=d2_;

}

bool Dados :: setDado1(int d1){
	if((d1>=1)&&(d1<=6)){
		d1_=d1;
		nlan1_++;
		med1_=med1_+d1_;
		v1_[4]=v1_[3];
		v1_[3]=v1_[2];
		v1_[2]=v1_[1];
		v1_[1]=v1_[0];
		v1_[0]=d1_;
		return(true);
	}
	else{	
	std ::  cout<<"Error se le asignara el valor aleatorio "<< d1_ <<std ::  endl;
	return(false);
	}
}

bool Dados :: setDado2(int d2){
	if((d2>=1)&&(d2<=6)){
		d2_=d2;
		nlan2_++;
		med2_=med2_+d2_;
		v2_[4]=v2_[3];
		v2_[3]=v2_[2];
		v2_[2]=v2_[1];
		v2_[1]=v2_[0];
		v2_[0]=d2_;
		return(true);
	}
	else{ 
	std :: cout<<"Error se le asignara el valor aleatorio "<< d2_ <<std :: endl; 
	return(false);
	}
}

int Dados :: getSuma(){
	return(d1_+d2_);
}

Dados :: Dados(){
	d1_=d2_=1;
	nlan1_=0;
	nlan2_=0;
	med1_=0;
	med2_=0;
	for(int i=0;i<5;i++){
		v1_[i]=0;
		v2_[i]=0;
	}
	srand(time(NULL));
}

int Dados :: getLanzamientos1(){
	return(nlan1_);
}
int Dados :: getLanzamientos2(){
	return(nlan2_);
}

float Dados :: getMedia1(){
	if(nlan1_== 0){
		return(0);
	}
	else{
		med1_=(med1_/nlan1_);
		return(med1_);
	}	
}
float Dados :: getMedia2(){
	if(nlan2_== 0){
		return(0);
	}
	else{
		med2_=(med2_/nlan2_);
		return(med2_);
	}
}
void Dados :: getUltimos1(int *ve1){
	for(int i =0;i<5;i++){
		ve1[i]=v1_[i];
	}
}
void Dados :: getUltimos2(int *ve2){
	for(int i =0;i<5;i++){
		ve2[i]=v2_[i];
	}
	
}

