#include "igreja.h"
#include "3dsloader.h"

static obj_type objecto;
Textura Igreja::tIgreja("Texturas/Obstaculos/igreja.bmp",false);

Igreja
:: Igreja (Ponto *p, Vetor *n, Vetor *v, float dN, float dV, float dU, int opcao)
: Obstaculo(p, n, v, dN, dV, dU, opcao) {

	Load3DS (&objecto,"Modelos/3DS/igreja.3ds");
	tIgreja.carregarBMP();
}

void Igreja :: draw() {	
	
		int l_index;
	
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);

    
		glTranslatef(this->centro->x,this->centro->y+8.2,this->centro->z);
		glRotatef(90.0f,1.0f,0.f,0.f);
		glRotatef(180.0f,1.0f,0.f,0.f);

		glBindTexture(GL_TEXTURE_2D, tIgreja.ID); 

	    glBegin(GL_TRIANGLES);
	
    for (l_index=0;l_index<objecto.polygons_qty;l_index++)
    {
       
        glTexCoord2f( objecto.mapcoord[ objecto.polygon[l_index].a ].u,
                      objecto.mapcoord[ objecto.polygon[l_index].a ].v);

        glVertex3f( objecto.vertex[ objecto.polygon[l_index].a ].x,
                    objecto.vertex[ objecto.polygon[l_index].a ].y,
                    objecto.vertex[ objecto.polygon[l_index].a ].z); //Vertex definition


        glTexCoord2f( objecto.mapcoord[ objecto.polygon[l_index].b ].u,
                      objecto.mapcoord[ objecto.polygon[l_index].b ].v);

        glVertex3f( objecto.vertex[ objecto.polygon[l_index].b ].x,
                    objecto.vertex[ objecto.polygon[l_index].b ].y,
                    objecto.vertex[ objecto.polygon[l_index].b ].z);
        

        glTexCoord2f( objecto.mapcoord[ objecto.polygon[l_index].c ].u,
                      objecto.mapcoord[ objecto.polygon[l_index].c ].v);

        glVertex3f( objecto.vertex[ objecto.polygon[l_index].c ].x,
                    objecto.vertex[ objecto.polygon[l_index].c ].y,
                    objecto.vertex[ objecto.polygon[l_index].c ].z);
    }
    glEnd();

    glFlush(); 
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

}	
