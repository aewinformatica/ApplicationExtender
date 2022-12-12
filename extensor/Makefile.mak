CPP    = g++
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         splash.o \
         Title.o \
         HookManager.o \
         OtherAction.o \
         AppResource.res

LIBS   = -shared -Wl,--kill-at
CFLAGS = -DBUILD_DLL

.PHONY: Extensor.dll clean clean-after

all: Extensor.dll

clean:
	$(RM) $(OBJS) Extensor.dll

clean-after:
	$(RM) $(OBJS)

Extensor.dll: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.cpp main.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

splash.o: splash.cpp resource.h Utils.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

Title.o: Title.cpp Title.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

HookManager.o: HookManager.cpp StdAfx.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

OtherAction.o: OtherAction.cpp StdAfx.h OtherAction.h
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

