ifeq ($(OS), Windows_NT)
	LDFLAGS = -lmingw32
	CFLAGS += -D WIN32
	ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif


CC = gcc
CFLAGS += -Wall -O -g
TARGET = game

SRC  += $(wildcard src/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c) 
OBJ  = $(SRC:.c=.o)
OUTPUT_FOLDER = bin

all: dirs $(TARGET)
	@echo -e "Done.\n"

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
	@echo -e "Clean.\n"

mrproper: clean
	rm -rf $(OUTPUT_FOLDER)

cleanandbuild: clean all
