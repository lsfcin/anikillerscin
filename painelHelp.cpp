#include "painelHelp.h"

Textura PainelHelp :: tFundo("Texturas/Menu/menuAjudaPreto.bmp",false);
Textura PainelHelp :: tBackS("Texturas/Menu/Botoes/botaobackS.bmp",false);

PainelHelp :: PainelHelp():Painel(){	
	this->tFundo.carregarBMP();		
	this->tBackS.carregarBMP();
}

void PainelHelp::drawOrtho(){
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, tFundo.ID);
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1); glVertex3f(50, 50 , 0.f);
			glTexCoord2i(1, 1); glVertex3f(WIDTH-50, 50, 0.f);
			glTexCoord2i(1, 0); glVertex3f(WIDTH-50, 550, 0.f);
			glTexCoord2i(0, 0); glVertex3f(50, 550, 0.f);
	glEnd();	

	// botao back
	
	glBindTexture(GL_TEXTURE_2D, tBackS.ID);

	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(10 , 710,	1.f);
			glTexCoord2i(1, 1);glVertex3f(170, 710,	1.f);
			glTexCoord2i(1, 0);glVertex3f(170, 723, 1.f);
			glTexCoord2i(0, 0);glVertex3f(10 , 723, 1.f);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}