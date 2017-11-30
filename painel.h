#ifndef PAINEL_H
#define PAINEL_H

#include "textura.h"
#include "timer.h"
#include "keys.h"
#include "constantes.h"

class Painel {
	protected:		
		//Timer contador;
		int escolha;

	public:
		Painel(/*long intervaloDeTempo*/);					
		virtual void drawOrtho() = 0;
		void setEscolha(int escolha);
//		int getEscolha();


};


#endif