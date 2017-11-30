

#include "keys.h"

// callback functions
key_func g_upfunc=0;
key_func g_downfunc=0;


void SetKeyboardFunc(key_func func) {
	g_downfunc = func;
}


void SetKeyboardUpFunc(key_func func) {
	g_upfunc = func;
}


bool g_keystates[512]={false};


bool IsKeyPressed(unsigned int key) {

	// make sure valid key requested
	if (key>=0&&key<512) {
		// return the state of the requested key
		return g_keystates[key];
	}
	return false;
}

void KeyUpFunc(unsigned int key) {

	// set state of key
	g_keystates[key]=false;

	// if callback function set, call it
	if (g_upfunc) {
		g_upfunc(key);
	}
}
//--------------------------------------------------------------------------	KeyDownFunc
//
void KeyDownFunc(unsigned int key) {

	// set state of key
	g_keystates[key]=true;

	// if callback function set, call it
	if (g_upfunc) {
		g_upfunc(key);
	}
}