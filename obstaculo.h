#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "Ponto.h"
#include "Vetor.h"
#include "objeto3D.h"
#include "textura.h"

class Obstaculo : public Objeto3D{
	protected:
		static Textura t1;
		static Textura t2;
		static Textura t3;
		static Textura t4;
		static Textura t5;
		static Textura t6;
		static Textura t7;
		static Textura t8;
		static Textura t9;
		static Textura t10;
		int opcao;

	public:
		Obstaculo(Ponto *p, Vetor *n, Vetor *v, float dN, float dV, float dU, int opcao);
		virtual void draw();
};

#endif