#ifndef PAINEL_PRINCIPAL_H
#define PAINEL_PRINCIPAL_H
#include "painel.h"

class PainelPrincipal: public Painel{
private:
	static Textura tFundo;
	static Textura tExit; 
	static Textura tHelp; 
	static Textura tMult; 
	static Textura tSingle;
	static Textura tSingleS;
	static Textura tMultS;
	static Textura tHelpS;
	static Textura tExitS;

public:
	PainelPrincipal(/*long intervaloDeTempo*/);	
	virtual void drawOrtho();
};

#endif