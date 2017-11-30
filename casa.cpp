#include "Casa.h"


Textura Casa :: parede1("Texturas/Obstaculos/Casa1a.bmp", false);
Textura Casa :: parede2("Texturas/Obstaculos/Casa1b.bmp", false);
Textura Casa :: parede3("Texturas/Obstaculos/Casa1c.bmp", false);
Textura Casa :: parede4("Texturas/Obstaculos/posto.bmp", false);
Textura Casa :: teto("Texturas/Obstaculos/metal.bmp", false);

Casa
:: Casa (Ponto *p, Vetor *n, Vetor *v, float dN, float dV, float dU, int opcao)
: Obstaculo(p, n, v, dN, dV, dU, opcao) {
	this->parede1.carregarBMP();
	this->parede2.carregarBMP();
	this->parede3.carregarBMP();
	this->parede4.carregarBMP();
	this->teto.carregarBMP();
}

void Casa :: draw() {
	Textura *temp1, *temp2, *temp3, *temp4, *temp5;

	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);	
	
	switch(this->opcao) {
		case 1:
			temp1 = &this->parede1;		
			temp2 = &this->parede2;		
			temp3 = &this->parede2;		
			temp4 = &this->parede2;	
			temp5 = &this->parede2;
			break;

		case 2:
			temp1 = &this->parede4;		
			temp2 = &this->parede4;		
			temp3 = &this->parede4;		
			temp4 = &this->parede4;	
			temp5 = &this->t10;
			break;

	}

	glBindTexture(GL_TEXTURE_2D, temp1->ID);
	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaN, 0.f);	  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);   glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y, this->extremidades[3]->z);
		glTexCoord2f(0.f, this->deltaV);  glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);
		glTexCoord2f(this->deltaN, this->deltaV);  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);	
	glEnd();
	

	glBindTexture(GL_TEXTURE_2D, temp2->ID);
	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaN, 0.f);	  glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y, this->extremidades[1]->z);
		glTexCoord2f(0.f, 0.f);   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y, this->extremidades[2]->z);
		glTexCoord2f(0.f, this->deltaV);  glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaN, this->deltaV);  glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);	
	glEnd();

	glBindTexture(GL_TEXTURE_2D, temp3->ID);
	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);	  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);   glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y, this->extremidades[1]->z);
		glTexCoord2f(0.f, this->deltaV);  glVertex3f(this->extremidades[1]->x , this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);
		glTexCoord2f(this->deltaU, this->deltaV);  glVertex3f(this->extremidades[0]->x , this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);	
	glEnd();

	glBindTexture(GL_TEXTURE_2D, temp4->ID);
	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);	  glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y, this->extremidades[3]->z);
		glTexCoord2f(0.f, 0.f);   glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y, this->extremidades[2]->z);
		glTexCoord2f(0.f, this->deltaV);  glVertex3f(this->extremidades[2]->x , this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaU, this->deltaV);  glVertex3f(this->extremidades[3]->x , this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);	
	glEnd();

	glBindTexture(GL_TEXTURE_2D, temp5->ID);
	//glBindTexture(GL_TEXTURE_2D, this->teto.ID);
	glBegin(GL_POLYGON);	
		glTexCoord2f(this->deltaU, 0.f);	  glVertex3f(this->extremidades[0]->x, this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);
		glTexCoord2f(0.f, 0.f);   glVertex3f(this->extremidades[1]->x, this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);
		glTexCoord2f(0.f, this->deltaN);  glVertex3f(this->extremidades[2]->x, this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
		glTexCoord2f(this->deltaU, this->deltaN);  glVertex3f(this->extremidades[3]->x, this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);	
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}