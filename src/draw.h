/* Drawing Function Wrapper */
#ifndef DRAW_LIB_H
#define DRAW_LIB_H

#include <X11/Xlib.h>

/* Struct defintion for LuxDraw Window parameters */
struct uXwindow {
	int height;			/* Height */
	int width;			/* Width */
	int xpos;			/* X Position */
	int ypos;			/* Y position */
	int border;			/* Border width */
	unsigned long bdc;	/* Border Color */
	unsigned long bgc;	/* Background Color */
	unsigned long fgc;	/* Foreground Color */
};

/* Struct for QuickDraw Root Window*/

/* Struct for QuickDraw Text Parameters*/
struct uXtext {
	const char* text;	/* Actual Text */
	const char* font;	/* Font Name */
	const char* color;	/* Color of Text */
	unsigned int pt;	/* Point Size */
	int len;			/* String Length */
	int xpos;			/* X Position */
	int ypos;			/* Y Position */
};


/* Types of Objects */
enum uXObjType {
	UXO_NULL,			/* Place Holder Object */
	UXO_WINDOW,			/* Window */
	UXO_BUTTON,			/* Button */
	UXO_MAX				/* Max number of kinds of objects */
};



/* LuxDraw object */
struct uXObject {
	enum uXObjType type;		/* Kind of Object */
};

/* Objects to draw in window */
struct uXObject* visibleObjects;

/* Function Definitions */

/* Sets up environment */
int initMuDraw( Display** disp, int* screen, Window* win, XEvent* event);

/*Creates Root Window */
int initRootWindow( struct uXWindow* rwin );

/* Makes object visible */
int setVisible( struct uXObject* uxo );

/* Makes object invisible */
int clearVisible( struct uXObject* uxo );

/* Clean up X Displays */
int cleanupX( Display** disp, Window* win );


#endif	/* DRAW_LIB_H */
