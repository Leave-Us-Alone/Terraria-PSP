TARGET = Terraria
OBJS = src/callbacks.o \
main.o

INCDIR = 
CFLAGS = -O3 -g -G0 -Wall -D__PSP__
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP Stuff
BUILD_PRX = 1
PSP_FW_VERSION = 340
PSP_LARGE_MEMORY = 1

LIBDIR = 
LDFLAGS = 

LIBS = -lpge -lpsppower -lpspgum -lpspgu -lpng -lz -lm -lfreetype -lpspwlan -lpspopenpsid

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Terraria
PSP_EBOOT_ICON = logo.png
PSP_EBOOT_PIC1 = logo.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak