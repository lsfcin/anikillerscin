#ifndef MUNDO_H
#define MUNDO_H
#include "camera.h"
#include "chevette.h"
#include "Casa.h"
#include "igreja.h"
#include "display.h"

class Mundo{
	public:
		int opcao;
		Textura *texturaChao;
		Textura *texturaGrama;
		Textura *texturaHorizonte;
		Obstaculo *obstaculos[50];
	public:
		Mundo(int opcao);
		~Mundo();			
		void draw();		
		void pintarObstaculos();

};

#endif