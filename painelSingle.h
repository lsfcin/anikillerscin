#ifndef PAINEL_SINGLE_H
#define PAINEL_SINGLE_H
#include "painel.h"
#include "camera.h"
#include "chevette.h"
#include "picape.h"
#include "cornoCar.h"
#include "diablo.h"
#include "chevetteEscoliose.h"

class PainelSingle: public Painel{
private:
	static Textura tSingleFundo;
	static Textura tStartS;
	static Textura tStart;
	static Textura tSeta;
	static Textura tSetaAmarela;
	static Textura tSetaVermelha;	
	static Textura tSetaVerde;
	static Textura tSetaRosa;
	static Textura tSetaBranca;
	static Textura tSetaPreta;
	static Textura tSetaS;
	static Textura tBack;
	static Textura tBackS; 
	Camera * camera;
	Carro *carros[Carro::NUM_CARROS];
	int carroEscolhido;
	double anguloRotacao;
	Textura *setaUp;
	Textura *setaDown;

public:
	PainelSingle();	
	~PainelSingle();
	void draw();
	virtual void drawOrtho();
	void setCarroEscolhido(int carroEscolhido);	
	void setCor(int cor);
	void zerarAnguloRotacao();
	Carro & getCarroEscolhido();
};

#endif
