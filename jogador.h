#ifndef JOGADOR_H
#define JOGADOR_H
#include "camera.h"
#include "display.h"
#include "chevette.h"
#include "picape.h"
#include "cornoCar.h"
#include "diablo.h"

class Jogador{
	public:
		Camera *camera;
		Carro *carro;
		Display *display;
		int nJogadores;
		int posicao;
		float life;
		float maxLife;
		
	public:
		Jogador();
		Jogador(Carro *carro, int nJogadores, int posicao);
		~Jogador();				
		void update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado);
		void tratarTeclado(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado);	
		void draw();
		void drawOrtho();
		void setNJogadores(int nJogadores);
		void setPosicao(int posicao);
};

#endif
