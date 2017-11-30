#include "display.h"
#include "glut.h"
#include "camera.h"

Display :: Display() {
	this->menu = new Textura("Texturas/Display/status.bmp",true);
	this->nJogadores = 1;
	this->posicao = 1;
	this->valor = 0.0f;
}

Display :: Display(int nJogadores, int posicao) {
	this->menu = new Textura("Texturas/Display/status.bmp",true);
	this->nJogadores = nJogadores;
	this->posicao = posicao;
	this->valor = 0.0f;
}

Display :: ~Display() {
	delete menu;
}

void Display :: drawOrtho() {

	glPushMatrix();
	glColor3f(0.75f,0.f,0.f);

	//posicao e tamanho quando só tem 1 jogador
	if(nJogadores == 1 && posicao == 1) {
		glBegin(GL_QUADS);
			glVertex2i(155, 49); 
			glVertex2i(valor, 49);
			glVertex2i(valor ,72);		
			glVertex2i(155, 72);
		glEnd();

		/////pintando as letras do display...
		glColor3f(1.f, 1.f, 1.f);

		//this->renderBitmapString(155, 100, "Nome: ");
		//this->renderBitmapString(155, 120, "N Minas: ");
		//this->renderBitmapString(155, 140, "N Misseis: ");

		//this->renderBitmapString(215, 100, " ");
		//this->renderBitmapString(215, 120, );
		//this->renderBitmapString(215, 140, " ");

	}
	//posicao e tamanho do jogador de cima p/ 2 players 
	else if(nJogadores == 2 && posicao == 1) {
		glBegin(GL_QUADS);
			glVertex2i(118, 37); 
			glVertex2i(valor, 37);
			glVertex2i(valor ,54);		
			glVertex2i(118, 54);
		glEnd();

	//posicao e tamanho do jogador de baixo p/ 2 players
	} else if(nJogadores == 2 && posicao == 2){
		glBegin(GL_QUADS);
			glVertex2i(118, HEIGHT/2 + 37); 
			glVertex2i(valor, HEIGHT/2 + 37);
			glVertex2i(valor, HEIGHT/2 + 54);		
			glVertex2i(118, HEIGHT/2 + 54);
		glEnd();
	}
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	
	glBlendFunc(GL_DST_COLOR,GL_ZERO);
	glBindTexture(GL_TEXTURE_2D, this->menu->ID);
	
	//posicao e tamanho quando só tem 1 jogador
	if(nJogadores == 1 && posicao == 1) {
		glBegin(GL_QUADS);
			glTexCoord2i(0, 1);  glVertex2i(0,0); 
			glTexCoord2i(1, 1);  glVertex2i(menu->imageWidth, 0);
			glTexCoord2i(1, 0);  glVertex2i(menu->imageWidth, menu->imageHeight);		
			glTexCoord2i(0, 0);  glVertex2i(0, menu->imageHeight);
		glEnd();
	}
	//posicao e tamanho do jogador de cima p/ 2 players 
	else if(nJogadores == 2 && posicao == 1) {
	glBegin(GL_QUADS);
		glTexCoord2i(0, 1);  glVertex2i(0,0); 
		glTexCoord2i(1, 1);  glVertex2i(menu->imageWidth * 0.75, 0);
		glTexCoord2i(1, 0);  glVertex2i(menu->imageWidth * 0.75, menu->imageHeight * 0.75);		
		glTexCoord2i(0, 0);  glVertex2i(0, menu->imageHeight * 0.75);
	glEnd();
	//posicao e tamanho do jogador de baixo p/ 2 players
	} else if(nJogadores == 2 && posicao == 2){
		glBegin(GL_QUADS);
			glTexCoord2i(0, 1);  glVertex2i(0, HEIGHT/2); 
			glTexCoord2i(1, 1);  glVertex2i(menu->imageWidth * 0.75, HEIGHT/2);
			glTexCoord2i(1, 0);  glVertex2i(menu->imageWidth * 0.75 , (menu->imageHeight * 0.75) + HEIGHT/2 );		
			glTexCoord2i(0, 0);  glVertex2i(0, (menu->imageHeight * 0.75) + HEIGHT/2);
		glEnd();
	}
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
void Display :: update(float life, float maxLife){	
	if(life <= 0)
		valor = 118;
	else
		if (nJogadores == 2)
			valor = ((176 * life) /maxLife) + 117;
		else if (nJogadores == 1)
			valor = ((240 * life) /maxLife) + 153;
}

void Display :: renderBitmapString(int x, int y, char *string) {  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) 
	  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);  
}


