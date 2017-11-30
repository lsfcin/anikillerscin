#ifndef PAINEL_WIN_LOSE_H
#define PAINEL_WIN_LOSE_H
#include "painel.h"

class PainelWinLose: public Painel{
private:
	static Textura winner;
	static Textura loser;
	static Textura fundo;
	static Textura botaonextstageS;
	static Textura botaonextstageN;
	static Textura botaoexitS;
	static Textura botaoexitN;
	Textura *statusJogador1;
	Textura *statusJogador2;
	Textura *statusJogador3;
	Textura *statusJogador4;
	int vencedor;
	int nJogadores;

public:
	PainelWinLose();	
	virtual void drawOrtho();
	void setNJogadores(int nJogadores);
	void setVencedor(int vencedor);
	void drawOrtho1Player();
	void drawOrtho2Player();
	void drawOrtho3Player();
	void drawOrtho4Player();
	void drawOrthoPainel();
};

#endif