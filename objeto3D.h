#ifndef OBJETO_3D_H
#define OBJETO_3D_H

#include "ponto.h"
#include "constantes.h"
#include <stdlib.h>
#include <cstring>
#include "glut.h"
#include "objeto3D.h"

class Objeto3D{	
public:	
	Ponto *centro;	
	Ponto *extremidades[4];
	Vetor *n;	//n == sentido;
	Vetor *v;	//v == up
	Vetor *u;	//u == Urizonte :D
	float angulo; //variável que armazena o angulo atual do Objeto...
	float deltaN;
	float deltaV;
	float deltaU;

public:
	Objeto3D();
	Objeto3D(Ponto *centro, Vetor *n, Vetor *v, float dN, float dV, float dU);
	Objeto3D(const Objeto3D &o);
	~Objeto3D();
	void calcularU();
	void calcularExtremidades();	
	bool colisaoDeSilvio(const Ponto *p) const;
	bool colidiu(const Objeto3D &o);	
	virtual void draw() = 0;
	Objeto3D & operator=(const Objeto3D  &o);
	Ponto getCentro();
	Vetor getN();
	Vetor getV();
	Vetor getU();
	float getAngulo();
	float getDeltaN();
	float getDeltaV();
	float getDeltaU();

	void teste(const Objeto3D &a);
};

#endif
