#ifndef PAINEL_ESCAPE_H
#define PAINEL_ESCAPE_H
#include "painel.h"

class PainelEscape: public Painel{
private:
	static Textura tFundoEscape;
	static Textura tReturn;
	static Textura tReturnS;
	static Textura tHelp;
	static Textura tHelpS;
	static Textura tExit;
	static Textura tExitS;

public:
	PainelEscape();	
	virtual void drawOrtho();
};

#endif