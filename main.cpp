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

    pgeTexture* bg = pgeTextureLoad("assets/bg.png", PGE_VRAM, 1);
	if (!bg) pgeExit();

    while (pgeRunning()) {
        pgeGfxStartDrawing();
        pgeGfxClearScreen(0);

		pgeTextureActivate(bg);
        pgeGfxDrawTextureEasy(bg, 0, 0, .0f, 255);

        fillRect(10,10, 30,60, 0xFF0000FF, 0);

        pgeGfxEndDrawing();
		pgeGfxSwapBuffers(PGE_WAIT_VSYNC);
    }

	pgeGfxShutdown();
	pgeExit();
    return 0;
}
