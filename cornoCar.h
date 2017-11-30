#ifndef CORNOCAR_H
#define CORNOCAR_H

#include "carro.h"
#include "textura.h"

class CornoCar : public Carro{
public:
	static Textura tRoda;
	static Textura tCornoCar;

public:		
	CornoCar(Ponto *centro = new Ponto(0.0f,0.0f,0.0f), Vetor *n = new Vetor(0.0f,0.0f,1.0f), Vetor *v = new Vetor(0.0f,1.0f,0.0f), int cor = PRETO);
	~CornoCar();	
	void roda_origem(int raio);
	void desenhaRodas();
	virtual void setCor(int cor);
	virtual void draw();
};
#endif
