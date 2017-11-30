#include "tiro.h"

Tiro :: Tiro(float acele, float velomax,float deltaX, float deltaZ){
	
	for (int i = 0;i < 4;i++){
		this->extremidades[i].x = 0;
		this->extremidades[i].y = 0;
		this->extremidades[i].z = 0;
	}

	this->aceleracao = acele;
	this->velocidade = 0;
	this->velocidadeMaxima = velomax;
	
	this->deltaX = deltaX;
	this->deltaZ = deltaZ;

	this->atirada = 0;

	this->calcularExtremidades();
	
}

void Tiro :: calcularExtremidades(){
	this->extremidades[0].x -= this->deltaX;
	this->extremidades[0].z += this->deltaZ;

	this->extremidades[1].x += this->deltaX;
	this->extremidades[1].z += this->deltaZ;

	this->extremidades[2].x += this->deltaX;
	this->extremidades[2].z -= this->deltaZ;

	this->extremidades[3].x -= this->deltaX;
	this->extremidades[3].z -= this->deltaZ;
}

void Tiro :: acelerar(){
	if (this->velocidade < this->velocidadeMaxima - aceleracao){
		this->velocidade += this->aceleracao; 
	}else{
		this->velocidade = this->velocidadeMaxima;
	}
	this->andar();
}

void Tiro :: andar(){
	Vetor temp = *this->v1 * this->velocidade;
	*this->centro = *this->centro + temp;	
	this->calcularExtremidades();
}