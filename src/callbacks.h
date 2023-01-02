#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>

extern "C"
{
    int exit_callback(int arg1, int arg2, void *common);
    int CallbackThread(SceSize args, void *argp);
    int SetupCallbacks(void);
}