#include "armamento.h"

	Armamento :: Armamento (Ponto * centroProsTiros, Vetor *direcaoProsTiros, Vetor *lateralProsTiros) {
		
		this->indiceMetralhadora = 0;
		this->indiceMina = 0;
		this->indiceMT = 0;

		for (int i = 0; i < 50; i++) {
			this->metralhadora[i] = new Metralhadora (new Ponto(), new Vetor(), new Vetor(), 0.2f, 0.05f, 0.1f);
		}//pra nao dar new nas balas do metralharoda

		for (int i = 0; i < 3; i++) {
			this->mina[i] = new Mina (new Ponto(), new Vetor(), new Vetor(), 0.1f, 0.1f, 0.1f);
		}	

		for (int i = 0; i < 10; i++) {
			this->mT[i] = new TiroTeleguiado (new Ponto(), new Vetor(), new Vetor(), 0.45f, 0.1f, 0.2f);
		}

		this->centroParaOsTiros = centroProsTiros;
		this->direcaoParaOsTiros = direcaoProsTiros;
		this->lateralParaOsTiros = lateralProsTiros;
		this->tempo = new Timer (200);
	}

	Armamento :: ~Armamento() {
		delete tempo;
		for (int i = 0; i < 50; i++) {
			delete this->metralhadora[i];
		}//pra nao dar new nas balas do metralharoda

		for (int i = 0; i < 3; i++) {
			delete this->mina[i];
		}	

		for (int i = 0; i < 10; i++) {
			delete this->mT[i];
		}
	}

	void Armamento :: update () {
		
		for (int i = 0; i < 50; i++) {
			if (this->metralhadora[i]->atirada) {
				this->metralhadora[i]->update();
			}
		}
		for (int i = 0; i < 10; i++) {
			if (this->mT[i]->atirada) {
				this->mT[i]->update();
			}
		}

	}

	void Armamento :: draw () {
		for (int i = 0; i < 50; i++) {
			if (this->metralhadora[i]->atirada) {
				this->metralhadora[i]->draw();
			}
		}

		for (int i = 0; i < 3; i++) {
			if (this->mina[i]->atirada) {
				this->mina[i]->draw();
			}
		}

		for (int i = 0; i < 10; i++) {
			if (this->mT[i]->atirada) {
				this->mT[i]->draw();
			}
		}
	}

	void Armamento :: atirarMetralhadora () {
		if (this->tempo->passouTempo()) {
			this->metralhadora[(this->indiceMetralhadora++)%50]->disparar(this->centroParaOsTiros->copia(), this->direcaoParaOsTiros->copia());
		}
	}

	void Armamento :: atirarMina () {
		if (this->tempo->passouTempo() && indiceMina < 3) {//ta infinito por enquanto / depois alguem faz um metodo pra controlar a quantidade de minas
			this->mina[this->indiceMina++]->disparar(this->centroParaOsTiros->copia(), this->direcaoParaOsTiros->copia());
		}
	}

	void Armamento :: atirarMT () {
		if ((this->mT[this->indiceMT - 1]->atirada == false || this->indiceMT == 0) && indiceMT < 10) {//ta infinito por enquanto / depois alguem faz um metodo pra controlar a quantidade de miseel teleguiado
			this->mT[this->indiceMT++]->disparar(this->centroParaOsTiros->copia(), this->direcaoParaOsTiros->copia());
		}
	}