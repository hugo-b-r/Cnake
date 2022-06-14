
CC = gcc

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

TARGET = $(BIN_DIR)/game

SRC := $(wildcard $(SRC_DIR)/*.c) 
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS := -Wall
CPPFLAGS := -Iinc -MMD -MP
LDFLAGS := -Llib
LDLIBS :=

ifeq ($(OS), Windows_NT)
	LDLIBS = -lmingw32
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


.PHONY: all clean

all: $(TARGET) cli
	@echo -e "Done.\n"

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

cli:
    CFLAGS += -D CLI

clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
	@echo -e "Clean.\n"

cleanandbuild: clean all

-include $(OBJ:.o=.d)
