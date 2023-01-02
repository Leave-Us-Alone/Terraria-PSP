#include <src/terraria.h>

void mainLoop() {
    while(true) {
        updateControls();
        startDrawing();
        clearScreen(0);

        int padding = 10;
        fillRect(padding,padding, 30,30, 0xFF0000FF);
        if (pad.held.cross)
            fillRect(50,10, 30,30, 0xFF00FF00);
        
        swapScreen();
        endDrawing();
    }
}
