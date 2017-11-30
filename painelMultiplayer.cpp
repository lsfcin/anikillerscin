#include "painelMultiplayer.h"

Textura PainelMultiplayer :: tFundo("Texturas/Menu/menuprincipal.bmp",false);
Textura PainelMultiplayer :: tBack("Texturas/Menu/Botoes/botaobackN.bmp",false);
Textura PainelMultiplayer :: tBackS("Texturas/Menu/Botoes/botaobackS.bmp",false);
Textura PainelMultiplayer :: tVersus("Texturas/Menu/Botoes/botaoversusN.bmp",false);
Textura PainelMultiplayer :: tVersusS("Texturas/Menu/Botoes/botaoversusS.bmp",false);
Textura PainelMultiplayer :: tLAN("Texturas/Menu/Botoes/botaolanN.bmp",false);
Textura PainelMultiplayer :: tLANS("Texturas/Menu/Botoes/botaolanS.bmp",false);


PainelMultiplayer ::PainelMultiplayer():Painel(){
	this->tFundo.carregarBMP();
	this->tBack.carregarBMP();
	this->tBackS.carregarBMP();
	this->tVersus.carregarBMP();
	this->tVersusS.carregarBMP();
	this->tLAN.carregarBMP();
	this->tLANS.carregarBMP();
}

void PainelMultiplayer::drawOrtho(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->tFundo.ID);
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1); glVertex3f(-HEIGHT+500, 0	  , 0.f);
			glTexCoord2i(1, 1); glVertex3f( HEIGHT+500, 0     , 0.f);
			glTexCoord2i(1, 0); glVertex3f( HEIGHT+500, HEIGHT, 0.f);
			glTexCoord2i(0, 0); glVertex3f(-HEIGHT+500, HEIGHT, 0.f);
	glEnd();	
	
	//BOTÕES
	if (escolha == 0){
		glBindTexture(GL_TEXTURE_2D, this->tVersusS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tVersus.ID);
	}

	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(550, 200, 1.f);
			glTexCoord2i(1, 1);glVertex3f(710, 200, 1.f);
			glTexCoord2i(1, 0);glVertex3f(710, 213, 1.f);
			glTexCoord2i(0, 0);glVertex3f(550, 213, 1.f);
	glEnd();

	
	if (escolha == 1){
		glBindTexture(GL_TEXTURE_2D, this->tLANS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tLAN.ID);
	}
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(700, 350, 1.f);
			glTexCoord2i(1, 1);glVertex3f(860, 350, 1.f);
			glTexCoord2i(1, 0);glVertex3f(860, 363, 1.f);
			glTexCoord2i(0, 0);glVertex3f(700, 363, 1.f);
	glEnd();
	
	
	if (escolha == 2){
		glBindTexture(GL_TEXTURE_2D, this->tBackS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, this->tBack.ID);
	}
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex3f(700, 500 , 1.f);
			glTexCoord2i(1, 1);glVertex3f(860, 500, 1.f);
			glTexCoord2i(1, 0);glVertex3f(860, 513, 1.f);
			glTexCoord2i(0, 0);glVertex3f(700, 513, 1.f);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}