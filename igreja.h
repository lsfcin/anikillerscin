#ifndef Igreja_H
#define Igreja_H

#include "obstaculo.h"

class Igreja : public Obstaculo{
	protected:
         static Textura tIgreja;

	public:
		Igreja(Ponto *p, Vetor *n, Vetor *v, float dN, float dV, float dU, int opcao); 
		~Igreja();

		virtual void draw();


};

#endif
