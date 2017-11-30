#ifndef METRALHADORA_H
#define METRALHADORA_H

#include "vetor.h"
#include "objeto3D.h"

class Metralhadora : public Objeto3D{
	public:
	float velocidade;

	//unsigned int *texturas;//deve mudar na colisao pra tirar uma onda

	bool atirada;

	Metralhadora (Ponto *centro = new Ponto(), Vetor *direcao = new Vetor (0.f, 0.0f, 1.0f), Vetor *lateral = new Vetor (0.0f, 1.0f, 0.0f), float dn = 0.6f, float dv = 0.6f, float du = 0.6f);

	~Metralhadora ();

	virtual void draw ();

	void update();

	void disparar (Ponto , Vetor );//copias
};

#endif