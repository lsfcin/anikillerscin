#ifndef CAMERA_H
#define CAMERA_H
#include "ponto.h"
#include "vetor.h"
#include "keys.h"
#include "constantes.h"
#include "textura.h"
#include "carro.h"

class Camera {	
	public:     
		Camera (int numJogadores = 1);
		~Camera();	
		float GrausPraRad(float graus);
		float RadPraGraus(float radiano);
		void setPosicaoCamera(Ponto *c, float angulo0, float angulo1);
		void atualizarGiro();	    
		void transladarFrente(int i);
		void perseguirObjeto3d(int opcaoDeCamera, const Carro *objeto, float distancia, Vetor *altura);		
        void fotografar (); 
        void atualizarView();
		void update(const Carro *objeto);
		void mover();
		void renderBitmapString(int x, int y, void *font, char *string);
		void drawOrtho();
	private:
		Vetor *foco;
		Ponto *centro;
		Vetor *up;	
		float *ang;
		int nJogadores;
};
#endif