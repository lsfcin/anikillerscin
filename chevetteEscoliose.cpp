#include "chevetteEscoliose.h"
#define RadParaGraus(a) a*180/PI

Textura ChevetteEscoliose::tCarroPreto("Texturas/Carros/ChevetteEscoliose/cPreto.bmp",false);
Textura ChevetteEscoliose::tCarroVermelho("Texturas/Carros/ChevetteEscoliose/cVermelho.bmp",false);
Textura ChevetteEscoliose::tCarroAmarelo("Texturas/Carros/ChevetteEscoliose/cAmarelo.bmp",false);
Textura ChevetteEscoliose::tCarroVerde("Texturas/Carros/ChevetteEscoliose/cVerde.bmp",false);
Textura ChevetteEscoliose::tCarroRosa("Texturas/Carros/ChevetteEscoliose/cRosa.bmp",false);
Textura ChevetteEscoliose::tCarroBranco("Texturas/Carros/ChevetteEscoliose/cBranco.bmp",false);
Textura ChevetteEscoliose::tRoda("Texturas/Carros/Chevette/roda.bmp",false);


ChevetteEscoliose::ChevetteEscoliose(Ponto *centro,Vetor *n, Vetor *v, int cor): Carro(centro, n, v,10.0f, 0.01f, 0.4f,0.08f, 1.0f, 0.5f,0.36f,0.2f){
	this->setCor(cor);
	this->tRoda.carregarBMP();
}

ChevetteEscoliose::~ChevetteEscoliose(){

}

void ChevetteEscoliose::draw() {	

	int i, j;
	float Vx, Vy, Vz;
	float s, t;
	static Vetor canonico(1.0f, 0.0f, 0.0f);

	this->armas->draw();

	glPushMatrix();	
	glTranslatef(this->centro->x,this->centro->y,this->centro->z);
	glScalef(0.02, 0.02, 0.02);
	glTranslatef(0, -this->centro->y, 0);  
	glColor3f(0.8,0.8,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->corEscolhida->ID);
	Vetor * temp = new Vetor();
	*temp = n->produtoVetorial(canonico);
	float produtoInterno = n->produtoInterno(canonico);
	float a = acos(produtoInterno);
	this->angulo = RadParaGraus(a);
	if(temp->y > 0.f) 
		this->angulo = -this->angulo;	
	
	delete temp;	
	glRotated(this->angulo, 0, 1, 0);

	glBegin(GL_TRIANGLES);
			for(i=0;i<26;i++) //lateral direita do carro....
					for(j=0;j<3;j++) {
							Vx = modeloCarro[i][j][0]; Vy = modeloCarro[i][j][1]; Vz = modeloCarro[i][j][2];
							s = (Vx+22)/48;  t = (Vy/44.44)+0.17;
							glTexCoord2f(s,t); glVertex3d(Vx,Vy,Vz);
					}            
            
			for(i=26;i<78;i++) // Interior Direito 26
					for(j=0;j<3;j++) {
							Vx = modeloCarro[i][j][0]; Vy = modeloCarro[i][j][1]; Vz = modeloCarro[i][j][2];
							s = (Vx+22)/48;  t = 0.6-0.025*Vz;
							glTexCoord2f(s,t); glVertex3d(Vx,Vy,Vz);
					}            
            
			for(i=78;i<104;i++) // Lateral Esquerda 78 - 104
					for(j=0;j<3;j++) {
							Vx = modeloCarro[i][j][0]; Vy = modeloCarro[i][j][1]; Vz = modeloCarro[i][j][2];
							s = (Vx+21)/48;  t = (Vy/44.44)+0.17;
							glTexCoord2f(s,t); glVertex3d(Vx,Vy,Vz);
					}            
            
			for(i=104;i<156;i++)  // Interior Esquerdo 104 - 156
					for(j=0;j<3;j++) {
							Vx = modeloCarro[i][j][0]; Vy = modeloCarro[i][j][1]; Vz = modeloCarro[i][j][2];
							s = (Vx+22)/48;  t = 0.6-0.022*Vz;
							glTexCoord2f(s,t); glVertex3d(Vx,Vy,Vz);
					}            				
            
			glDisable(GL_TEXTURE_2D);
			glColor3f(0.5,0.5,0.5);
			for(i=156;i<NUMEROFACESCARRO;i++)   //detalhes como o escapamento...
					for(j=0;j<3;j++) {
							Vx = modeloCarro[i][j][0]; Vy = modeloCarro[i][j][1]; Vz = modeloCarro[i][j][2];
							glVertex3d(Vx,Vy,Vz);
					}
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	

    glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tRoda.ID);
	desenhaRodas();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void ChevetteEscoliose::roda_origem(int raio) { //método que desenha uma roda na origem para que depois ela possa ser colocada na sua posição devida...

	float ang;
	float inc_ang = PI/20;
	float posicao = 0;	

	for(ang=0; ang<=2*PI; ang+=inc_ang) {
			if(ang+inc_ang>2*PI) inc_ang = 2*PI-ang;

			glBegin(GL_TRIANGLES);
					glNormal3f(0,0,1);
					glTexCoord2f(0.25, 0.75);
					glVertex3f(0.0,0.0,0.0);
					glTexCoord2f(0.25*cos(ang)+0.25,0.25*sin(ang)+0.75);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), 0.0);
					glTexCoord2f(0.25*cos(ang+inc_ang)+0.25,0.25* sin(ang+inc_ang)+0.75);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), 0.0);

					glNormal3f(0,0,-1);
					glTexCoord2f(0.25, 0.75);
					glVertex3f(0.0,0.0,-2.6);
					glTexCoord2f(0.25*cos(ang+inc_ang)+0.25,0.25* sin(ang+inc_ang)+0.75);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), -2.6);
					glTexCoord2f(0.25*cos(ang)+0.25,0.25*sin(ang)+0.75);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), -2.6);
			glEnd();

			glBegin(GL_QUADS);
			Vetor *a = new Vetor(0.0f, 0.0f, -2.6f);
			Vetor *b = new Vetor((raio*(cos(ang+inc_ang)-cos(ang))), 
									 (raio*(sin(ang+inc_ang)-sin(ang))),
									 0);
			Vetor *resultante = new Vetor();
			*resultante = a->produtoVetorial(*b);
			glNormal3f(resultante->x, resultante->y, resultante->z);

			delete a;
			delete b;
			delete resultante;

					glTexCoord2f(posicao,0.15);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), 0.0);
					glTexCoord2f(posicao,0.1);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), -2.6);
					glTexCoord2f(posicao+(1/20),0.15);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), -2.6);
					glTexCoord2f(posicao+(1/20),0.1);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), 0.0);
			glEnd();
			posicao += 1/20;
	}
}

void ChevetteEscoliose::desenhaRodas() { //método que desenha as rodas girando...
	int static raio = 3;
	float velocidade = this->velocidade->norma();

	if(this->mRetrogrado())
		velocidade = -velocidade;

	this->anguloVerticalRoda += velocidade *900;
		
	// Desenha as rodas dianteiras que só giram

	glPushMatrix();
			glTranslatef(14.1,0.3,10.1);
			glRotatef(-anguloRodaCarro*30,0,1,0);
			glRotatef(-anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(14.1,0.3,-10.1);
			glRotatef(-(180+anguloRodaCarro*30),0,1,0);
			glRotatef(anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();

	// Desenha as rodas traseiras
	glPushMatrix();
			glTranslatef(-14.1,0.3,10.1);
			glRotatef(-anguloVerticalRoda*1.11,0,0,1);	
			roda_origem(raio);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(-14.1,0.3,-10.1);
			glRotatef(180,0,1,0);
			glRotatef(anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();
	glFlush();
	
}

void ChevetteEscoliose::setCor(int cor){
	switch(cor){
		case PRETO:
			this->corEscolhida = &this->tCarroPreto;
			break;
		case VERMELHO:
			this->corEscolhida = &this->tCarroVermelho;
			break;
		case AMARELO:
			this->corEscolhida = &this->tCarroAmarelo;
			break;
		case VERDE:
			this->corEscolhida = &this->tCarroVerde;
			break;
		case ROSA:
			this->corEscolhida = &this->tCarroRosa;
			break;
		case BRANCO:
			this->corEscolhida = &this->tCarroBranco;
			break;
		default:
			this->corEscolhida = &this->tCarroPreto;
			break;			
	}
	this->corEscolhida->carregarBMP();
}