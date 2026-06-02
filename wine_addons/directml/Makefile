# Cross-compile DirectML stub for Windows x86_64
# Requires: apt install gcc-mingw-w64-x86-64

CC = x86_64-w64-mingw32-gcc
CFLAGS = -O2 -static-libgcc -Wall
TARGET = directml.dll

all: $(TARGET)

$(TARGET): directml.c
	$(CC) $(CFLAGS) -shared -o $@ $< -Wl,--kill-at

clean:
	rm -f $(TARGET) $(TARGET:.dll=.o)

.PHONY: all clean
