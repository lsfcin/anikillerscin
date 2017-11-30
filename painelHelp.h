#ifndef PAINEL_HELP_H
#define PAINEL_HELP_H
#include "painel.h"

class PainelHelp: public Painel{
private:
	static Textura tFundo;	
	static Textura tBackS; 

public:
	PainelHelp();	
	virtual void drawOrtho();
};

#endif