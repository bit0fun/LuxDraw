/* Drawing Function Wrapper */
#ifndef DRAW_LIB_H
#define DRAW_LIB_H

/* Struct defintion for LuxDraw Window parameters */
struct LXwindow {
	int height;			/* Height */
	int width;			/* Width */
	int xpos;			/* X Position */
	int ypos;			/* Y position */
	int border;			/* Border width */
	unsigned long bdc;	/* Border Color */
	unsigned long bgc;	/* Background Color */
	unsigned long fgc;	/* Foreground Color */
} LXwindow;

/* Struct for QuickDraw Root Window*/

/* Struct for QuickDraw Text Parameters*/
struct LXtext {
	const char* text;	/* Actual Text */
	const char* font;	/* Font Name */
	const char* color;	/* Color of Text */
	unsigned int pt;	/* Point Size */
	int len;			/* String Length */
	int xpos;			/* X Position */
	int ypos;			/* Y Position */

} LXtext;

/* LuxDraw object */
typedef struct LXobject {

} LXobject;

/* Objects to draw in window */
LXObject* visibleObjects;

/* Function Definitions */

/* Sets up environment */
int initQuickDraw( Display** disp, int* screen, Window* win, XEvent* event);

/*Creates Root Window */
int initRootWindow( LXWindow* rwin );

#endif	/* DRAW_LIB_H */
