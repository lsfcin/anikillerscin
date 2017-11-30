#ifndef PAINEL_PLAYER_H
#define PAINEL_PLAYER_H
#include "painel.h"
#include "camera.h"
#include "chevette.h"
#include "picape.h"
#include "chevetteEscoliose.h"
#include "cornoCar.h"
#include "diablo.h"

class PainelPlayer: public Painel{
private:
	static Textura tSingleFundo;
	static Textura tOKS;
	static Textura tOK;
	static Textura tSeta;
	static Textura tSetaAmarela;
	static Textura tSetaVermelha;	
	static Textura tSetaVerde;
	static Textura tSetaRosa;
	static Textura tSetaBranca;
	static Textura tSetaPreta;
	static Textura tSetaS;
	Camera * camera;
	Carro *carros[Carro::NUM_CARROS];
	int carroEscolhido;
	double anguloRotacao;
	Textura *setaUp;
	Textura *setaDown;

public:
	PainelPlayer();	
	~PainelPlayer();
	void draw();
	virtual void drawOrtho();
	void setCarroEscolhido(int carroEscolhido);	
	void setCor(int cor);
	void zerarAnguloRotacao();
	Carro & getCarroEscolhido();
};

#endif
