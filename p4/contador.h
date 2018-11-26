#ifndef CONTADOR_H
#define CONTADOR_H

class Contador{
private:
	int valor_;
	int min_;
	int max_;
public:
	Contador(int valor=0,int min=0,int max=1000){
		if(min<max){
		min_=min;
		max_=max;
		}
		else{
			min_=0;
			max_=1000;
		}
		if((valor>=min)&&(valor<=max)){
			valor_=valor;
		}
		else{
			valor_=0;
		}
	};
	Contador operator=(const Contador &c);
	Contador operator=(const int &c);
	Contador operator++(void);
	Contador operator++(int);
	Contador operator--(void);
	Contador operator--(int);
	inline Contador friend operator+(Contador c,const int &i){
		c.valor_=c.valor_+i;
		return c;
	};
	inline Contador friend operator+(const int &i,Contador c){
		c.valor_=c.valor_+i;
		return c;
	};
	inline Contador friend operator-(Contador c,const int &i){
		c.valor_=c.valor_-i;
		return c;
	};
	inline Contador friend operator-(const int &i,Contador c){
		c.valor_=c.valor_-i;
		return c;
	};
	int get(){return valor_;};

};

Contador Contador::operator=(const Contador &c)
{
	valor_=c.valor_;
	min_=c.min_;
	max_=c.max_;
	return *this;
}

Contador Contador::operator=(const int &c)
{
	valor_=c;
	return *this;
}

Contador Contador::operator++(void)
{

	++valor_;
	if (valor_ >=max_){
		valor_=max_;
	}
	return *this;
	
}

Contador Contador::operator++(int)
{
 	Contador temp=*this;
	++valor_;
	if (valor_ >=max_){
		valor_=max_;
	}
	return temp;
}

Contador Contador::operator--(void)
{
	--valor_;
	if (valor_ <=min_){
		valor_=min_;
	}
	return *this;
}
Contador Contador::operator--(int)
{
 	Contador temp=*this;
	--valor_;
	if (valor_ <=min_){
		valor_=min_;
	}
	return temp;
}
#endif