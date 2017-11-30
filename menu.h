#ifndef MENU_H
#define MENU_H

#include "timer.h"
#include "painelPrincipal.h"
#include "painelHelp.h"
#include "painelSingle.h"
#include "painelMultiplayer.h"
#include "painelPlayer.h"
#include "chevette.h"

class Menu{
private:		
	
	const static int PRINCIPAL = 0;
	const static int SINGLE_PLAYER = 1;	
	const static int MULTIPLAYER = 2;
	const static int HELP = 3;
	const static int PLAYER = 4;

	// do painel Principal	
	const static int EXIT = 4;	

	// do painel Single Player
	const static int SETA_ESQUERDA = 0;
	const static int SETA_DIREITA = 1;
	const static int BACK = 2;
	const static int START = 3;
	const static int SETA_UP = 4;

	// do painel Multiplayer
	const static int VERSUS = 0;
	const static int LAN = 1;
	//o back ja foi criado ali atrás...

	//dos painéis Players
	const static int OK = 8;

	PainelPrincipal * mPrincipal;
	PainelHelp * mHelp;
	PainelSingle * mSingle;
	PainelMultiplayer * mMultiplayer;
	PainelPlayer * mPlayer;

	Timer *timerTeclado;	
	Timer *timerHelp;

	bool comecarJogo;
	bool ativo;
	int nJogadores;
	int *carroEscolhido;
	int *corEscolhida;
	int painelAtual;

public:
	Menu();
	~Menu();
	void update();
	void tratarTeclado();
	void tratarTecladoPrincipal();
	void tratarTecladoSingle();
	void tratarTecladoMulti();
	void tratarTecladoPlayer();
	void tratarTecladoHelp();
	void draw();
	void drawOrtho();
	void ativar(bool ativar);
	bool ativado();
	bool podeComecarJogo();
	int* getCorEscolhida();
	int* getCarroEscolhido();
	int getNJogadores();
	
};



#endif