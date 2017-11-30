#include "metralhadora.h"

	Metralhadora :: Metralhadora (Ponto *centro, Vetor *direcao, Vetor *lateral, float dn, float dv, float du)
		: Objeto3D(centro, direcao, lateral, dn, dv, du) {//todos os parametros devem ser copias
		velocidade = 1.5f;
		atirada = false;
	}

	Metralhadora :: ~Metralhadora () {
		//nao serve pra nada
	}

	void Metralhadora :: draw () {
		if (this->atirada) {
			glPushMatrix();	
				glColor3f(1.f,1.f,0.f);
				glBegin(GL_POLYGON);	
					glVertex3f(this->extremidades[0]->x, this->extremidades[0]->y, this->extremidades[0]->z);
					glVertex3f(this->extremidades[3]->x, this->extremidades[3]->y, this->extremidades[3]->z);
					glVertex3f(this->extremidades[3]->x, this->extremidades[3]->y + this->deltaV, this->extremidades[3]->z);
					glVertex3f(this->extremidades[0]->x, this->extremidades[0]->y + this->deltaV, this->extremidades[0]->z);	
				glEnd();

				glBegin(GL_POLYGON);	
					glVertex3f(this->extremidades[1]->x, this->extremidades[1]->y, this->extremidades[1]->z);
					glVertex3f(this->extremidades[2]->x, this->extremidades[2]->y, this->extremidades[2]->z);
					glVertex3f(this->extremidades[2]->x, this->extremidades[2]->y + this->deltaV, this->extremidades[2]->z);
					glVertex3f(this->extremidades[1]->x, this->extremidades[1]->y + this->deltaV, this->extremidades[1]->z);	
				glEnd();
			glPopMatrix();
		}
	}

	void Metralhadora ::update () {
		if (this->atirada) {
			*this->centro = *this->centro + *this->n * this->velocidade;
			this->calcularExtremidades();
		}
	}

	void Metralhadora :: disparar (Ponto centro, Vetor direcao) {//copias
		this->atirada = true;
	
		delete this->centro;
		delete this->n;
		delete this->u;

		this->centro = new Ponto();
		this->n = new Vetor();
		this->v =  new Vetor(0.f,1.f,0.f);
		this->u = new Vetor();

		*this->centro = centro;
		*this->n = direcao;
		
		this->calcularU();
		this->calcularExtremidades();
	}
