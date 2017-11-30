#include <cmath>
#include "carro.h"

Carro::Carro(): Dinamico(){
	
	this->armas = new Armamento(this->centro, this->n, this->v);
	this->roda = new Vetor(this->n->x, this->n->y, this->n->z);	

	//Valores Default
	this->velocidadeAngular = 0.02f;
	this->velocidadeAngularRoda = 0.07f;
	this->angMaxRodaCarro = 1.f;
	this->anguloRodaCarro = 0.0f;
	this->anguloVerticalRoda = 0.0f;
}

Carro::Carro(Ponto *centro, Vetor *n, Vetor *v, float massa, float acel, float velocidadeMaxima,
		  float velocidadeMinima, float angMaxRodaCarro, float dN , float dV , float dU)	  
	  :Dinamico(centro,n,v,massa,acel,velocidadeMaxima,velocidadeMinima, dN,dV,dU) {
	
    this->armas = new Armamento(this->centro, this->n, this->v);
	this->roda = new Vetor(this->n->x, this->n->y, this->n->z);	
	this->angMaxRodaCarro = angMaxRodaCarro;	

	//Valores Default
	this->velocidadeAngular = 0.02f;
	this->velocidadeAngularRoda = 0.07f;	
	this->anguloRodaCarro = 0.0f;
	this->anguloVerticalRoda = 0.0f;
}

Carro::Carro(const Carro &c ) {	
	this->centro = new Ponto(*c.centro);
	this->n = new Vetor(*c.n);
	this->v = new Vetor(*c.v);
	this->u = new Vetor(*c.u);
	this->angulo = c.angulo;
	this->deltaN = c.deltaN;
	this->deltaV = c.deltaV;
	this->deltaU = c.deltaU;
	for(int i = 0; i < 4; i++)
		this->extremidades[i] = new Ponto(*c.extremidades[i]);

	this->roda = new Vetor(*c.roda);	
}

 Carro & Carro :: operator=(const Carro  &o){
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
		*this->roda = *o.roda;
	}
	return *this;	
}


Carro::~Carro(){
	delete this->armas;
	delete this->roda;
}

Vetor Carro::getCameraFrontal() const{
	Vetor a = (*this->n + (*this->n + (*this->n + this->n->reflexo(*this->roda)))); 	
	a.normalizar();
	return a;
}

Vetor Carro::getCameraLateral() const{
	Vetor a = this->n->produtoVetorial(*this->v);		
	a.normalizar();	
	return a;
}

void Carro :: calcularVelocidadeAngular() {
	/*if(this->velocidade->norma() < this->velocidadeMaxima/5)
		this->velocidadeAngular = 0.007f;
	else*/
		this->velocidadeAngular = 0.003f + ((fabs(this->anguloRodaCarro)) * 0.07f);//((mod(this->velocidade)) * 0.03f);	
}

void Carro :: girarCarro(){
	
	if(this->mProgressivo()) {
		if(anguloRodaCarro < -velocidadeAngular/2)
			this->n->rotacionarEmY(-velocidadeAngular); 				
		else if(anguloRodaCarro > velocidadeAngular/2)
			this->n->rotacionarEmY(velocidadeAngular);					
		else{
			this->n->setCoordenadas(roda->x, roda->y, roda->z);	
			this->n->normalizar();		
		}
		this->reduzirDerrapagem();
	}else if (this->mRetrogrado()){
		if(anguloRodaCarro < -velocidadeAngular/2) {
			this->roda->rotacionarEmY(2*velocidadeAngular);
			this->n->rotacionarEmY(velocidadeAngular);		
		}else if(anguloRodaCarro > velocidadeAngular/2) {
			this->roda->rotacionarEmY(-2*velocidadeAngular); 
			this->n->rotacionarEmY(-velocidadeAngular);			
		}else{
			this->n->setCoordenadas(roda->x, roda->y, roda->z);	
			this->n->normalizar();			
		}
		this->reduzirDerrapagem();
	}

}

void Carro :: reduzirDerrapagem(){
	static float coeficienteDeAtrito = 0.45f; 
	this->calcularU();	
	*this->velocidade -= this->velocidade->projecao(*this->u) * coeficienteDeAtrito;		
}


void Carro :: girarRoda (int sentido) {	
	if ((anguloRodaCarro < -angMaxRodaCarro && sentido > 0) ||
		(anguloRodaCarro > angMaxRodaCarro && sentido < 0) ||
		(anguloRodaCarro > -angMaxRodaCarro && anguloRodaCarro < angMaxRodaCarro)) 
			this->roda->rotacionarEmY(sentido * this->velocidadeAngularRoda);				
}

void Carro :: calcularAnguloRodaCarro() {
	this->roda->normalizar();
	this->n->normalizar();

	double cosseno = this->n->produtoInterno(*this->roda);

	if(cosseno < -1.f) cosseno = -1.f;
	else if(cosseno > 1.f) cosseno = 1.f;
	anguloRodaCarro = (float) acos(cosseno);
	Vetor temp = this->roda->produtoVetorial(*this->n);
	if(temp.y < 0.f)
		anguloRodaCarro = -anguloRodaCarro;

}

void Carro::atualizarVetoresEValores(){	
	this->calcularU();		
	calcularVelocidadeAngular();
}

inline float Carro::getVelocidade(){
	
	if(this->mRetrogrado())
		return -this->velocidade->norma();
	else
		return this->velocidade->norma();

	return 0.0f;
}

void Carro::update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado) {
	this->atualizarVetoresEValores();
	if(this->velocidade->norma() != 0.0f) 
		this->girarCarro();

	if (cima)
		this->acelerar();
	else if (baixo){
		if(this->mProgressivo())
			this->freiar();
		else
			this->darRe();
	}else
		this->passivo();		

	if (esquerda && (this->velocidade->norma() != 0))
		girarRoda(-1);
	else if (direita && (this->velocidade->norma() != 0))
		girarRoda(1);

	if (metralhadora)
		this->armas->atirarMetralhadora();

	if (mina)
		this->armas->atirarMina();

	if (teleguiado)
		this->armas->atirarMT();

	this->armas->update();

	this->calcularExtremidades();
	calcularAnguloRodaCarro();

}

/*void Carro::update(bool cima, bool baixo, bool esquerda, bool direita, bool metralhadora, bool mina, bool teleguiado) {
	this->atualizarVetoresEValores();
	 if(this->velocidade->norma() != 0.0f) 
		 this->girarCarro();

	if (cima)
		this->acelerar();
	else if (baixo){
		if(this->mProgressivo())
			this->freiar();
		else
			this->darRe();
	}else
		this->passivo();		

	if (esquerda && (this->velocidade->norma() != 0))
		girarRoda(-1);
	else if (direita && (this->velocidade->norma() != 0))
		girarRoda(1);

	if (metralhadora)
		this->armas->atirarMetralhadora();

	if (mina)
		this->armas->atirarMina();

	if (teleguiado)
		this->armas->atirarMT();

	this->armas->update();

	this->calcularExtremidades();
	calcularAnguloRodaCarro();

}*/

/*void Carro::tratarColisaoCarro(Carro &o){
//	static float vB1, vB2;

		while(this->colidiu(o)){

		Vetor v1 = *this->centro - *o.centro;
		Vetor v2 = v1.oposto();

		v1 *= 1.001f;
		v2 *= 1.001f;
		Ponto centroT = *o.centro + v1;		
		*o.centro = *this->centro + v2;
		*this->centro = centroT;

		this->calcularExtremidades();
		o.calcularExtremidades();
	}
		
	Vetor vA1 = this->velocidade->copia();
	Vetor vB1 = o.velocidade->copia();
	
	Vetor vB2 = ( ( ((vA1*2) - vB1 ) * this->massa )  + (vB1 * o.massa) ) /(this->massa + o.massa);

	Vetor vA2 = vB2 + vB1 - vA1;


	*this->velocidade = vA2;
	*o.velocidade = vB2;

	// AQUI OS CARROS PERDEM LIFE

}*/

void Carro::tratarColisaoCarro(Carro &o){
	Ponto centroDeMassa = this->centroDeMassa(o);
	Vetor v1 = *this->centro - centroDeMassa;
	Vetor v2 = *o.centro - centroDeMassa;

	v1 *= 0.05f;
	v2 *= 0.05f;
	while(this->colidiu(o)){
		//v1*= 
	
		*this->centro += v1; 
		*o.centro += v2;

		this->calcularExtremidades();
		o.calcularExtremidades();
	}
/*	while(this->colidiu(o)){
		
		if(this->velocidade->norma() < 0.01f)
			*this->centro -= *o.velocidade;
		else
			*this->centro += *this->velocidade;
		if(o.velocidade->norma() < 0.01f)
			*o.centro -= *this->velocidade;
		else
			*o.centro += *o.velocidade;
		this->calcularU();
		this->calcularExtremidades();
		o.calcularU();
		o.calcularExtremidades();
	}*/
		
	Vetor vA1 = this->velocidade->copia();
	Vetor vB1 = o.velocidade->copia();
	
	Vetor vB2 = ( ( ((vA1*2) - vB1 ) * this->massa )  + (vB1 * o.massa) ) /(this->massa + o.massa);

	Vetor vA2 = vB2 + vB1 - vA1;


	*this->velocidade = vA2;
	*o.velocidade = vB2;

	/*while(this->colidiu(o)){		
		*this->centro += *this->velocidade; 
		*o.centro += *o.velocidade;
		this->calcularU();
		o.calcularU();
		this->calcularExtremidades();
		o.calcularExtremidades();
	}*/
}

void Carro::tratarColisaoObstaculo(Obstaculo &o){
	*this->velocidade = *this->velocidade * -0.5;
}

void Carro :: renderBitmapString(int x,int y,void *font,	char *string) {  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) 
    glutBitmapCharacter(font, *c);  
}

void Carro :: drawOrtho(){
/*
glColor3f(1.0f,0.0f,0.0f);
	char buffer [36];
	char str[500];
	strcpy (str,"Centro: ( ");
	gcvt (this->centro->x,4,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->centro->y,4,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->centro->z,4,buffer);	
	strcat (str,buffer);
	strcat (str," ) n: (");
	gcvt (this->n->x,4,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->n->y,4,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->n->z,4,buffer);	
	strcat (str,buffer);
	strcat (str," ) v: (");
	gcvt (this->v->x,4,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->v->y,4,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->v->z,4,buffer);	
	strcat (str,buffer);
	strcat (str," ) u: (");
	gcvt (this->u->x,4,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->u->y,4,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->u->z,4,buffer);	
	strcat (str,buffer);
	strcat (str," ) Angulo: ");
	gcvt (this->angulo,4,buffer);
	strcat (str,buffer); 
	strcat (str,".");

//	renderBitmapString(0,30,GLUT_BITMAP_TIMES_ROMAN_24,str);

	strcpy (str," ) Angulo roda: ");		
	gcvt (this->anguloRodaCarro,3,buffer);
	strcat (str,buffer); 	
	strcat (str,"; roda: (");
	gcvt (this->roda->x,3,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->roda->y,3,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->roda->z,3,buffer);	
	strcat (str,buffer);	
	strcat (str," ) vel: (");
	gcvt (this->velocidade->x,3,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->velocidade->y,3,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->velocidade->z,3,buffer);	
	strcat (str,buffer);	
	strcat (str," ) acel: (");
	gcvt (this->aceleracao->x,3,buffer);
	strcat (str,buffer); 
	strcat (str,", ");
	gcvt (this->aceleracao->y,3,buffer);
	strcat (str,buffer);
	strcat (str,", ");
	gcvt (this->aceleracao->z,3,buffer);	
	strcat (str,buffer);
	strcat (str,")");

	renderBitmapString(0,60,GLUT_BITMAP_TIMES_ROMAN_24,str);	
	

	strcpy (str,"anguloEntreNeVelocidade: ( ");		
	gcvt (this->n->anguloEntre(*this->velocidade),4,buffer);
	strcat (str,buffer); 	
	strcat (str," ) anguloEntreNeRoda: ( ");	
	gcvt (this->n->anguloEntre(*this->roda),4,buffer);
	strcat (str,buffer); 	
	strcat (str," )");
	glFlush();
	renderBitmapString(0,90,GLUT_BITMAP_TIMES_ROMAN_24,str);
	glFlush();
	*/
}