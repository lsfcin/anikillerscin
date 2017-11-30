#include "mundo.h"
#include <cstdlib>

Mundo::Mundo(int opcao) {
	for (int i = 0;i < 50;i++)
		this->obstaculos[i] = 0;
	
	this->opcao = opcao;

	switch (opcao) {
		case 1:
			this->pintarObstaculos();
			this->texturaChao = new Textura("Texturas/Cenario/asfalto2.bmp",true, true);	
			this->texturaGrama = new Textura("Texturas/Cenario/grama3.bmp",true, true);	
			this->texturaHorizonte = new Textura("Texturas/Cenario/horizonte3.bmp",true);	
			break;
		case 2:
			this->pintarObstaculos();
			this->texturaChao = new Textura("Texturas/Cenario/chao2.bmp",true, true);	
			this->texturaGrama = new Textura("Texturas/Cenario/grama2.bmp",true);	
			this->texturaHorizonte = new Textura("Texturas/Cenario/horizonte1.bmp",true);	
			break;
	}
}

Mundo::~Mundo(){
	delete texturaChao;
	delete texturaGrama;
	delete texturaHorizonte;
}

void Mundo::draw(){
	glPushMatrix();
	glScalef(4.f, 4.f, 4.f);
	glTranslatef(0.0f,-1.0f,0.0f);
	glEnable(GL_TEXTURE_2D);	
	
	glBindTexture(GL_TEXTURE_2D, this->texturaChao->ID); //desenhando o chão...
	
	glBegin(GL_QUADS);	
		glTexCoord2f(0.0f, 0.0f);   glVertex3f(-20.0f, 0.0f, -20.0f);
		glTexCoord2f(0.0f, 200.0f);  glVertex3f(-20.0f, 0.0f,  20.0f);
		glTexCoord2f(200.0f, 200.0f); glVertex3f(20.0f, 0.0f, 20.0f);
		glTexCoord2f(200.0f, 0.0f);  glVertex3f(20.0f, 0.0f, -20.0f);		
	glEnd();
	
	
	glBindTexture(GL_TEXTURE_2D, this->texturaGrama->ID); //desenhando a grama...

	glBegin(GL_QUADS);	
		glTexCoord2f(0.0f, 0.0f);     glVertex3f(-200.0f, -0.1f, -200.0f);
		glTexCoord2f(0.0f, 500.0f);   glVertex3f(-200.0f, -0.1f,  200.0f);
		glTexCoord2f(500.0f, 500.0f); glVertex3f(200.0f, -0.1f, 200.0f);
		glTexCoord2f(500.0f, 0.0f);   glVertex3f(200.0f, -0.1f, -200.0f);		
	glEnd();


	glBindTexture(GL_TEXTURE_2D, this->texturaHorizonte->ID); //desenhando o horizonte...
	
	glBegin(GL_QUADS);	//frente do horizonte...
		glTexCoord2f(0.0f, 0.0f);   glVertex3f(-200.0f , -0.1f, -200.0f);
		glTexCoord2f(0.0f, 1.f);    glVertex3f(-200.0f, 200.1f, -200.0f);
		glTexCoord2f(0.25f, 1.f);   glVertex3f(200.0f , 200.1f, -200.0f);
		glTexCoord2f(0.25f, 0.0f);  glVertex3f(200.0f , -0.1f, -200.0f);		
	glEnd();
	
	glBegin(GL_QUADS);	//direta do horizonte...
		glTexCoord2f(0.25f, 0.f);   glVertex3f(200.0f, -0.1f, -200.0f);
		glTexCoord2f(0.25f, 1.f);	glVertex3f(200.0f, 200.1f, -200.0f);
		glTexCoord2f(0.5f, 1.f);	glVertex3f(200.0f, 200.1f, 200.0f);
		glTexCoord2f(0.5f, 0.f);	glVertex3f(200.0f, -0.1f, 200.0f);		
	glEnd();

	glBegin(GL_QUADS);	//fundo do horizonte...
		glTexCoord2f(0.5f, 0.f);    glVertex3f(200.0f , -0.1f, 200.0f);
		glTexCoord2f(0.5f, 1.f);    glVertex3f(200.0f, 200.1f, 200.0f);
		glTexCoord2f(0.75f, 1.f);   glVertex3f(-200.0f , 200.1f, 200.0f);
		glTexCoord2f(0.75f, 0.f);   glVertex3f(-200.0f , -0.1f, 200.0f);	
	glEnd();

	glBegin(GL_QUADS);	//esquerda do horizonte...
		glTexCoord2f(0.75f, 0.f);   glVertex3f(-200.0f, -0.1f, 200.0f);
		glTexCoord2f(0.75f, 1.f);   glVertex3f(-200.0f, 200.1f, 200.0f);
		glTexCoord2f(1.f, 1.f);     glVertex3f(-200.0f, 200.1f, -200.0f);
		glTexCoord2f(1.f, 0.f);     glVertex3f(-200.0f, -0.1f, -200.0f);		
	glEnd();

	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
		

	for(int i = 0;i < 50;i++){
		if(this->obstaculos[i] != NULL){
			this->obstaculos[i]->draw();
		}
	}
/*
	int temp = 0;

	if (this->itemAtual == NULL)
		temp = (rand()%5);
		
		switch(temp) {
			case 0:
				this->itemAtual = new ItemLife (new Ponto((rand()%80), (rand()%80), (rand()%80)),
									new Vetor (1.f, 0.0f, 0.f),
									new Vetor(0.0f, 1.0f, 0.0f) , 
									0.01f, 0.01f, 0.01f); 
				break;

			case 1:
				this->itemAtual = new ItemMoeda (new Ponto((rand()%80), (rand()%80), (rand()%80)),
									new Vetor (1.f, 0.0f, 0.f),
									new Vetor(0.0f, 1.0f, 0.0f) , 
									0.01f, 0.01f, 0.01f); 
				break;
			case 2:
				this->itemAtual = new ItemMissel (new Ponto((rand()%80), (rand()%80), (rand()%80)),
									new Vetor (1.f, 0.0f, 0.f),
									new Vetor(0.0f, 1.0f, 0.0f) , 
									0.01f, 0.01f, 0.01f); 
				break;
			case 3:
				this->itemAtual = new ItemMina (new Ponto((rand()%80), (rand()%80), (rand()%80)),
									new Vetor (1.f, 0.0f, 0.f),
									new Vetor(0.0f, 1.0f, 0.0f) , 
									0.01f, 0.01f, 0.01f); 
				break;
			case 4:
				this->itemAtual = new ItemPontos (new Ponto((rand()%80), (rand()%80), (rand()%80)),
									new Vetor (1.f, 0.0f, 0.f),
									new Vetor(0.0f, 1.0f, 0.0f) , 
									0.01f, 0.01f, 0.01f); 
				break;
		}*/

		
}


void Mundo::pintarObstaculos(){
	
	switch(this->opcao) {
		case 1:
			this->obstaculos[0] = new Obstaculo(new Ponto(80.f, -4.02f, 0.f), new Vetor (0.f, 0.0f, 1.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 6);
			this->obstaculos[1] = new Obstaculo(new Ponto(-80.f, -4.02f, 0.f), new Vetor (0.f, 0.0f, 1.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 6);
			this->obstaculos[2] = new Obstaculo(new Ponto(0.f, -4.02f, 80.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 6);
			this->obstaculos[3] = new Obstaculo(new Ponto(0.f, -4.02f, -80.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 6);
			
			
			this->obstaculos[4] = new Obstaculo(new Ponto(8.f, -4.02f, 27.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.1f, 1.0f, 0.1f, 8);			
			this->obstaculos[5] = new Obstaculo(new Ponto(8.f, -3.02f, 27.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 0.01f, 5);
						
			
			this->obstaculos[6] = new Obstaculo(new Ponto(-50.f, -4.02f, 27.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[7] = new Obstaculo(new Ponto(67.f, -4.02f, 12.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[8] = new Obstaculo(new Ponto(-8.f, -4.02f, -70.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[9] = new Obstaculo(new Ponto(51.f, -4.02f, -57.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[6] = new Obstaculo(new Ponto(50.f, -4.02f, 12.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[7] = new Obstaculo(new Ponto(7.f, -4.02f, 2.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[8] = new Obstaculo(new Ponto(45.f, -4.02f, -32.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[9] = new Obstaculo(new Ponto(-51.f, -4.02f, 57.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[21] = new Obstaculo(new Ponto(5.32f, -4.02f, 20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[22] = new Obstaculo(new Ponto(-60.f, -4.02f, -12.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[23] = new Obstaculo(new Ponto(-10.f, -4.02f, 3.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);
			this->obstaculos[24] = new Obstaculo(new Ponto(-2.f, -4.02f, -57.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 8);



			this->obstaculos[10] = new Casa(new Ponto(-25.f, -4.02f, 68.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[25] = new Casa(new Ponto(21.f, -4.02f, 68.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[26] = new Casa(new Ponto(0.f, -4.02f, 38.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[27] = new Casa(new Ponto(33.f, -4.02f, -68.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[28] = new Casa(new Ponto(25.f, -4.02f, -80.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[30] = new Casa(new Ponto(-55.f, -4.02f, 0.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[31] = new Casa(new Ponto(-70.f, -4.02f, 68.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);
			this->obstaculos[32] = new Casa(new Ponto(55.f, -4.02f, -27.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.0f, 1.0f, 1.f, 1);

			
			
			this->obstaculos[11] = new Igreja(new Ponto(-12.f, -4.02f, 47.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9);


			this->obstaculos[13] = new Obstaculo(new Ponto(-50.f, -4.02f, 10.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9);
			this->obstaculos[15] = new Obstaculo(new Ponto(0.f, -4.02f, -20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9);
			this->obstaculos[18] = new Obstaculo(new Ponto(20.f, -4.02f, 19.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9);
			this->obstaculos[19] = new Obstaculo(new Ponto(55.f, -4.02f, 11.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9);
			this->obstaculos[20] = new Obstaculo(new Ponto(39.f, -4.02f, -40.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.5f, 2.5f, 0.5f, 9); 

			this->obstaculos[33] = new Obstaculo(new Ponto(75.f, -4.02f, 75.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 3.5f, 0.5f, 10);
			this->obstaculos[34] = new Obstaculo(new Ponto(75.f, -4.02f, 55.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 3.5f, 0.5f, 10);
			this->obstaculos[35] = new Obstaculo(new Ponto(55.f, -4.02f, 55.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 3.5f, 0.5f, 10);
			this->obstaculos[36] = new Obstaculo(new Ponto(55.f, -4.02f, 75.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 3.5f, 0.5f, 10);
			

			this->obstaculos[32] = new Casa(new Ponto(65.f, -1.5f, 65.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 15.f, 1.f, 15.f, 2);
			
			


			break;

		case 2:	
			this->obstaculos[0] = new Obstaculo(new Ponto(80.f, -4.02f, 0.f), new Vetor (0.f, 0.0f, 1.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 1);
			this->obstaculos[1] = new Obstaculo(new Ponto(-80.f, -4.02f, 0.f), new Vetor (0.f, 0.0f, 1.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 1);
			this->obstaculos[2] = new Obstaculo(new Ponto(0.f, -4.02f, 80.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 1);
			this->obstaculos[3] = new Obstaculo(new Ponto(0.f, -4.02f, -80.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 80.f, 0.5f, 0.5f, 1);
			
			this->obstaculos[4] = new Obstaculo(new Ponto(10.f, -4.02f, 20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[5] = new Obstaculo(new Ponto(30.f, -4.02f, 20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[6] = new Obstaculo(new Ponto(40.f, -4.02f, -20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[7] = new Obstaculo(new Ponto(50.f, -4.02f, 0.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[8] = new Obstaculo(new Ponto(0.f, -4.02f, -20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[9] = new Obstaculo(new Ponto(60.f, -4.02f, 60.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[16] = new Obstaculo(new Ponto(45.f, -4.02f, -39.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[17] = new Obstaculo(new Ponto(12.f, -4.02f, -74.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[28] = new Obstaculo(new Ponto(10.f, -4.02f, -60.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[29] = new Obstaculo(new Ponto(-32.f, -4.02f, 67.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
			this->obstaculos[30] = new Obstaculo(new Ponto(-13.f, -4.02f, 59.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.f, 5.5f, 2.0f, 3);
								
			this->obstaculos[10] = new Obstaculo(new Ponto(0.f, -4.02f, 0.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[10] = new Obstaculo(new Ponto(10.f, -4.02f, -20.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[11] = new Obstaculo(new Ponto(-10.f, -4.02f, 27.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[12] = new Obstaculo(new Ponto(67.f, -4.02f, -54.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[13] = new Obstaculo(new Ponto(50.f, -4.02f, 10.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[14] = new Obstaculo(new Ponto(10.f, -4.02f, 50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[15] = new Obstaculo(new Ponto(-50.f, -4.02f, -50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[18] = new Obstaculo(new Ponto(33.f, -4.02f, 19.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[19] = new Obstaculo(new Ponto(-51.f, -4.02f, 11.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);
			this->obstaculos[20] = new Obstaculo(new Ponto(39.f, -4.02f, -40.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 0.5f, 0.5f, 0.5f, 4);

			this->obstaculos[21] = new Obstaculo(new Ponto(-60.f, -4.02f, 50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 10.f, 2.f, 10.f, 4);
			this->obstaculos[22] = new Obstaculo(new Ponto(-60.f, -4.02f, 50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 5.f, 4.f, 5.f, 4);
			this->obstaculos[23] = new Obstaculo(new Ponto(-60.f, -4.02f, 50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.50f, 6.f, 2.5f, 4);
			this->obstaculos[24] = new Obstaculo(new Ponto(-60.f, -4.02f, 50.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.f, 8.f, 1.f, 4);


			this->obstaculos[25] = new Obstaculo(new Ponto(-0.4f, -4.02f, 35.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 5.f, 2.f, 5.f, 4);
			this->obstaculos[26] = new Obstaculo(new Ponto(-0.4f, -4.02f, 35.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 2.50f, 4.f, 2.5f, 4);
			this->obstaculos[27] = new Obstaculo(new Ponto(-0.4f, -4.02f, 35.f), new Vetor (1.f, 0.0f, 0.f),
										  new Vetor(0.0f, 1.0f, 0.0f) , 1.f, 6.f, 1.f, 4);
			
			break;
		}
}

/*void Mundo::drawOrtho(){
	if(this->painelEscapeAtivo)
		this->pEscape->drawOrtho();
	else if(this->painelHelpAtivo)
		this->pHelp->drawOrtho();

}*/

/*void Mundo::update(){
	static int escolha = 1;
	if(this->painelEscape){
		if (IsKeyPressed(UP)){
			if(this->timerTeclado->passouTempo()){
				if(escolha == 1)
					escolha = 3;
				else
					escolha--;		
			}
		}
		if (IsKeyPressed(DOWN)){
			if(this->timerTeclado->passouTempo()){
				if(escolha == 3){
					escolha = 1;
				}else{
					escolha++;
				}
			}
		}
		if (IsKeyPressed(ENTER) && this->timerTeclado->passouTempo()){
			if(this->timerEscape->passouTempo() && escolha == 1){
				this->painelEscape = false;		
			//	this->timerEscape->zerar();
			}else if(escolha == 2){				
				this->painelEscape = false;
				this->painelHelp = true;
			}else if(escolha == 3){
				this->ativo = false;
				this->painelEscape = false;
				this->destruir = true;
			}
		}else if (IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo() && this->timerEscape->passouTempo()){
			this->painelEscape = false;
			//this->timerEscape->zerar();
		}
		this->pEscape->setEscolha(escolha);


	}else if(this->painelHelp){
		if(IsKeyPressed(ENTER) && this->timerTeclado->passouTempo()){
			this->painelEscape = true;
			this->painelHelp = false;
		}else if(IsKeyPressed(ESCAPE) && this->timerTeclado->passouTempo()){
			this->painelEscape = true;
			this->painelHelp = false;		
		}
			
	}else if(this->ativo){
		if(IsKeyPressed(ESCAPE) && this->timerEscape->passouTempo() )
			this->painelEscape = true;					
	}

}*/