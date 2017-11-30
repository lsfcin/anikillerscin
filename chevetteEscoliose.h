#ifndef CHEVETTE_ESCOLIOSE_H
#define CHEVETTE_ESCOLIOSE_H

#include "carro.h"
#include "textura.h"
#include "facesChevette.h"

class ChevetteEscoliose : public Carro{
private:
	static Textura tCarroPreto;
	static Textura tCarroVermelho;
	static Textura tCarroAmarelo;
	static Textura tCarroVerde;
	static Textura tCarroRosa;
	static Textura tCarroBranco;
	static Textura tRoda;
	
public:		
	ChevetteEscoliose(Ponto *centro = new Ponto(0.0f,0.0f,0.0f), Vetor *n = new Vetor(0.0f,0.0f,1.0f), Vetor *v = new Vetor(0.0f,1.0f,0.0f), int cor = PRETO);
	~ChevetteEscoliose();	
	void roda_origem(int raio);
	void desenhaRodas();
	virtual void setCor(int cor);
	virtual void draw();
};
#endif