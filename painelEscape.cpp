#include "painelEscape.h"

	Textura PainelEscape ::tExit("Texturas/Menu/Botoes/botaoexitN.bmp",false);
	Textura PainelEscape ::tExitS("Texturas/Menu/Botoes/botaoexitS.bmp",false);
	Textura PainelEscape ::tHelp("Texturas/Menu/Botoes/botaohelpN.bmp",false);	
	Textura PainelEscape ::tHelpS("Texturas/Menu/Botoes/botaohelpS.bmp",false);
	Textura PainelEscape ::tReturn("Texturas/Menu/Botoes/botaoreturntogameN.bmp",false);	
	Textura PainelEscape ::tReturnS("Texturas/Menu/Botoes/botaoreturntogameS.bmp",false);
	Textura PainelEscape ::tFundoEscape("Texturas/Menu/painelWL.bmp",false);

PainelEscape :: PainelEscape():Painel(){	
	this->tExit.carregarBMP();
	this->tExitS.carregarBMP();
	this->tHelp.carregarBMP();
	this->tHelpS.carregarBMP();
	this->tReturn.carregarBMP();
	this->tReturnS.carregarBMP();
	this->tFundoEscape.carregarBMP();			
}

void PainelEscape::drawOrtho(){
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tFundoEscape.ID);
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex2f((WIDTH/2) - 200, (HEIGHT/2) - 80); 
		 glTexCoord2i(1, 1);glVertex2f((WIDTH/2) + 200, (HEIGHT/2) - 80);
		 glTexCoord2i(1, 0);glVertex2f((WIDTH/2) + 200, (HEIGHT/2) + 80);		
		 glTexCoord2i(0, 0);glVertex2f((WIDTH/2) - 200, (HEIGHT/2) + 80);
	glEnd();

	glTranslated(0.f, 0.f, 0.1f);
	if (escolha == 1){
		glBindTexture(GL_TEXTURE_2D, tReturnS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, tReturn.ID);
	}
	glBegin(GL_QUADS);
		glTexCoord2i(0, 1);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) - 40); 
		glTexCoord2i(1, 1);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) - 40);
		glTexCoord2i(1, 0);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) - 27);		
		glTexCoord2i(0, 0);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) - 27);
	glEnd();

	if (escolha == 2){
		glBindTexture(GL_TEXTURE_2D, tHelpS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, tHelp.ID);
	}
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) - 10); 
		 glTexCoord2i(1, 1);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) - 10);
		 glTexCoord2i(1, 0);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) + 3);		
		 glTexCoord2i(0, 0);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) + 3);
	glEnd();
	
	if (escolha == 3){
		glBindTexture(GL_TEXTURE_2D, tExitS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, tExit.ID);
	}
	glBegin(GL_QUADS);
		 glTexCoord2i(0, 1);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) + 20); 
		 glTexCoord2i(1, 1);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) + 20);
		 glTexCoord2i(1, 0);glVertex2f((WIDTH/2) + 80, (HEIGHT/2) + 33);		
		 glTexCoord2i(0, 0);glVertex2f((WIDTH/2) - 80, (HEIGHT/2) + 33);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	glPopMatrix();


}