#ifndef TIRO_H
#define TIRO_H

#include "Ponto.h"
#include "Vetor.h"

class Tiro{
	public:
	Ponto extremidades[4];
	Ponto *centro;
	Vetor *v1;
	Vetor *v2;
	unsigned int *texturas;

	// parte física
	float aceleracao;
	float velocidade;
	float velocidadeMaxima;
	
	float deltaX;
	float deltaZ;

	int atirada;

	Tiro(float acele, float velomax,float deltaX, float deltaZ);

	void calcularExtremidades();
	void acelerar();
	void andar();
};

#endif