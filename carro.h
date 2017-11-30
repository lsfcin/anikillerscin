#ifndef CARRO_H
#define CARRO_H

#include "dinamico.h"
#include "obstaculo.h"
#include "armamento.h"

class Carro : public Dinamico{
	friend class Camera;
public:	
	//Número de Carros diferentes (por tipo)
	const static unsigned int NUM_CARROS = 5;

	// TIPOS DE CARRO
	const static unsigned int CHEVETTE = 0;
	const static unsigned int CHEVETTE_ESCOLIOSE = 1;
	const static unsigned int PICAPE = 2;
	const static unsigned int CORNOCAR = 3;
	const static unsigned int DIABLO = 4;
	

	//Número de Cores diferentes
	const static unsigned int NUM_CORES = 6;
	//CORES DOS CARROS
	const static unsigned int PRETO = 0;
	const static unsigned int VERMELHO = 1;
	const static unsigned int AMARELO = 2;
	const static unsigned int VERDE = 3;
	const static unsigned int ROSA = 4;
	const static unsigned int BRANCO = 5;
	float velocidadeAngular;
	Textura *corEscolhida;
	//roda
	Vetor *roda;
	float velocidadeAngularRoda;
	float anguloRodaCarro;
	float angMaxRodaCarro;
	float anguloVerticalRoda; //variável que armazena o angulo vertical atual da roda...
	Armamento *armas;

public:
	Carro();
	Carro(Ponto *centro, Vetor *n, Vetor *v, float massa, float acel, float velocidadeMaxima,
		  float velocidadeMinima, float angMaxRodaCarro, float dN , float dV , float dU);	
	Carro(const Carro &c );
	Carro & operator=(const Carro &o);
	~Carro();
	Vetor getCameraFrontal() const;
	Vetor getCameraLateral() const;
	void atualizarVetoresEValores();	
	inline float getVelocidade();
	void calcularVelocidadeAngular();
	void reduzirDerrapagem();
	void girarCarro();	
	void girarRoda (int sentido);
	void calcularAnguloRodaCarro();
	void renderBitmapString(int x,int y,void *font,	char *string);
	void drawOrtho();	
	virtual void update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado);	
	virtual void tratarColisaoCarro(Carro &o);
	virtual void tratarColisaoObstaculo(Obstaculo &o);
	virtual void draw() = 0;
	virtual void setCor(int cor) = 0;
};

#endif
