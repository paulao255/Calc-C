PROG_NAME = Ccalc
VERSION = 2026-04-14

CC = gcc
STD = c90
CFLAGS = -fdiagnostics-color=always -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wformat=2 -Wnull-dereference -Wstrict-prototypes -Wmissing-prototypes -Wcast-align -Wpointer-arith -Wundef -funroll-loops -flto -mtune=native -march=native -fPIE -pie -fstack-protector-all -O3
INCLUDES = -I./C-Utils/include
LIBS = -lm
SRCS = ../src/Main.c ./C-Utils/include/C-Utils/cutils.c
OBJS =

all:
	@if [ ! -d "build" ]; then mkdir build; fi
	cd build && git clone https://github.com/paulao255/C-Utils.git && mkdir bin && $(CC) $(INCLUDES) $(SRCS) $(OBJS) -std=$(STD) $(CFLAGS) -v $(LIBS) -o bin/$(PROG_NAME)

run: all
ifeq ($(OS),Windows_NT)
	.\build\bin\$(PROG_NAME).exe
else
	./build/bin/$(PROG_NAME)
endif

install: all
ifeq ($(OS),Windows_NT)
	@if not exist "C:\Program Files\PFC" mkdir "C:\Program Files\PFC"
	copy build\bin\$(PROG_NAME).exe "C:\Program Files\PFC\$(PROG_NAME).exe"
	powershell -Command "$$s=(New-Object -COM WScript.Shell).CreateShortcut([Environment]::GetFolderPath('Desktop')+'\$(PROG_NAME).lnk');$$s.TargetPath='C:\Program Files\PFC\$(PROG_NAME).exe';$$s.Save()"
else
	sudo cp build/bin/$(PROG_NAME) /usr/local/bin/$(PROG_NAME)
endif

uninstall:
ifeq ($(OS),Windows_NT)
	@if exist "C:\Program Files\PFC\$(PROG_NAME).exe" del "C:\Program Files\PFC\$(PROG_NAME).exe" && rmdir "C:\Program Files\PFC"
	@if exist "C:\Users\%USERNAME%\Desktop\$(PROG_NAME).lnk" del "C:\Users\%USERNAME%\Desktop\$(PROG_NAME).lnk"
else
	sudo rm -f /usr/local/bin/$(PROG_NAME)
endif

clean:
ifeq ($(OS),Windows_NT)
	@if exist build rmdir /s /q build
else
	rm -rf build
endif

help:
	@echo "App name: $(PROG_NAME)"
	@echo "Version: $(VERSION)"
	@echo "Standard: $(STD)"
