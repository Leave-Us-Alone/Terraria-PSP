#include <pspkernel.h>
#include <pspdebug.h>
#include <psppower.h>
#include <src/callbacks.h>

PSP_MODULE_INFO("Terraria", PSP_MODULE_USER, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

int main() {
    SetupCallbacks();
    scePowerSetClockFrequency(333, 333, 166);

    pspDebugScreenInit();
    pspDebugScreenPrintf("Terraria World!");

    // sceKernelExitGame();
    return 0;
}
