#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdlib.h>
#include <string.h>

#include "mudraw_gen.h"
#include "debug.h"
#include "color.h"

typedef void (*uButtonCall)(void *cbdata);

/* Defintion of Button Data Structure */
struct uButton{
	char *text;
	int text_width;
	int font_ascent;
	int width, height;
	unsigned long border;
	unsigned long background;
	unsigned long foreground;
	void *cbdata;
	uButtonCall on_click;	

};


/*** Function Prototypes ***/


/* Setup function for uButton structure
 *
 * disp :	Display 
 * parent :	Parent X11 Window
 * s:		Button String
 * font :	Font to use for string
 * x_pos :	x coordinate
 * y_pos :	y coordinate
 * width :	width of button (pixels)
 * height :	height of button (pixels)
 * fg :		Foreground color
 * bg :		Background color
 * border : Border color
 *
 *
 *
 * */
int uButtonSetup(Display *disp, Window parent, char *s, XFontStruct *font,
				int x_pos, int y_pos, int width, int height,
				unsigned long fg, unsigned long bg, unsigned long border,
				XContext xcxt, uButtonCall call, void *cbdata);

/* Resizes button, ensures drawn properly
 *
 * button:	the button affected
 * xev:		the xevent variable
 * */

void uButtonConfigure( struct uButton *button, XEvent *xev);


/* Called when the mouse is over the button */
int uButtonHover( struct uButton *button, XEvent *xev);

/* Called when the mouse no longer is over the button */

int uButtonReturn( struct uButton *button, XEvent *xev );

/* Draws button to window */
int uButtonDraw( struct uButton *button, XEvent *xev );
