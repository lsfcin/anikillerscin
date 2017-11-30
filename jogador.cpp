#include "jogador.h"

Jogador::Jogador() {
	this->nJogadores = 1;
	this->posicao = 1;
	this->camera = new Camera(1);
	this->display = new Display(1,1);
	//o carro default é o chevette
	this->carro = new Chevette(new Ponto(3.95f, -4.02f, 8.45f), new Vetor (0.f, 0.0f, 1.0f),
							   new Vetor(0.0f, 1.0f, 0.0f),Chevette::PRETO);
	this->camera->setPosicaoCamera(new Ponto(), PI/2, 0.f);
	this->life = 100;
}

Jogador::Jogador(Carro *carro, int nJogadores, int posicao) {
	this->carro = carro; //o carro não é setado no construtor
	this->nJogadores = nJogadores;
	this->posicao = posicao;
	this->camera = new Camera(nJogadores);
	this->display = new Display(nJogadores, posicao);
	this->camera->setPosicaoCamera(new Ponto(), PI/2, 0.f);
	this->life = 100;
	this->maxLife = 100;
}

Jogador::~Jogador(){
	delete camera;
	delete carro;
	delete display;
}

void Jogador::draw(){
	this->carro->draw();
}

void Jogador::drawOrtho(){
	this->display->drawOrtho();
	
}

void Jogador::update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado){
	this->tratarTeclado(cima, baixo, esquerda, direita, metralhadora, mina, teleguiado);
	this->display->update(this->life, this->maxLife);
}

void Jogador::tratarTeclado(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado){	
	this->carro->update(cima, baixo, esquerda, direita, metralhadora, mina, teleguiado);	
	this->camera->update(carro);	
}

void Jogador::setNJogadores(int nJogadores) {
	this->nJogadores = nJogadores;
}

void Jogador::setPosicao(int posicao) {
	this->posicao = posicao;
}