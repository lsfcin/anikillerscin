#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include "mina.h"
#include "metralhadora.h"
#include "tiroTeleguiado.h"
#include "timer.h"

#define MAX_METRALHADORA 50
#define MAX_MINA 3

class Armamento {
public:
	Metralhadora *metralhadora[50];//vai ser estatico
	Mina *mina[3];//vai ser estatico
	TiroTeleguiado *mT[10];

	short indiceMetralhadora;
	short indiceMina;//como eu faço com esta merda de indice pq a mina nao eh infinita feito a metralhadora
	short indiceMT;

	Ponto * centroParaOsTiros;//to na duvida, pois vou fazer o seguinte : vou deixar o armamento com uns ponteiros q apontem pra o mesmo conteudo do carro a ele associado. mai qualquer coisa agente muda :p (JAVA)
	Vetor * direcaoParaOsTiros;//essa viajem eh so por causa da herança
	Vetor * lateralParaOsTiros;

	Timer * tempo;//delay
public:
	Armamento (Ponto *, Vetor *, Vetor *);//n sao copias
	~Armamento();
	void update ();//pode ser modificado pra receber a tecla precionada
	void draw ();//sai pintando todas as balas || tiros
	void atirarMetralhadora ();
	void atirarMina ();
	void atirarMT ();
};

#endif