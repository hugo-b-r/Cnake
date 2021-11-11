CC = gcc
CFLAGS = -Wall -O
LDFLAGS = 
TARGET = game

SRC  = $(wildcard src/**/*.c) $(wildcard src/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c)
OBJ  = $(SRC:.c=.o)
OUTPUT_FOLDER = bin


all: dirs $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) -o $(OUTPUT_FOLDER)/$(TARGET) $^ $(LDFLAGS)

%.o: %.c
	$(CC) `pkg-config --cflags --libs CSFML` -o $@ -c $< $(CFLAGS)

dirs:
	mkdir $(OUTPUT_FOLDER)

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(OUTPUT_FOLDER)