#include "painelWinLose.h"

	Textura PainelWinLose::winner ("Texturas/Menu/winner.bmp",false);
	Textura PainelWinLose::loser ("Texturas/Menu/loser.bmp",false);
	Textura PainelWinLose::fundo ("Texturas/Menu/painelWL.bmp",false);
	Textura PainelWinLose::botaonextstageS ("Texturas/Menu/Botoes/botaonextstageS.bmp",false);
	Textura PainelWinLose::botaonextstageN ("Texturas/Menu/Botoes/botaonextstageN.bmp",false);
	Textura PainelWinLose::botaoexitS ("Texturas/Menu/Botoes/botaoexitS.bmp",false);
	Textura PainelWinLose::botaoexitN ("Texturas/Menu/Botoes/botaoexitN.bmp",false);

PainelWinLose::PainelWinLose():Painel(){
	this->winner.carregarBMP();
	this->loser.carregarBMP();
	this->fundo.carregarBMP();
	this->botaonextstageS.carregarBMP();
	this->botaonextstageN.carregarBMP();
	this->botaoexitS.carregarBMP();
	this->botaoexitN.carregarBMP();
	this->vencedor = 0;
	this->nJogadores = 0;
}

void PainelWinLose::setNJogadores(int nJogadores) {
	this->nJogadores = nJogadores;
}

void PainelWinLose::setVencedor(int vencedor) {
	this->vencedor = vencedor;
	if(this->vencedor == 1) {
		this->statusJogador1 = &this->winner;
		this->statusJogador2 = &this->loser;
		this->statusJogador3 = &this->loser;
		this->statusJogador4 = &this->loser;
	} else if(this->vencedor == 2) {
		this->statusJogador1 = &this->loser;
		this->statusJogador2 = &this->winner;
		this->statusJogador3 = &this->loser;
		this->statusJogador4 = &this->loser;
	} else if(this->vencedor == 3) {
		this->statusJogador1 = &this->loser;
		this->statusJogador2 = &this->loser;
		this->statusJogador3 = &this->winner;
		this->statusJogador4 = &this->loser;
	} else if(this->vencedor == 4) {
		this->statusJogador1 = &this->loser;
		this->statusJogador2 = &this->loser;
		this->statusJogador3 = &this->loser;
		this->statusJogador4 = &this->winner;
	} else {
		this->statusJogador1 = &this->loser;
		this->statusJogador2 = &this->loser;
		this->statusJogador3 = &this->loser;
		this->statusJogador4 = &this->loser;
	}
}

void PainelWinLose::drawOrtho1Player() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR,GL_ZERO);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, this->statusJogador1->ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1); glVertex2i((WIDTH/2) - 200, (HEIGHT/2) - 300); 
		 glTexCoord2i(1, 1); glVertex2i((WIDTH/2) + 200, (HEIGHT/2) - 300);
		 glTexCoord2i(1, 0); glVertex2i((WIDTH/2) + 200, (HEIGHT/2) - 200);		
		 glTexCoord2i(0, 0); glVertex2i((WIDTH/2) - 200, (HEIGHT/2) - 200);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void PainelWinLose::drawOrtho2Player() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR,GL_ZERO);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, this->statusJogador1->ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1); glVertex2i((WIDTH/2) - 200, (HEIGHT/2) - 300); 
		 glTexCoord2i(1, 1); glVertex2i((WIDTH/2) + 200, (HEIGHT/2) - 300);
		 glTexCoord2i(1, 0); glVertex2i((WIDTH/2) + 200, (HEIGHT/2) - 200);		
		 glTexCoord2i(0, 0); glVertex2i((WIDTH/2) - 200, (HEIGHT/2) - 200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, this->statusJogador2->ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex2i((WIDTH/2) - 200, (HEIGHT/2) + 200); 
		 glTexCoord2i(1, 1);glVertex2i((WIDTH/2) + 200, (HEIGHT/2) + 200);
		 glTexCoord2i(1, 0);glVertex2i((WIDTH/2) + 200, (HEIGHT/2) + 300);		
		 glTexCoord2i(0, 0);glVertex2i((WIDTH/2) - 200, (HEIGHT/2) + 300);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
void PainelWinLose::drawOrtho3Player() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR,GL_ZERO);

	glEnable(GL_TEXTURE_2D);

	//colocar as posicoes das texturas winner e loser

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
void PainelWinLose::drawOrtho4Player() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR,GL_ZERO);

	glEnable(GL_TEXTURE_2D);

	//colocar as posicoes das texturas winner e loser

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void PainelWinLose::drawOrthoPainel() {
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, fundo.ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex3f((WIDTH/2) - 200, (HEIGHT/2) - 100, 0.f); 
		 glTexCoord2i(1, 1);glVertex3f((WIDTH/2) + 200, (HEIGHT/2) - 100, 0.f);
		 glTexCoord2i(1, 0);glVertex3f((WIDTH/2) + 200, (HEIGHT/2) + 100, 0.f);		
		 glTexCoord2i(0, 0);glVertex3f((WIDTH/2) - 200, (HEIGHT/2) + 100, 0.f);
	glEnd();

	if(this->escolha == 0)
		glBindTexture(GL_TEXTURE_2D, botaonextstageS.ID);
	else if(this->escolha == 1)
		glBindTexture(GL_TEXTURE_2D, botaonextstageN.ID);
	glBegin(GL_QUADS);
		glTexCoord2i(0, 1);glVertex3f((WIDTH/2) - 80, (HEIGHT/2) - 40, 1.f); 
		glTexCoord2i(1, 1);glVertex3f((WIDTH/2) + 80, (HEIGHT/2) - 40, 1.f);
		glTexCoord2i(1, 0);glVertex3f((WIDTH/2) + 80, (HEIGHT/2) - 27, 1.f);		
		glTexCoord2i(0, 0);glVertex3f((WIDTH/2) - 80, (HEIGHT/2) - 27, 1.f);
	glEnd();

	if(this->escolha == 0)
		glBindTexture(GL_TEXTURE_2D, botaoexitN.ID);
	else if(this->escolha == 1)
		glBindTexture(GL_TEXTURE_2D, botaoexitS.ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex3f((WIDTH/2) - 80, (HEIGHT/2) + 20, 1.f); 
		 glTexCoord2i(1, 1);glVertex3f((WIDTH/2) + 80, (HEIGHT/2) + 20, 1.f);
		 glTexCoord2i(1, 0);glVertex3f((WIDTH/2) + 80, (HEIGHT/2) + 33, 1.f);		
		 glTexCoord2i(0, 0);glVertex3f((WIDTH/2) - 80, (HEIGHT/2) + 33, 1.f);
	glEnd();
}

void PainelWinLose::drawOrtho(){
	glPushMatrix();
	
	if(this->nJogadores == 1) drawOrtho1Player();
	else if(this->nJogadores == 2) drawOrtho2Player();
	else if(this->nJogadores == 3) drawOrtho3Player();
	else drawOrtho4Player();
	drawOrthoPainel();

	glPopMatrix();
}