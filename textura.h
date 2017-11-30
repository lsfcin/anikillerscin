#ifndef TEXTURA_H
#define TEXTURA_H

#include<windows.h>
#include <stdio.h>
#include "glut.h"
//#include <GL/glut.h> // Tentar tirar essa jo�a daqui depois

#define BITMAP_ID 0x4D42	// ID padr�o pra Bitmap

class Textura
{
   public:
      Textura(char *file = "", bool carregarTextura = false, bool mipMap = false);   
      ~Textura(); 

      void carregarBMP();   // carrega o bmp e gera a textura.
      void FreeImage();     // deleta a imagem da mem�ria.

      unsigned int ID;                    // ID used para identificar cada textura no OpenGl.
      int imageWidth;                     // largura da textura.
      int imageHeight;                    // altura da textura.
	  

   protected:
      void GenerateTexture();             // Gera a textura no opengl, al�m de configur�-la
      unsigned char* LoadBitmap(BITMAPINFOHEADER *bitmapInfoHeader);// carrega o bmp.
	  bool mipMap; // informa se a textura � pra ser carregada em formato de mipmap;
      unsigned char *image;               // imagem carregada.
      bool texturaCarregada;              
      int type;                           // formato da imagem.
	  char *file;
};

#endif
