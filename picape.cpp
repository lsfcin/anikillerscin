#include "picape.h"
#include "3dsloader.h"

#define RadParaGraus(a) a*180/PI

static obj_type object;
Textura Picape::tRoda("Texturas/Carros/Chevette/roda.bmp",false);

Textura Picape::tPicape("Texturas/Carros/Hunter/hunterAmarela.bmp",false);

Picape::Picape(Ponto *centro,Vetor *n, Vetor *v, int cor): Carro(centro, n, v,10.0f, 0.01f, 0.4f,0.08f, 1.0f, 1.0f,0.5f,0.3f){
	this->tRoda.carregarBMP();
	Load3DS (&object,"Modelos/3DS/hunter.3ds");
	
	this->tPicape.carregarBMP();
}

Picape::~Picape(){

}

void Picape::draw() {	
	static Vetor canonico(0.0f, 0.0f, -1.0f);
	this->armas->draw();
	
	int l_index;
	
		glPushMatrix();
		
		glEnable(GL_TEXTURE_2D);

		glTranslatef(this->centro->x,this->centro->y+0.42,this->centro->z);
		
		glTranslatef(0, -this->centro->y * 0.02, 0);  
		glColor3f(0.8,0.8,1.0);
		Vetor * temp = new Vetor();
		*temp = n->produtoVetorial(canonico);
		float produtoInterno = n->produtoInterno(canonico);
		float a = acos(produtoInterno);
		this->angulo = RadParaGraus(a);
		if(temp->y > 0.f) 
			this->angulo = -this->angulo;	
	
		delete temp;	
			glRotated(this->angulo, 0, 1, 0);
		
		glPushMatrix();
		glRotatef(90.0f,1.0f,0.f,0.f);
		glRotatef(180.0f,0.0f,1.f,0.f);
		glScalef(0.0007f,0.0007f,0.0007f);
		glBindTexture(GL_TEXTURE_2D, tPicape.ID); 
		
	    glBegin(GL_TRIANGLES);
	
    for (l_index=0;l_index<object.polygons_qty;l_index++)
    {
       
        glTexCoord2f( object.mapcoord[ object.polygon[l_index].a ].u,
                      object.mapcoord[ object.polygon[l_index].a ].v);

        glVertex3f( object.vertex[ object.polygon[l_index].a ].x,
                    object.vertex[ object.polygon[l_index].a ].y,
                    object.vertex[ object.polygon[l_index].a ].z); //Vertex definition


        glTexCoord2f( object.mapcoord[ object.polygon[l_index].b ].u,
                      object.mapcoord[ object.polygon[l_index].b ].v);

        glVertex3f( object.vertex[ object.polygon[l_index].b ].x,
                    object.vertex[ object.polygon[l_index].b ].y,
                    object.vertex[ object.polygon[l_index].b ].z);
        

        glTexCoord2f( object.mapcoord[ object.polygon[l_index].c ].u,
                      object.mapcoord[ object.polygon[l_index].c ].v);

        glVertex3f( object.vertex[ object.polygon[l_index].c ].x,
                    object.vertex[ object.polygon[l_index].c ].y,
                    object.vertex[ object.polygon[l_index].c ].z);
    }
    glEnd();
    glFlush(); 
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//glPushMatrix();
	glColor3f(1,1,1);
	//glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tRoda.ID);
	glScalef(0.044f, 0.044f, 0.044f);
	glTranslated(0.f, -10.f, -8.f);
	glRotated(90, 0.f, 1.f, 0.f);
	desenhaRodas();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	
}

void Picape::roda_origem(int raio) {
	
	float ang;
	float inc_ang = PI/20;
	float posicao = 0;	
	
	//glRotatef(90,0,1,0);
	for(ang=0; ang<=2*PI; ang+=inc_ang) {
			if(ang+inc_ang>2*PI) inc_ang = 2*PI-ang;

			glBegin(GL_TRIANGLES);
					glNormal3f(0,0,1);
					glTexCoord2f(0.25, 0.75);
					glVertex3f(0.0,0.0,0.0);
					glTexCoord2f(0.25*cos(ang)+0.25,0.25*sin(ang)+0.75);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), 0.0);
					glTexCoord2f(0.25*cos(ang+inc_ang)+0.25,0.25* sin(ang+inc_ang)+0.75);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), 0.0);

					glNormal3f(0,0,-1);
					glTexCoord2f(0.25, 0.75);
					glVertex3f(0.0,0.0,-2.6);
					glTexCoord2f(0.25*cos(ang+inc_ang)+0.25,0.25* sin(ang+inc_ang)+0.75);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), -2.6);
					glTexCoord2f(0.25*cos(ang)+0.25,0.25*sin(ang)+0.75);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), -2.6);
			glEnd();

			glBegin(GL_QUADS);
			Vetor *a = new Vetor(0.0f, 0.0f, -2.6f);
			Vetor *b = new Vetor((raio*(cos(ang+inc_ang)-cos(ang))), 
									 (raio*(sin(ang+inc_ang)-sin(ang))),
									 0);
			Vetor *resultante = new Vetor();
			*resultante = a->produtoVetorial(*b);
			glNormal3f(resultante->x, resultante->y, resultante->z);

			delete a;
			delete b;
			delete resultante;
			
					glTexCoord2f(posicao,0.15);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), 0.0);
					glTexCoord2f(posicao,0.1);
					glVertex3f((raio*cos(ang)), (raio*sin(ang)), -2.6);
					glTexCoord2f(posicao+(1/20),0.15);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), -2.6);
					glTexCoord2f(posicao+(1/20),0.1);
					glVertex3f((raio*cos(ang+inc_ang)), (raio*sin(ang+inc_ang)), 0.0);
			glEnd();
			posicao += 1/20;
	}	
}

void Picape::desenhaRodas() { 	
	int static raio = 3.9;
	float velocidade = this->velocidade->norma();

	if(this->mRetrogrado())
		velocidade = -velocidade;

	this->anguloVerticalRoda += velocidade *900;
		
	// Desenha as rodas dianteiras que só giram

	glPushMatrix();
			glTranslatef(10.5,2.0,8.1);
			glRotatef(-anguloRodaCarro*30,0,1,0);
			glRotatef(-anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(10.5,2.0,-8.1);
			glRotatef(-(180+anguloRodaCarro*30),0,1,0);
			glRotatef(anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();

	// Desenha as rodas traseiras
	glPushMatrix();
			glTranslatef(-13.1,2.0,8.1);
			glRotatef(-anguloVerticalRoda*1.11,0,0,1);	
			roda_origem(raio);
	glPopMatrix();
	glPushMatrix();
			glTranslatef(-13.1,2.0,-8.1);
			glRotatef(180,0,1,0);
			glRotatef(anguloVerticalRoda*1.11,0,0,1);
			roda_origem(raio);
	glPopMatrix();
	glFlush();
	
}

void Picape::setCor(int cor){	
	
}
