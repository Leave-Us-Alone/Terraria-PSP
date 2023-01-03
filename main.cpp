#include <pspkernel.h>
#include <psppower.h>
#include <pge/pge.h>

#include <src/callbacks.h>
#include <src/defs.h>

PSP_MODULE_INFO("Terraria", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

int main() {
    SetupCallbacks();
    scePowerSetClockFrequency(333, 333, 166);

    pgeGfxInit(PGE_PIXEL_FORMAT_8888);
    pgeControlsInit();
    pgeFontInit();

    pgeTexture* bg = pgeTextureLoad("assets/bg.png", PGE_VRAM, 1);
	if (!bg) pgeExit();

    pgeFont* font = pgeFontLoad("assets/font/sans.ttf", 10, PGE_FONT_SIZE_PIXELS, PGE_VRAM);
	if (!font) pgeExit();

    while (pgeRunning()) {
        pgeControlsUpdate();
        pgeGfxStartDrawing();
        pgeGfxClearScreen(0);

		pgeTextureActivate(bg);
        pgeGfxDrawTextureEasy(bg, 0, 0, .0f, 255);

        fillRect(10,10, 30,60, 0xFF0000FF, 0);
        if (pgeControlsHeld(PGE_CTRL_CROSS))
            fillRect(40,70, 30,60, 0xFFFF00FF, 0);

        float freeRam = pgeSystemGetFreeRam()/1024/1024;
        char ram[50];
        sprintf(ram, "free RAM: %.2f MB", freeRam);
        pgeFontActivate(font);
        pgeFontPrintf(font, 100, 100, 0xFF00FF00, ram);

        pgeGfxEndDrawing();
		pgeGfxSwapBuffers(PGE_WAIT_VSYNC);
    }

	pgeTextureDestroy(bg);
	pgeFontDestroy(font);
	
    pgeControlsShutdown();
	pgeFontShutdown();
	pgeGfxShutdown();
	pgeExit();
    return 0;
}
