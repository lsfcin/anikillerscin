#ifndef PAINEL_MULTIPLAYER_H
#define PAINEL_MULTIPLAYER_H
#include "painel.h"

class PainelMultiplayer: public Painel{
private:
	static Textura tFundo;
	static Textura tBack;
	static Textura tBackS;
	static Textura tVersus;
	static Textura tVersusS;
	static Textura tLAN;
	static Textura tLANS;

public:
	PainelMultiplayer();	
	virtual void drawOrtho();
};

#endif