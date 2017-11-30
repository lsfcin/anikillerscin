#ifndef TIMER_H
#define TIMER_H

#include "APIS\SDL\include\SDL.h"

class Timer{
private:
	int anterior;
	int atual;
	long intervaloDeTempo;

public:
	Timer(long intervaloDeTempo = 80);	
	bool passouTempo();
	void zerar();
};


#endif
