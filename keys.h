#ifndef __KEYS__H__
#define __KEYS__H__
	#define F1			282
	#define F2			283
	#define F3			284
	#define F4			285
	#define F5			286
	#define F6			287
	#define F7			288
	#define F8			289
	#define F9			290
	#define F10			291
	#define F11			292
	#define F12			293
	
	#define UP			273
	#define DOWN		274
	#define RIGHT		275
	#define LEFT		276	
	#define INSERT		277
	#define HOME		278
	#define END			279
	#define PAGE_UP		280
	#define PAGE_DOWN	281

	#define TAB			9
	#define BACKSPACE	8
	#define KEY_DELETE		127
	#define SPACE		32
	#define ENTER		13
	#define ESCAPE		27

	bool IsKeyPressed(unsigned int key);
	void KeyDownFunc(unsigned int key);
	void KeyUpFunc(unsigned int key);
	void InitKeyboard();

	typedef void (*key_func)(int);
	void SetKeyboardFunc(key_func);

	void SetKeyboardUpFunc(key_func);

#endif