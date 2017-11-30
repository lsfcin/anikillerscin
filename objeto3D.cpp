#include "objeto3D.h"

Objeto3D::Objeto3D(){
	this->centro = new Ponto();	
	this->n = new Vetor(0.0f,0.0f,1.0f);
	this->v = new Vetor(0.0f,1.0f,0.0f);
	this->u = new Vetor(1.0f,0.0f,0.0f);
	this->deltaN = 1.f;
	this->deltaV = 1.f;
	this->deltaU = 1.f;
	this->angulo = 0.0f;
	for(int i = 0; i < 4; i++)
		this->extremidades[i] = new Ponto(); 
	this->calcularExtremidades();
}


Objeto3D::Objeto3D(Ponto *centro,Vetor *n, Vetor *v, float dN, float dV, float dU){
	this->deltaN = dN;
	this->deltaV = dV;
	this->deltaU = dU;
	this->centro = centro;	
	this->n = n;
	this->n->normalizar();
	this->v = v;
	this->v->normalizar();
	this->u = new Vetor();
	this->calcularU(); // calcula u a partir de n e v;
	this->angulo = 0;
	for(int i = 0; i < 4; i++)
		this->extremidades[i] = new Ponto(); 
	this->calcularExtremidades();
}

Objeto3D::Objeto3D(const Objeto3D &o ) {
	this->centro = new Ponto(*o.centro);
	this->n = new Vetor(*o.n);
	this->v = new Vetor(*o.v);
	this->u = new Vetor(*o.u);
	this->angulo = o.angulo;
	this->deltaN = o.deltaN;
	this->deltaV = o.deltaV;
	this->deltaU = o.deltaU;
	for(int i = 0; i < 4; i++)
		this->extremidades[i] = new Ponto(*o.extremidades[i]);
}

Objeto3D::~Objeto3D(){
	delete this->centro;	
	delete this->n;
	delete this->v;
	delete this->u;
	for(int i = 0; i < 4; i++)
		delete this->extremidades[i];
}

void Objeto3D::calcularU(){
	//*this->u = this->n->produtoVetorial(*this->v);
	*this->u = *this->n * *this->v;
	this->u->normalizar();
}

void Objeto3D::teste(const Objeto3D &a){

}

 void Objeto3D :: calcularExtremidades(){
	*this->extremidades[0] = *this->centro + ((*this->n * this->deltaN) + (*this->u * this->deltaU));
	*this->extremidades[1] = *this->centro + ((*this->n * this->deltaN) - (*this->u * this->deltaU));
	*this->extremidades[2] = *this->centro - ((*this->n * this->deltaN) + (*this->u * this->deltaU));
	*this->extremidades[3] = *this->centro - ((*this->n * this->deltaN) - (*this->u * this->deltaU));
 }

 bool  Objeto3D::colisaoDeSilvio(const Ponto *p) const {
	Vetor v0 = *this->extremidades[1] - *this->extremidades[0];
	Vetor v1 = *p - *this->extremidades[0];

	Vetor v2 = *this->extremidades[2] - *this->extremidades[1];
	Vetor v3 = *p - *this->extremidades[1];

	Vetor v4 = *this->extremidades[3] - *this->extremidades[2];
	Vetor v5 = *p - *this->extremidades[2];

	Vetor v6 = *this->extremidades[0] - *this->extremidades[3];
	Vetor v7 = *p - *this->extremidades[3];

	if(v0.anguloEntre(v1) < 0 || v2.anguloEntre(v3) < 0 || 
	   v4.anguloEntre(v5) < 0 || v6.anguloEntre(v7) < 0) 
		return false;

	return true;

	}

 bool Objeto3D::colidiu(const Objeto3D &o){
	
	 if(o.centro->distancia(*this->centro) <= 
	   (o.centro->distancia(*o.extremidades[0]) + this->centro->distancia(*this->extremidades[0]))) {

	 if((this->colisaoDeSilvio(o.extremidades[0]) ||
	     this->colisaoDeSilvio(o.extremidades[1]) ||
	     this->colisaoDeSilvio(o.extremidades[2]) ||
	     this->colisaoDeSilvio(o.extremidades[3]) ||

	     o.colisaoDeSilvio(this->extremidades[0]) ||
	     o.colisaoDeSilvio(this->extremidades[1]) ||
	     o.colisaoDeSilvio(this->extremidades[2]) ||
		 o.colisaoDeSilvio(this->extremidades[3]))&&

		 ((this->centro->y >= o.centro->y && this->centro->y <= (o.centro->y + o.deltaV)) ||
		 (this->centro->y + this->deltaV >= o.centro->y && this->centro->y + this->deltaV <= (o.centro->y + o.deltaV)) ||
		 (this->centro->y <= o.centro->y && this->centro->y + this->deltaV >= (o.centro->y + o.deltaV))))
	     return true;
	 }

	 return false;
}

  Ponto Objeto3D::getCentro(){
	 return *this->centro;
 }

 Vetor Objeto3D::getN(){
	 return *this->n;
 }

 Vetor Objeto3D::getV(){
	 return *this->v;
 }

 Vetor Objeto3D::getU(){
	 return *this->u;
 }

 float Objeto3D::getAngulo(){
	return this->angulo;
 }

 float Objeto3D::getDeltaN(){
	return this->deltaN;
 }

 float Objeto3D::getDeltaV(){
	 return this->deltaV;
 }

 float Objeto3D::getDeltaU(){
	 return this->deltaU;
 }

Objeto3D & Objeto3D :: operator=(const Objeto3D  &o){
		if(this != &o){
			*this->centro = *o.centro;  
			*this->n = *o.n;
			*this->v = *o.v;
			*this->u = *o.u;
			this->angulo = o.angulo;
			this->deltaN = o.deltaN;
			this->deltaV = o.deltaV;
			this->deltaU = o.deltaU;
			for(int i = 0; i < 4; i++)
				*this->extremidades[i] = *o.extremidades[i];
		}
		return *this;
}