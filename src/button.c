#include "button.h"

int uButtonSetup(Display *disp, Window parent, char *s, XFontStruct *font,
				int x_pos, int y_pos, int width, int height,
				unsigned long fg, unsigned long bg, unsigned long border,
				XContext xcxt, uButtonCall call, void *cbdata){
	
	struct uButton *button;
	Window win;
	int tlen = strlen( s ); /* length of text for button */

	/* Setting border width to 2 */		
	win = XCreateSimpleWindow( disp, parent, x_pos, y_pos, width, height, 2, border, bg );
	
	/* check if win was setup properly */
	if( win == NULL ){
		/* couldn't make window */		
		return 1;
	} 
	
	button = calloc( sizeof( *button ), 1 );
	if( button == NULL ){
		/* couldn't allocate memory for button */
	}
}

void uButtonConfigure( struct uButton *button, XEvent *xev){

}

int uButtonHover( struct uButton *button, XEvent *xev){
	XSetWindowAttributes attr;
	if( button == NULL ){
		return 1;	
	} else {
		/* Switch colors on hover */
		attr.background_pixel = button->border;	
		attr.border_pixel = button->background;
		XChangeWindowAttributes(xev->xany.display, xev->xany.window, CWBackPixel|CWBorderPixel, &attr);
		XClearArea(xev->xany.display, xev->xany.window, 0, 0, button->width, button->height, 1);
		return 0;
	}
}




int uButtonReturn( struct uButton *button, XEvent *xev ){
	XSetWindowAttributes attr;
	if( button == NULL ){
		/* No button found, return 1 */
		return 1;
	} else {
		attr.background_pixel = button->background;
		attr.border_pixel = button->border;
		XChangeWindowAttributes( xev->xany.display, xev->xany.window, CWBackPixel | CWBorderPixel, &attr );	
		XClearArea( xev->xany.display, xev->xany.window, 0, 0, button->width, button->height, 1);
		return 0;
	}
}

int uButtonDraw( struct uButton *button, XEvent *xev ){
	int tpos_x;	/* Text x coordinate within button */
	int tpos_y; /* Text y coordinate within button */
	int tlen;	/* Text length */

	/* Check for null pointer */
	if( button == NULL ){
		/* Button draw failed, return 1*/
		return 1;
	} else if ( button->text ) {
		tlen = strlen( button->text );	
		tpos_x = (button->width - button->text_width) >> 2;
		tpos_y = (button->height + button->font_ascent ) >> 2;
	
		/* Draw the string after getting positions */
		XDrawString(xev->xany.display, xev->xany.window, DEFGC(xev->xany.display), tpos_x, tpos_y, button->text, tlen );
		return 0;
	}

}
