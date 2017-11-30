#ifndef DINAMICO_H
#define DINAMICO_H

#include "objeto3D.h"

class Dinamico : public Objeto3D{

public:
	//parte física
	float massa;
	
	Vetor *aceleracao;
	Vetor *velocidade;
	float acel;	
	float freio;	
	float resistencia;
	float velocidadeMaxima;
	float velocidadeMinima;

public:
	Dinamico();
	Dinamico(Ponto *centro, Vetor *n, Vetor *v, float massa, float acelerar, float velocidadeMaxima,
			 float velocidadeMinima, float dN , float dV , float dU);
	~Dinamico();

	Ponto centroDeMassa(const Dinamico &d);
	void acelerar();
	void freiar();
	void darRe();	
	void passivo();
	bool repouso();
	bool mProgressivo();
	bool mRetrogrado() const;

	

	//virtual void update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina/*, bool teleguiado*/) = 0;	
	virtual void draw() = 0;

};

#endif