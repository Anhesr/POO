#ifndef Dados_h
#define Dados_h

class Dados{
//esta clase representa el lanzamiento de dos dados con funciones	
private:
	int d1_;
	int d2_;
	int nlan1_;
	int nlan2_;
	float med1_;
	float med2_;
	int v1_[5];
	int v2_[5];
public:
	Dados();
	void lanzamiento();
	int getDado1();
	int getDado2();
	bool setDado1(int d1);
	bool setDado2(int d2);
	int getSuma();
	int getLanzamientos1();
	int getLanzamientos2();
 	float getMedia1();
 	float getMedia2();
 	void getUltimos1(int *ve1);
 	void getUltimos2(int *ve2);
};

#endif
