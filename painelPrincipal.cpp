#include "painelPrincipal.h"

Textura PainelPrincipal :: tFundo("Texturas/Menu/menuPrincipal.bmp",false);
Textura PainelPrincipal :: tExit("Texturas/Menu/Botoes/botaoexitN.bmp",false);
Textura PainelPrincipal :: tHelp("Texturas/Menu/Botoes/botaohelpN.bmp",false);
Textura PainelPrincipal :: tMult("Texturas/Menu/Botoes/botaomultiplayerN.bmp",false);
Textura PainelPrincipal :: tSingle("Texturas/Menu/Botoes/botaosingleplayerN.bmp",false);
Textura PainelPrincipal :: tExitS("Texturas/Menu/Botoes/botaoexitS.bmp",false);
Textura PainelPrincipal :: tHelpS("Texturas/Menu/Botoes/botaohelpS.bmp",false);
Textura PainelPrincipal :: tMultS("Texturas/Menu/Botoes/botaomultiplayerS.bmp",false);
Textura PainelPrincipal :: tSingleS("Texturas/Menu/Botoes/botaosingleplayerS.bmp",false);

PainelPrincipal ::PainelPrincipal(/*long intervaloDeTempo*/):Painel(/*intervaloDeTempo*/){
	this->tFundo.carregarBMP();	
	this->tExit.carregarBMP();
	this->tHelp.carregarBMP();
	this->tMult.carregarBMP();
	this->tSingle.carregarBMP();
	this->tExitS.carregarBMP();
	this->tHelpS.carregarBMP();
	this->tMultS.carregarBMP();
	this->tSingleS.carregarBMP();
}

void PainelPrincipal::drawOrtho(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->tFundo.ID);
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1); glVertex3f(-HEIGHT+500, 0	  , 0.f);
			glTexCoord2i(1, 1); glVertex3f( HEIGHT+500, 0	  , 0.f);
			glTexCoord2i(1, 0); glVertex3f( HEIGHT+500, HEIGHT, 0.f);
			glTexCoord2i(0, 0); glVertex3f(-HEIGHT+500, HEIGHT, 0.f);
	glEnd();	
	
	if (escolha == 1){
		glBindTexture(GL_TEXTURE_2D, this->tSingleS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tSingle.ID);
	}

	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(550, 200, 1.f);
			glTexCoord2i(1, 1);glVertex3f(710, 200, 1.f);
			glTexCoord2i(1, 0);glVertex3f(710, 213, 1.f);
			glTexCoord2i(0, 0);glVertex3f(550, 213, 1.f);
	glEnd();

	
	if (escolha == 2){
		glBindTexture(GL_TEXTURE_2D, this->tMultS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tMult.ID);
	}
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(700, 350, 1.f);
			glTexCoord2i(1, 1);glVertex3f(860, 350, 1.f);
			glTexCoord2i(1, 0);glVertex3f(860, 363, 1.f);
			glTexCoord2i(0, 0);glVertex3f(700, 363, 1.f);
	glEnd();
	
	
	if (escolha == 3){
		glBindTexture(GL_TEXTURE_2D, this->tHelpS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tHelp.ID);
	}
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(700, 500, 1.f);
			glTexCoord2i(1, 1);glVertex3f(860, 500, 1.f);
			glTexCoord2i(1, 0);glVertex3f(860, 513, 1.f);
			glTexCoord2i(0, 0);glVertex3f(700, 513, 1.f);
	glEnd();
	
	if (escolha == 4){
		glBindTexture(GL_TEXTURE_2D, this->tExitS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tExit.ID);
	}

	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(550, 650, 1.f);;
			glTexCoord2i(1, 1);glVertex3f(710, 650, 1.f);
			glTexCoord2i(1, 0);glVertex3f(710, 663, 1.f);
			glTexCoord2i(0, 0);glVertex3f(550, 663, 1.f);
	glEnd();


	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}