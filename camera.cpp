#include "camera.h"

Camera::Camera(int nJogadores){
	foco = new Vetor(0.f, 0.f, 0.f);
	centro = new Ponto(0.f, 0.f, 0.f);
	up = new Vetor(0.f, 0.f, 0.f);
	ang = new float[2];
	ang[0] = 0;
	ang[1] = 0;
	this->nJogadores = nJogadores;
}

Camera::~Camera(){
	delete foco;
	delete centro;
	delete up;
	delete [] ang;	
}

void Camera::renderBitmapString(int x,int y,void *font,	char *string) {  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) 
    glutBitmapCharacter(font, *c);  
}

void Camera::drawOrtho(){

/*	char buffer [36];
	char str[200];
	strcpy (str,"CAMERA: (");
	gcvt (this->centro->x,3,buffer);
	strcat (str,buffer);
	strcat(str,",");
	gcvt (this->centro->y,3,buffer);
	strcat (str,buffer);
	strcat(str,",");
	gcvt (this->centro->z,3,buffer);
	strcat (str,buffer);
	strcat(str,").");
	
	glColor3f(1.0f,0.0f,0.0f); 
	renderBitmapString(130,30,GLUT_BITMAP_TIMES_ROMAN_24,str);
	
	buffer[36];
	str[200];
	strcpy (str,"ALVO: [");	
	gcvt (this->foco->x,3,buffer);
	strcat (str,buffer);
	strcat(str,", ");
	gcvt (this->foco->y,3,buffer);
	strcat (str,buffer);
	strcat(str,", ");
	gcvt (this->foco->z,3,buffer);
	strcat (str,buffer);
	strcat(str,"].");
	
	glColor3f(0.0f,0.0f,1.0f); 	
	renderBitmapString(430,30,GLUT_BITMAP_TIMES_ROMAN_24,str);

*/
}

float Camera::GrausPraRad(float graus) {
	return graus * 0.0174532925f;
}

float Camera::RadPraGraus(float radiano) {
	return radiano * 57.295779578f;
}

void Camera::setPosicaoCamera(Ponto *c, float angulo0, float angulo1) {
	ang[0] = angulo0;
	ang[1] = angulo1;
	centro = c;
	atualizarGiro();
}

void Camera::atualizarGiro() {
	foco->setCoordenadas(cos(ang[1])*cos(ang[0]), sin(ang[1]), cos(ang[1])*sin(ang[0]));
	up->setCoordenadas(cos(ang[1] + (PI/2))*cos(ang[0]), cos(ang[1]), cos(ang[1] + (PI/2))*sin(ang[0]));
}	    
void Camera::transladarFrente(int i) {
	centro->setCoordenadas(centro->x + i*(foco->x)*0.1f,  centro->y + i*(foco->y)*0.1f, centro->z + i*(foco->z)*0.1f);
}

void Camera::perseguirObjeto3d(int opcaoDeCamera, const Carro *objeto , float distancia, Vetor *altura) {	
	if(opcaoDeCamera <= 2){			
		if(distancia > 2.3)
			distancia = 2.3f;
		else if(distancia < -2.3f)
			distancia = -2.3f;

		Vetor camera = objeto->getCameraFrontal();

		*this->centro = (*objeto->centro - (camera*distancia)) + *altura;
		*this->foco = *objeto->centro - *centro;
		this->foco->normalizar();
		*this->up = *altura;

		//isso pra colocar o carro mais no canto da tela.
		centro->y += 0.5f; 
	}else if(opcaoDeCamera == 3){
		Vetor camera = objeto->getCameraLateral();
		*this->centro = (*objeto->centro - (camera*distancia)) + *altura;
		*this->foco = *objeto->centro - *centro;
		this->foco->normalizar();
		this->up = altura;
	}

}
        
void Camera::fotografar () {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(nJogadores != 2) gluPerspective(45, ((float)WIDTH)/HEIGHT, 0.1, 10000.0);	
	else gluPerspective(45, ( 2.0f *WIDTH)/HEIGHT, 0.1, 10000.0);	
	atualizarView();
}

void Camera::atualizarView(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(centro->x, centro->y, centro->z,  centro->x + foco->x,
	centro->y + foco->y, centro->z + foco->z, up->x, up->y, up->z);
}

void Camera::update(const Carro *objeto){
	static int opcao = 0;
	static Vetor * altura = new Vetor(0.f, 0.0f, 0.f);
	
	if(IsKeyPressed('r'))
		opcao = 1;
	else if(IsKeyPressed(F1))
		opcao = 0;	
	else if(IsKeyPressed(F2))
		opcao = 2;
	else if(IsKeyPressed(F3))
		opcao = 3;
	else if(IsKeyPressed(F4))
		opcao = 4;

	if(opcao == 0) {
		altura->x = 0.0f;
		altura->y = 0.5f;
		altura->z= 0.0f;
		this->perseguirObjeto3d(0,objeto, 2.0f +objeto->velocidade->norma() , altura);
	}else if(opcao == 1) {
		altura->x = 0.0f;
		altura->y = 0.5f;
		altura->z= 0.0f;
		this->perseguirObjeto3d(1,objeto,-(2.0f + objeto->velocidade->norma()), altura);
		opcao = 0;
	}else if(opcao == 2) {
		altura->x = 0.0f;
		altura->y = 20.5f;
		altura->z= 0.0f;
 		this->perseguirObjeto3d(2,objeto, 2.0f + objeto->velocidade->norma(), altura);
	}else if(opcao == 3) {
		altura->x = 0.0f;
		altura->y = 0.40f;
		altura->z= 0.0f;
 		this->perseguirObjeto3d(3, objeto, 1.0f+objeto->velocidade->norma(), altura);
	}else if(opcao == 4) 
		this->mover();		
}

void Camera :: mover () {
	if (IsKeyPressed(PAGE_UP))
		transladarFrente(1);
    if (IsKeyPressed(PAGE_DOWN))
		transladarFrente(-1);
	if (IsKeyPressed(LEFT))
	    ang[0] -= 0.015f;
	if (IsKeyPressed(RIGHT))
	   	ang[0] +=0.015f;
	if(IsKeyPressed(UP))
		ang[1] += 0.015f;			
	if(IsKeyPressed(DOWN))
		ang[1] -= 0.015f;
	this->atualizarGiro();
}
