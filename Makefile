TARGET = Terraria
OBJS = src/callbacks.o \
main.o

INCDIR = 
CFLAGS = -O3 -g -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP Stuff
BUILD_PRX = 1
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1

LIBDIR = 
LDFLAGS = 

MYLIBS = 
STDLIBS = -lpsppower
LIBS = $(STDLIBS) $(MYLIBS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Terraria
#PSP_EBOOT_ICON = ICON0.PNG
PSP_EBOOT_PIC1 = PIC1.png

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak