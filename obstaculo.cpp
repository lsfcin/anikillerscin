#include "obstaculo.h"

Textura Obstaculo :: t1 ("Texturas/Obstaculos/obstaculo1.bmp",false);
Textura Obstaculo :: t2 ("Texturas/Obstaculos/predio3.bmp",false);
Textura Obstaculo :: t3 ("Texturas/Obstaculos/parede4.bmp",false);
Textura Obstaculo :: t4 ("Texturas/Obstaculos/parede3.bmp", false);
Textura Obstaculo :: t5 ("Texturas/Obstaculos/stop.bmp", false);
Textura Obstaculo :: t6 ("Texturas/Obstaculos/parede5.bmp", false);
Textura Obstaculo :: t7 ("Texturas/Cenario/asfalto2.bmp", false);
Textura Obstaculo :: t8 ("Texturas/Obstaculos/caixas.bmp", false);
Textura Obstaculo :: t9 ("Texturas/Obstaculos/pedra1.bmp", false);
Textura Obstaculo :: t10("Texturas/Obstaculos/metal.bmp", false);

Obstaculo :: Obstaculo(Ponto *p, Vetor *n, Vetor *v, float dN,float dV, float dU, int opcao)
	:Objeto3D(p,n,v,dN,dV,dU){

	this->t1.carregarBMP();
	this->t2.carregarBMP();
	this->t3.carregarBMP();
	this->t4.carregarBMP();
	this->t5.carregarBMP();
	this->t6.carregarBMP();
	this->t7.carregarBMP();
	this->t8.carregarBMP();
	this->t9.carregarBMP();
	this->t10.carregarBMP();

	this->opcao = opcao;
}


void Obstaculo :: draw(){
	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);	

	if (this->opcao == 1)
		glBindTexture(GL_TEXTURE_2D, this->t1.ID);
	if (this->opcao == 2)
		glBindTexture(GL_TEXTURE_2D, this->t2.ID);
	if (this->opcao == 3)
		glBindTexture(GL_TEXTURE_2D, this->t3.ID);
	if (this->opcao == 4)
		glBindTexture(GL_TEXTURE_2D, this->t4.ID);
	if (this->opcao == 5)
		glBindTexture(GL_TEXTURE_2D, this->t5.ID);
	if (this->opcao == 6)
		glBindTexture(GL_TEXTURE_2D, this->t6.ID);
	if (this->opcao == 7)
		glBindTexture(GL_TEXTURE_2D, this->t7.ID);
	if (this->opcao == 8)
		glBindTexture(GL_TEXTURE_2D, this->t8.ID);
	if (this->opcao == 9)
		glBindTexture(GL_TEXTURE_2D, this->t9.ID);
	if (this->opcao == 10)
		glBindTexture(GL_TEXTURE_2D, this->t10.ID);

	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaN, 0.f);		   glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);					   glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y, this->extremidades[3]->z);
		glTexCoord2f(0.f, this->deltaV);		   glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);
		glTexCoord2f(this->deltaN, this->deltaV);  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);	
	glEnd();

	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaN, 0.f);		   glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y, this->extremidades[1]->z);
		glTexCoord2f(0.f, 0.f);					   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y, this->extremidades[2]->z);
		glTexCoord2f(0.f, this->deltaV);		   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaN, this->deltaV);  glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);	
	glEnd();

	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);		   glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);					   glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y, this->extremidades[1]->z);
		glTexCoord2f(0.f, this->deltaV);		   glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);
		glTexCoord2f(this->deltaU, this->deltaV);  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);	
	glEnd();

	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);		   glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y, this->extremidades[3]->z);
		glTexCoord2f(0.f, 0.f);					   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y, this->extremidades[2]->z);
		glTexCoord2f(0.f, this->deltaV);		   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaU, this->deltaV);  glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);	
	glEnd();

	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);		   glVertex3f(this->extremidades[0]->x, this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);					   glVertex3f(this->extremidades[1]->x, this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);
		glTexCoord2f(0.f, this->deltaN);		   glVertex3f(this->extremidades[2]->x, this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaU, this->deltaN);  glVertex3f(this->extremidades[3]->x, this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);	
	glEnd();
	
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();


}