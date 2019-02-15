#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdlib.h>
#include <string.h>

typedef void (*uButtonCall)(void *cbdata);

/* Defintion of Button Data Structure */
struct uButton{
	char *text;
	int text_width;
	int font_ascent;
	int width, height;
	unsigned long border, background, foreground;
	void *cbdata;
	uButtonCall on_click;	

};

