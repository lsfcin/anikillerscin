/*#pragma comment(lib, "SDL.lib")
#pragma comment(lib, "SDLmain.lib") 
#pragma comment(linker, "/NODEFAULTLIB:msvcrt.lib")*/

#include "jogo.h"
#include "timer.h"
#include "keys.h"
#include "audio.h"
#include "APIS\SDL\include\SDL.h"
#include "glut.h"
#include <windows.h>



long frame=0,timer,timebase=0;
double fps =0;
long frameTeclado=0,timerTeclado,timebaseTeclado=0;
double fpsTeclado =0;

Jogo *game;

void calcularFPS(){
    frame++;
	timer=SDL_GetTicks();
	if (timer - timebase > 100) {
	fps= frame*1000.0/(timer-timebase);
	timebase = timer;		
	frame = 0;
	}
}

void ups(){
    frameTeclado++;
	timerTeclado=SDL_GetTicks();
	if (timerTeclado - timebaseTeclado > 100) {
	fpsTeclado= frameTeclado*1000.0/(timerTeclado-timebaseTeclado);
	timebaseTeclado = timerTeclado;		
	frameTeclado = 0;
	}
}
static void quit( int codigo ){
	SDL_Quit();	
	exit(codigo);
}

//trata eventos do teclado específicos para o main
void tratarTeclado(){
	/*if(IsKeyPressed(ESCAPE))
		quit(0);*/
	if(IsKeyPressed(SDLK_KP_PLUS))
		aumentarVolume();
	else if(IsKeyPressed(SDLK_KP_MINUS))
		reduzirVolume();	
}

void atualizarBufferTeclado(){
	/* Our SDL event placeholder. */
	SDL_Event event;

	/* Grab all the events off the queue. */
	while( SDL_PollEvent( &event ) ) {

		switch( event.type ) {
			case SDL_KEYDOWN:
				/* Handle key presses. */
				KeyDownFunc(event.key.keysym.sym);				
			break;
			case SDL_KEYUP:
				/* Handle key presses. */
				KeyUpFunc(event.key.keysym.sym);				
			break;
			case SDL_QUIT:
				/* Handle quit requests (like Ctrl-c). */
				quit( 0 );
			break;
		}
	}
}

static void setup_opengl( int width, int height ){	

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// FUNDO PRETO
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LESS);	

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations              

	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glViewport(0, 0, WIDTH, HEIGHT);
	gluPerspective(45, (1.0 *WIDTH)/HEIGHT, 0.0001, 10000000.0);
	glPopMatrix();	

	glMatrixMode(GL_MODELVIEW);	

}



void setOrthographicProjection() {
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
	// invert the y axis, down is positive
	glScalef(1, -1, 1);
	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -HEIGHT, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void update(){
	tratarTeclado();
	game->update();
}
void draw(){
	game->draw();

}

void renderBitmapString(int x, int y, void *font, char *string) {  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) 
    glutBitmapCharacter(font, *c);  
}

void pintarFPS(){    	
/*	char buffer [36];
	gcvt (fps,5,buffer);
	char str[80];
    strcpy (str,buffer);
    strcat (str," FPS.");

	glColor3f(1.0f,0.0f,0.0f); 
	renderBitmapString(5,30,GLUT_BITMAP_TIMES_ROMAN_24,str);	
*/	
}

void pintarUPS(){
/*	char buffer [36];
	gcvt (fpsTeclado,5,buffer);
	char str[80];
    strcpy (str,buffer);
    strcat (str," UPS.");

	glColor3f(1.0f,0.0f,0.0f); 
	renderBitmapString(5,80,GLUT_BITMAP_TIMES_ROMAN_24,str);
	*/
}


void drawOrtho(){
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();	
//	pintarFPS();	
//	pintarUPS();	
	game->drawOrtho();
	glPopMatrix();
	resetPerspectiveProjection();
}

int main( int argc, char* argv[] ){
    
    system("abertura/intro.exe");

	const SDL_VideoInfo* info = NULL;
	
	int bpp = 16;
	int flags = 0;
	
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		MessageBox(NULL,NULL,NULL,MB_ICONSTOP);
		SDL_GetError( );
		quit(1);
	}	

	info = SDL_GetVideoInfo();

	if( !SDL_GetVideoInfo()) {		
		MessageBox(NULL,NULL,NULL,MB_ICONSTOP);
		SDL_GetError();
		quit(1);
	}

	bpp = info->vfmt->BitsPerPixel;
	
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );	
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 ); 

	//flags = SDL_FULLSCREEN | SDL_OPENGL;
	flags = SDL_OPENGL;

	if( SDL_SetVideoMode(WIDTH, HEIGHT, bpp, flags) == 0 ) {
		MessageBox(NULL,NULL,NULL,MB_ICONSTOP);
		SDL_GetError();
		quit(1);
	}
	
	setup_opengl(WIDTH, HEIGHT);

	SDL_EnableKeyRepeat(0, 0);
	game = new Jogo();
	inicializarFMod();
	Timer upsTimer(1000/60);

	bool comecouJogo = false;
	SDL_ShowCursor(SDL_DISABLE);
	while( true ) {

		if (upsTimer.passouTempo()) {
			ups();
			atualizarBufferTeclado();			
			update();	
		}

		calcularFPS();
		draw();		
		drawOrtho();
		SDL_GL_SwapBuffers();
		if(!comecouJogo){			
			//FSOUND_Stream_Play(0,musica);
			//FSOUND_PlaySound(1,buzina);
			comecouJogo = true;
		}
		Sleep(20);
			
	}
	finalizarFMod();
	return 0;
}
