#ifndef DISPLAY_H
#define DISPLAY_H

#include "Textura.h"

class Display {
	public:
		Textura * menu;	
		int nJogadores;
		int posicao;		
		float valor;
		
		Display();
		Display(int nJogadores, int posicao);

		~Display();

		void drawOrtho();

		void update(float life, float maxLife);

		void renderBitmapString(int x, int y, char *string);  
 

};
#endif