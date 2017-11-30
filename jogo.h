#ifndef JOGO_H
#define JOGO_H

#include "mundo.h"
#include "jogador.h"
#include "menu.h"
#include "painelEscape.h"
#include "painelWinLose.h"

class Jogo{
	
	private:
		int mundoAtual;	

		Menu *menu;
		Timer *timerTeclado;
		Timer *timerEscape;
		PainelEscape * pEscape;
		PainelHelp * pHelp;
		PainelWinLose *pWinLose;

		bool painelEscapeAtivo;
		bool painelWinnerAtivo;
		bool painelHelpAtivo;
		bool destruirMundo;
		int nJogadores;
		int vencedor;
		Mundo *world;
		Jogador *jogadores[4];		

	public:
		Jogo();
		~Jogo();		
		void update();
		void tratarTeclado();
		void tratarTecladoWinLose();
		void draw();
		void drawOrtho();
		void colisaoMinas();
		void colisaoObstaculos();
		void colisaoObstaculoMetralhadora();
		void colisaoMetralhadora();
		void iniciarFase();
		void colisaoObstaculoMT();
		void colisaoMT();	
		void comecarJogo();
		bool acabouJogo();
};
#endif