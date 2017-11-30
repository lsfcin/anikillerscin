#ifndef TIROTELEGUIADO_H
#define TIROTELEGUIADO_H

#include "vetor.h"
#include "textura.h"
#include "objeto3D.h"

class TiroTeleguiado :public Objeto3D {
	public:
    static Textura tMT;

	float velocidade;
	Ponto *centro2;
	//unsigned int *texturas;//deve mudar na colisao pra tirar uma onda
	int gamb;
	bool atirada;

	TiroTeleguiado (Ponto *centro, Vetor *direcao = new Vetor(0.f,0.f,1.f), Vetor *lateral = new Vetor(0.f,1.f,0.f), float dn = 0.5f, float dv= 0.3f, float du = 0.1f);

	~TiroTeleguiado ();

	virtual void draw ();

	void update();

	void disparar (Ponto, Vetor);//copias

	void perseguir (Ponto *destino);
};
#endif
