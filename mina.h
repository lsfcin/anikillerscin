#ifndef MINA_H
#define MINA_H

#include "vetor.h"
#include "objeto3D.h"

class Mina : public Objeto3D{
	public:
	//unsigned int *texturas;//deve mudar na colisao pra tirar uma onda
	bool atirada;

	Mina (Ponto *centro = new Ponto(), Vetor *direcao = new Vetor (0.f, 0.0f, 1.0f), Vetor *lateral = new Vetor (0.0f, 1.0f, 0.0f), float dn = 0.1f, float dv = 0.1f, float du = 0.1f);
	~Mina ();
	virtual void draw ();
	void disparar (Ponto , Vetor );//copias e o vetor eu ainda nao sei pra que serve...
};

#endif