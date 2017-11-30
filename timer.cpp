#include "timer.h"

Timer::Timer(long intervaloDeTempo){
	this->intervaloDeTempo = intervaloDeTempo;
	this->anterior = SDL_GetTicks();
	this->atual = SDL_GetTicks();
}

bool Timer::passouTempo(){
	
	bool retorno = false;
    this->atual = SDL_GetTicks(); 

	if (this->atual > this->anterior + this->intervaloDeTempo){        
		this->anterior = atual;
		retorno = true;
	}
    return retorno; 
}

void Timer::zerar(){
	this->anterior = SDL_GetTicks();
	this->atual = SDL_GetTicks();	
}