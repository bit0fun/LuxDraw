#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "debug.h"

#define DEBUG_MODE

#define WIN_X_POS		960
#define WIN_Y_POS		540
#define WIN_HEIGHT  	480
#define WIN_WIDTH		640
#define WIN_BORDER		5 /* Only available without window manager  */

#define XEVENT_MASK		(StructureNotifyMask | ExposureMask | KeyPressMask)


typedef struct win_param {
	int height;			/* Height */
	int width;			/* Width */
	int xpos;			/* X Position */
	int ypos;			/* Y position */
	int border;			/* Border width */
	unsigned long bdc;	/* Border Color */
	unsigned long bgc;	/* Background Color */
} win_param;

typedef struct text_param {
	const char* font;	/* Font name */
	const char* text;	/* Actual Text */
	int	length;			/* Length of text */	
	int xpos;			/* X Position */
	int ypos;			/* Y Position */
} text_param;

/*
int drawString( const char* s, ){
	return 0;
}*/

int main(int argc, char** argv){
	Display *disp;
	int screen;
	Window win;
	XEvent	xevent;
	
	win_param root_win = {
		WIN_HEIGHT,
		WIN_WIDTH,
		WIN_X_POS,
  		WIN_Y_POS,
		WIN_BORDER,
		0,	/* Placeholder values*/	
		0
	};


	disp = XOpenDisplay(NULL);

	if(disp == NULL){
		fprintf(stderr, "Could not find display. Exiting\n");
	}

	screen = DefaultScreen(disp);





	/* Setting up colors */
	Colormap cmap;
	XColor	xcolor1, xcolor2;
	cmap = DefaultColormap(disp, screen);
	XAllocNamedColor(disp, cmap, "Indigo", &xcolor1, &xcolor2);
	root_win.bdc = xcolor1.pixel;	/* Setting border color to Indigo */
	XAllocNamedColor(disp, cmap, "Light Gray", &xcolor1, &xcolor2);
	root_win.bgc = xcolor1.pixel;
	/* Creating Graphics Context  */
//	GC gc = XCreateGC(disp, win, 0, NULL);


	win = XCreateSimpleWindow(disp, RootWindow(disp, screen),root_win.xpos, 
			root_win.ypos, root_win.width, root_win.height, root_win.border,
			root_win.bdc, root_win.bgc);

	/* Allow Window close events to not throw errors */
	Atom delwin = XInternAtom( disp, "WM_DELETE_WINDOW", 0 );
	XSetWMProtocols(disp, win, &delwin, 1);


	XSelectInput(disp, win, XEVENT_MASK ); 
	XMapWindow(disp, win);

	XStoreName(disp, win, "Program");

	XFontStruct* font;
	text_param test_txt = {
		"-*-Hack-*-10-*",
		"Test",
		4,
		10,
		50,
	};


	char* defaultfont = "-*-DejaVu Sans Mono-*-10-*";
//-misc-hack-medium-i-normal--0-0-0-0-m-0-iso8859-1
	font = XLoadQueryFont(disp, "-*-hack-medium-r-normal-*");
	if( !font) {
		debug("Couldn't find \' Hack \' font, trying DejaVu Sans Mono\n");
		font = XLoadQueryFont(disp, defaultfont);
		if( !font) {
			debug("Unable to find preferred fonts, using fixed");	
			font = XLoadQueryFont(disp, "fixed");
		}
	}
//	test_txt.fid = (test_txt->font->fid);
	/* GC for drawing text */
	XGCValues values;
	values.font = font->fid;
	values.foreground = BlackPixel(disp, screen);
	values.line_width = 1;
	values.line_style = LineSolid;
	GC scribe = XCreateGC(disp, win, GCForeground | GCLineWidth | GCLineStyle | GCFont, &values);		
//	test_txt.scribe = &scribe;
	test_txt.length = XTextWidth(font, "test", strlen("test"));

	/* Ensure everything is written to the display */
	XFlush(disp);

	/* Process events */

	while(1){
		XNextEvent(disp, &xevent);

		/* Checking if resizing window */
		if(xevent.type == ConfigureNotify){
			if( (root_win.width != xevent.xconfigure.width) ||
				(root_win.height != xevent.xconfigure.height)){
				root_win.width =  xevent.xconfigure.width;
				root_win.height = xevent.xconfigure.height;
				printf("Changed size: width = %d | height = %d ", root_win.width, root_win.height);
			}
		
		}

		/* Draw or Redraw Window */
		if(xevent.type == Expose){
			XFillRectangle(disp, win, DefaultGC(disp, screen), 20, 20, 100, 10 );	
			XFlush(disp);
			XDrawString(disp, win, scribe, test_txt.xpos, test_txt.ypos, "test", 4);
			XFlush(disp);
		}
		
		/* Handle Key presses*/
		if(xevent.type == KeyPress){
			break;
		}

		/*Handle Window Close Event */
		if(xevent.type == ClientMessage){
			break;
		}


	}
	XDestroyWindow(disp, win);
	XCloseDisplay(disp);

	return 0;
}
