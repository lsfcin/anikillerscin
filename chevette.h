#ifndef CHEVETTE_H
#define CHEVETTE_H

#include "carro.h"
#include "textura.h"
#include "facesChevette.h"

class Chevette : public Carro{
public:
	static Textura tCarroPreto;
	static Textura tCarroVermelho;
	static Textura tCarroAmarelo;
	static Textura tCarroVerde;
	static Textura tCarroRosa;
	static Textura tCarroBranco;
	static Textura tRoda;

public:		
	Chevette(Ponto *centro = new Ponto(0.0f,0.0f,0.0f), Vetor *n = new Vetor(0.0f,0.0f,1.0f), Vetor *v = new Vetor(0.0f,1.0f,0.0f), int cor = PRETO);
	~Chevette();	
	void roda_origem(int raio);
	void desenhaRodas();
	virtual void setCor(int cor);
	virtual void draw();
};
#endif