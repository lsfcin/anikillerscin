#include "painelSingle.h"


Textura PainelSingle :: tSingleFundo("Texturas/Menu/menuSinglePlayerPreto.bmp",false);
Textura PainelSingle :: tStartS("Texturas/Menu/Botoes/botaostartS.bmp",false);
Textura PainelSingle :: tStart("Texturas/Menu/Botoes/botaostartN.bmp",false);
Textura PainelSingle :: tBack("Texturas/Menu/Botoes/botaobackN.bmp",false);
Textura PainelSingle :: tBackS("Texturas/Menu/Botoes/botaobackS.bmp",false);
Textura PainelSingle :: tSeta("Texturas/Menu/setaN.bmp",false);
Textura PainelSingle :: tSetaAmarela("Texturas/Menu/setaAmarela.bmp",false);
Textura PainelSingle :: tSetaS("Texturas/Menu/setaS.bmp",false);
Textura PainelSingle :: tSetaVermelha("Texturas/Menu/setaVermelha.bmp",false);	
Textura PainelSingle :: tSetaVerde("Texturas/Menu/setaVerde.bmp",false);
Textura PainelSingle :: tSetaRosa("Texturas/Menu/setaRosa.bmp",false);
Textura PainelSingle :: tSetaBranca("Texturas/Menu/setaBranca.bmp",false);
Textura PainelSingle :: tSetaPreta("Texturas/Menu/setaPreta.bmp",false);
		
PainelSingle :: PainelSingle():Painel(){
	this->tSingleFundo.carregarBMP();
	this->tStartS.carregarBMP();
	this->tStart.carregarBMP();
	this->tSeta.carregarBMP();
	this->tSetaAmarela.carregarBMP();
	this->tSetaS.carregarBMP();
	this->tSetaVermelha.carregarBMP();
	this->tSetaVerde.carregarBMP();
	this->tSetaRosa.carregarBMP();
	this->tSetaBranca.carregarBMP();
	this->tSetaPreta.carregarBMP();
	this->tBack.carregarBMP();
	this->tBackS.carregarBMP();

	this->camera = new Camera();
	this->camera->setPosicaoCamera((new Ponto(0.f, 2.f, -5.f)), PI/2, -PI/8);
	this->carros[Carro::CHEVETTE] = new Chevette();
	this->carros[Carro::CHEVETTE_ESCOLIOSE] = new ChevetteEscoliose();
	this->carros[Carro::PICAPE] = new Picape();
	this->carros[Carro::CORNOCAR] = new CornoCar();
	this->carros[Carro::DIABLO] = new Diablo();
	this->setCarroEscolhido(Carro::CHEVETTE);	
	this->setCor(Carro::PRETO);
	this->anguloRotacao = 269.85;
}

PainelSingle :: ~PainelSingle(){
	delete this->camera;
	delete this->carros[0];
	delete this->carros[1];
}

void PainelSingle::draw(){
	this->camera->fotografar();	

	glPushMatrix();
	glTranslatef(carros[this->carroEscolhido]->centro->x, 0,carros[this->carroEscolhido]->centro->z);
	
	glPushMatrix();
	glRotated(anguloRotacao, 0, 1.f, 0);
	anguloRotacao += 0.15;	
	carros[this->carroEscolhido]->draw();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glScalef(0.02, 0.02, 0.02);
	glBindTexture(GL_TEXTURE_2D, tSingleFundo.ID);
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1); glVertex3f(-200, -120, 50.f);
			glTexCoord2i(1, 1); glVertex3f( 200, -120, 50.f);
			glTexCoord2i(1, 0); glVertex3f( 200,   80, 50.f);
			glTexCoord2i(0, 0); glVertex3f(-200,   80, 50.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void PainelSingle::drawOrtho(){

	// botao voltar
	glEnable(GL_TEXTURE_2D);
	if (escolha == 2){
		glBindTexture(GL_TEXTURE_2D, tBackS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, tBack.ID);
	}
	glBegin(GL_QUADS); 
			glTexCoord2i(0, 1);glVertex2i(WIDTH * 0.1f,			HEIGHT * 0.9f);
			glTexCoord2i(1, 1);glVertex2i(WIDTH * 0.1f + 160.f, HEIGHT * 0.9f);
			glTexCoord2i(1, 0);glVertex2i(WIDTH * 0.1f + 160.f, HEIGHT * 0.9f + 13.f);
			glTexCoord2i(0, 0);glVertex2i(WIDTH * 0.1f,			HEIGHT * 0.9f + 13.f);
	glEnd();


	// botao start game
	if (escolha == 3){
		glBindTexture(GL_TEXTURE_2D, tStartS.ID);
	}else{
		glBindTexture(GL_TEXTURE_2D, tStart.ID);
	}
	glBegin(GL_QUADS); 
		glTexCoord2i(0, 1);glVertex2i(WIDTH * 0.9f - 160.f,	HEIGHT * 0.9f);
		glTexCoord2i(1, 1);glVertex2i(WIDTH * 0.9f,			HEIGHT * 0.9f);
		glTexCoord2i(1, 0);glVertex2i(WIDTH * 0.9f,			HEIGHT * 0.9f + 13.f);
		glTexCoord2i(0, 0);glVertex2i(WIDTH * 0.9f - 160.f, HEIGHT * 0.9f + 13.f);
	glEnd();


	//seta esquerda
	if (escolha == 0){
		if(IsKeyPressed(LEFT))
			glBindTexture(GL_TEXTURE_2D, tSetaAmarela.ID);
		else
			glBindTexture(GL_TEXTURE_2D, tSetaS.ID);

	}else{
		glBindTexture(GL_TEXTURE_2D, tSeta.ID);
	}	
	glBegin(GL_QUADS); 
		glTexCoord2i(0, 1);glVertex2i(WIDTH * 0.15f - tSeta.imageWidth*0.75f, HEIGHT * 0.45f - tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 1);glVertex2i(WIDTH * 0.15f + tSeta.imageWidth*0.75f, HEIGHT * 0.45f - tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 0);glVertex2i(WIDTH * 0.15f + tSeta.imageWidth*0.75f, HEIGHT * 0.45f + tSeta.imageHeight*0.75f);
		glTexCoord2i(0, 0);glVertex2i(WIDTH * 0.15f - tSeta.imageWidth*0.75f, HEIGHT * 0.45f + tSeta.imageHeight*0.75f);
	glEnd();

	//seta direita

	if (escolha == 1){
		if(IsKeyPressed(RIGHT))
			glBindTexture(GL_TEXTURE_2D, tSetaAmarela.ID);
		else
			glBindTexture(GL_TEXTURE_2D, tSetaS.ID);

	}else{
		glBindTexture(GL_TEXTURE_2D, tSeta.ID);
	}

	glBegin(GL_QUADS); 
		glTexCoord2i(0, 1);glVertex2i(WIDTH * 0.85f + tSeta.imageWidth*0.75f, HEIGHT * 0.45f - tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 1);glVertex2i(WIDTH * 0.85f - tSeta.imageWidth*0.75f, HEIGHT * 0.45f - tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 0);glVertex2i(WIDTH * 0.85f - tSeta.imageWidth*0.75f, HEIGHT * 0.45f + tSeta.imageHeight*0.75f);
		glTexCoord2i(0, 0);glVertex2i(WIDTH * 0.85f + tSeta.imageWidth*0.75f, HEIGHT * 0.45f + tSeta.imageHeight*0.75f);
	glEnd();

	//seta UP
	glBindTexture(GL_TEXTURE_2D, setaUp->ID);
	glBegin(GL_QUADS); 
		glTexCoord2i(0, 0);glVertex2i(WIDTH * 0.5f - tSeta.imageWidth*0.75f, HEIGHT * 0.25f - tSeta.imageHeight*0.75f);
		glTexCoord2i(0, 1);glVertex2i(WIDTH * 0.5f + tSeta.imageWidth*0.75f, HEIGHT * 0.25f - tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 1);glVertex2i(WIDTH * 0.5f + tSeta.imageWidth*0.75f, HEIGHT * 0.25f + tSeta.imageHeight*0.75f);
		glTexCoord2i(1, 0);glVertex2i(WIDTH * 0.5f - tSeta.imageWidth*0.75f, HEIGHT * 0.25f + tSeta.imageHeight*0.75f);
	glEnd();

	glDisable(GL_TEXTURE_2D);	
}

void PainelSingle::setCarroEscolhido(int carroEscolhido){	
		this->carroEscolhido = carroEscolhido;	
}

void PainelSingle::setCor(int cor){	
	this->carros[this->carroEscolhido]->setCor(cor);
	if(this->escolha == 4){
		int corUp = (cor +1) % Carro::NUM_CORES;

		switch(corUp){
			case Carro::PRETO:
				this->setaUp = &this->tSetaPreta;
				break;
			case Carro::VERMELHO:
				this->setaUp = &this->tSetaVermelha;
				break;
			case Carro::AMARELO:
				this->setaUp = &this->tSetaAmarela;
				break;
			case Carro::VERDE:
				this->setaUp = &this->tSetaVerde;
				break;
			case Carro::ROSA:
				this->setaUp = &this->tSetaRosa;
				break;
			case Carro::BRANCO:
				this->setaUp = &this->tSetaBranca;
				break;
			default:
				this->setaUp = &this->tSetaPreta;
				break;			
		}
	}else{
		this->setaUp = &this->tSeta;
	}

}

void PainelSingle::zerarAnguloRotacao(){
	this->anguloRotacao = 269.85;
}

Carro  & PainelSingle::getCarroEscolhido(){
	return *this->carros[this->carroEscolhido];
}
