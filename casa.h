#ifndef Casa_H
#define Casa_H

#include "obstaculo.h"

class Casa : public Obstaculo{
	protected:
		static Textura parede1;
		static Textura parede2;
		static Textura parede3;
		static Textura parede4;
		static Textura teto;

	public:
		Casa(Ponto *p, Vetor *n, Vetor *v, float dN, float dV, float dU, int opcao); 
		~Casa();

		virtual void draw();


};

#endif