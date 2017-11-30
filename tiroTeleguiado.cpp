#include "tiroteleguiado.h"
#include "3dsloader.h"

	static Vetor temp(0.f, 0.f, 1.f);
    Textura TiroTeleguiado::tMT("Texturas/Municao/m2.bmp",false);
    
	TiroTeleguiado :: TiroTeleguiado (Ponto *centro, Vetor *direcao, Vetor *lateral, float dn, float dv, float du) 
		: Objeto3D (centro, direcao, lateral, dn, dv, du){
		velocidade = 0.4f;
		atirada = false;
		tMT.carregarBMP();
		gamb = 0;
	}

	TiroTeleguiado :: ~TiroTeleguiado () {
		//n serva pra nada
	}

	void TiroTeleguiado :: draw () {
		static bool gamb = false;
		static obj_type object;
		
		if (this->atirada) {
			int l_index;
	

			glPushMatrix();
			glEnable(GL_TEXTURE_2D);

		if(!gamb){		

			Load3DS (&object,"Modelos/3DS/misselT.3ds");
			
			gamb = true;
		}
    
		glTranslatef(this->centro->x,this->centro->y+0.2,this->centro->z);
		glRotatef(90.0f,1.0f,0.f,0.f);
		glRotatef((this->n->anguloEntre(temp)*(180/3.1416))+180,0.f,0.f,1.f);

		glScalef(0.004f,0.004f,0.004f);

		glBindTexture(GL_TEXTURE_2D, tMT.ID); 

	    glBegin(GL_TRIANGLES);		
	
    for (l_index=0;l_index<object.polygons_qty;l_index++) {
       
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
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

		}
	}

	void TiroTeleguiado :: update() {
		if (this->atirada) {
			if(this->gamb > 4){
				*this->n = *this->centro2 - *this->centro;
				this->gamb = 0;
			}else{
				this->gamb++;
			}
			this->n->normalizar();
			*this->centro = *this->centro + *this->n * this->velocidade;
			this->calcularExtremidades();
		}
	}

	void TiroTeleguiado :: disparar (Ponto centro, Vetor direcao) {//copias

		this->atirada = true;

		delete this->centro;
		delete this->n;
		delete this->u;

		this->centro = new Ponto();
		this->n = new Vetor();
		this->v = new Vetor(0.f,1.f,0.f);
		this->u = new Vetor();

		*this->n = direcao;
		*this->centro = centro  + (*this->n * this->deltaN * 4);
		this->centro2 = centro2;
		
		this->calcularU();
		this->calcularExtremidades();
	}

	void TiroTeleguiado :: perseguir(Ponto *destino){
		this->centro2 = destino;
	}
