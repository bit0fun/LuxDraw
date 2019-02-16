#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <stdlib.h>
#include <string.h>

/*** Macros ***/

/* Gets the default GC from Xlib */
#define DEFGC(disp) (DefaultGC(disp, DefaultScreen(disp)) )
