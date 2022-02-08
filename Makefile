UNAME_O = $(shell uname -o)

ifeq ($(UNAME_O), Msys)
LDFLAGS = -lmingw32
SRC = $(wildcard src/windows/*.c) $(wildcard src/windows/**/*.c)
else
SRC = $(wildcard src/gnu_linux/*.c) $(wildcard src/gnu_linux/**/*.c)
endif


CC = gcc
CFLAGS = -Wall -O #-lSDL2main -lSDL2 -lSDL2_image
#LDFLAGS += -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
TARGET = game

SRC  += $(wildcard src/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c)
OBJ  = $(SRC:.c=.o)
OUTPUT_FOLDER = bin

all: dirs $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(OUTPUT_FOLDER)/$(TARGET) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

#`pkg-config --cflags --libs sdl2`

dirs:
	mkdir -p $(OUTPUT_FOLDER)

clean:
	rm -rf $(OBJ)
	rm -f $(OUTPUT_FOLDER)/$(TARGET)

mrproper: clean
	rm -rf $(OUTPUT_FOLDER)
