#ifndef PICAPE_H
#define PICAPE_H

#include "carro.h"
#include "textura.h"

class Picape : public Carro{
public:
	static Textura tRoda;
	static Textura tPicape;

public:		
	Picape(Ponto *centro = new Ponto(0.0f,0.0f,0.0f), Vetor *n = new Vetor(0.0f,0.0f,1.0f), Vetor *v = new Vetor(0.0f,1.0f,0.0f), int cor = PRETO);
	~Picape();	
	void roda_origem(int raio);
	void desenhaRodas();
	virtual void setCor(int cor);
	virtual void draw();
};
#endif
