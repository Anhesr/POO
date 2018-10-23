#include "ruleta.h"
#include "persona.h"
#include "crupier.h"
#include "jugador.h"

int main(){
	Crupier c("33XX","codigo1");
	Ruleta r(c);
	std :: cout<< r.getBola()<< std :: endl;
}