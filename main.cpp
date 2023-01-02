#include <pspkernel.h>
#include <pspdebug.h>
#include <psppower.h>
#include <src/terraria.h>

PSP_MODULE_INFO("Terraria", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

int main() {
    oslInit(0);
    oslInitGfx(OSL_PF_8888, 1);
    
    mainLoop();

    oslEndGfx();
    return 0;
}
