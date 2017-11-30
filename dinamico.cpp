#include "dinamico.h"



Dinamico::Dinamico(): Objeto3D(){
	this->acel = 0.01f;
	this->freio = this->acel * 5.0f;
	this->resistencia = this->acel * 0.7f;
	this->velocidadeMaxima = 0.5f;
	this->velocidadeMinima = 0.1f;
	this->velocidade = new Vetor();
	this->aceleracao = new Vetor();
	this->massa = 1.0f;
}

Dinamico::Dinamico(Ponto *centro,Vetor *n, Vetor *v, float massa, float acel, float velocidadeMaxima,
				   float velocidadeMinima, float dN , float dV , float dU)
	:Objeto3D(centro,n,v,dN,dV,dU){
	this->massa = massa;
	this->acel = acel;
	this->freio = this->acel * 5.0f;
	this->resistencia = this->acel * 0.7f;
	this->velocidadeMaxima = velocidadeMaxima;
	this->velocidadeMinima = velocidadeMinima;
	this->velocidade = new Vetor();
	this->aceleracao = new Vetor();
}




Dinamico::~Dinamico(){
	delete this->aceleracao;
	delete this->velocidade;	
}

bool Dinamico::repouso(){
	bool retorno = false;
	if(this->velocidade->vetorNulo())	
			retorno = true;				
	return retorno;
}

bool Dinamico::mProgressivo(){
	bool retorno = false;
	if(!this->velocidade->vetorNulo() && this->velocidade->produtoInterno(*this->n) >= 0.0f )	
			retorno = true;				
	return retorno;
}

bool Dinamico::mRetrogrado() const{
	bool retorno = false;
	if(!this->velocidade->vetorNulo() && this->velocidade->produtoInterno(*this->n) < 0.0f )	
			retorno = true;				
	return retorno;
}

void Dinamico::acelerar(){
	bool eraRetrogrado = this->mRetrogrado();
	Vetor n = this->n->copiaNormalizada();
	*this->aceleracao = n * this->acel;
	*this->velocidade += *this->aceleracao;
	*this->centro += *this->velocidade;
	if(eraRetrogrado){ 
		if(this->mProgressivo())	
			this->velocidade->anular();
	}else if(this->velocidade->norma() > this->velocidadeMaxima){
		this->velocidade->setNorma(this->velocidadeMaxima);	
		this->aceleracao->anular();
	}
}
void Dinamico::freiar(){
	Vetor n = this->n->copiaNormalizada();	
	*this->aceleracao = n * (-this->freio);
	*this->velocidade += *this->aceleracao;
	*this->centro += *this->velocidade;
	if(this->mRetrogrado())
		this->velocidade->anular();
}

//velocidade negativa e aceleracao negativa
void Dinamico::darRe(){
	Vetor n = this->n->copiaNormalizada();	
	*this->aceleracao = n * (-this->acel);
	*this->velocidade += *this->aceleracao;
	*this->centro += *this->velocidade;	
	if(!this->mProgressivo()){
		if(this->velocidade->norma() > this->velocidadeMinima){
			this->velocidade->setNorma(this->velocidadeMinima);	
			this->aceleracao->anular();
		}			
	}
}

void Dinamico::passivo(){	
	if(!this->repouso()){
		Vetor n = this->n->copiaNormalizada();
		bool eraProgressivo = this->mProgressivo();
		bool eraRetrogrado = this->mRetrogrado();

		float acel = eraProgressivo ? -this->resistencia: this->freio;

		*this->aceleracao = (n * acel);
		*this->velocidade += *this->aceleracao;
		*this->centro += *this->velocidade;	
		if( (eraProgressivo && this->mRetrogrado()) ||
			(eraRetrogrado && this->mProgressivo()) )
			this->velocidade->anular();

		if(this->repouso())
			this->aceleracao->anular();	
	}
}

Ponto Dinamico::centroDeMassa(const Dinamico &d){
	float massaTotal = this->massa + d.massa;
	Ponto retorno = ((*this->centro * this->massa)  + (*d.centro * d.massa))/massaTotal;
	return retorno;
}
