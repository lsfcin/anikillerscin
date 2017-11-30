#include "mina.h"

	Mina :: Mina (Ponto *centro, Vetor *direcao, Vetor *lateral, float dn, float dv, float du)// passar copias 
		: Objeto3D (centro, direcao, lateral, dn, dv, du) {
		atirada = false;
	}

	Mina :: ~Mina () {
		//nao serve pra nada
	}

	void Mina :: draw () {
		static int temporizador = 0;
		if (this->atirada) {
			glPushMatrix();

			if(temporizador >= 0){
				if(temporizador == 60)
					temporizador = -59;
				glColor3f(0.25f,0.f,0.f);
				
			}else if(temporizador > -60 && temporizador < 0){
				glColor3f(0.3f,0.2f,0.f);				
			}
			temporizador++;
			glTranslated(this->centro->x, this->centro->y, this->centro->z);
			glutSolidSphere (0.1f,100,100);
			glPopMatrix();

			
		}
	}


	void Mina :: disparar (Ponto centro, Vetor direcao) {
		this->atirada = true;
		delete this->centro;
		delete this->n;
		delete this->u;

		this->centro = new Ponto();
		this->n = new Vetor();
		this->v =  new Vetor(0.f,1.f,0.f);
		this->u = new Vetor();
		
		*this->n = direcao;

		*this->centro = centro - (*this->n * this->deltaN * 15);
		this->calcularU();
		this->calcularExtremidades();
	}
