#ifndef AUDIO_H
#define AUDIO_H

#pragma comment(lib, "fmodvc.lib")
#include "APIS\FMOD\include\fmod.h"

static int volume = 150;
static  FSOUND_STREAM *musica;
static FSOUND_SAMPLE *buzina;

static  void aumentarVolume(){
	if(volume != 255)
		volume++;
	 FSOUND_SetVolume(0, volume);

}

static  void reduzirVolume(){
	if(volume != 0)
		volume--;
	 FSOUND_SetVolume(0, volume);
}

static  void inicializarFMod()
{
   // Inicia FMOD
   FSOUND_Init(44100, 4, 0);

	
   // Carregar arquivos de áudio
   buzina = FSOUND_Sample_Load(FSOUND_FREE, "audio/buzina.wav", FSOUND_LOOP_OFF, 0,0);  
   musica = FSOUND_Stream_Open("audio/back.mp3",
      FSOUND_LOOP_NORMAL,0,0);


   // Configura Volume
   FSOUND_SetVolume(0, volume);
   FSOUND_SetVolume(1, 150);
}

static  void finalizarFMod()
{    
	// Libera da memória os arquivos de áudio carregados
	FSOUND_Sample_Free(buzina);    
    FSOUND_Stream_Close(musica);
    FSOUND_Close();
}

#endif
