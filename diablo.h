#ifndef DIABLO_H
#define DIABLO_H

#include "carro.h"
#include "textura.h"

class Diablo : public Carro{
public:
	static Textura tRoda;
	static Textura tDiablo;

public:		
	Diablo(Ponto *centro = new Ponto(0.0f,0.0f,0.0f), Vetor *n = new Vetor(0.0f,0.0f,1.0f), Vetor *v = new Vetor(0.0f,1.0f,0.0f), int cor = PRETO);
	~Diablo();	
	void roda_origem(int raio);
	void desenhaRodas();
	virtual void setCor(int cor);
	virtual void draw();
};
#endif
