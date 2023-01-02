#ifndef _DEFINE_NAMES_
#define _DEFINE_NAMES_
    #define startDrawing() oslStartDrawing()
    #define clearScreen(x) oslClearScreen(x)
    #define swapScreen() oslSwapBuffers()
    #define endDrawing() oslEndDrawing()

    #define updateControls() oslReadKeys()
    #define pad osl_pad

    #define fillRect(x,y,w,h,c) oslDrawFillRect(x,y,x+w,y+h,c)
#endif