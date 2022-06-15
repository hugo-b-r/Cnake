
CC = gcc
UNAME_S := $(shell uname -s)

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

TARGET = $(BIN_DIR)/game

SRC := $(wildcard $(SRC_DIR)/*.c) 
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS := -Wall
CPPFLAGS := -Iinc -MMD -MP
LDFLAGS :=
LDLIBS :=




ifeq ($(PLATFORM), windows)
    LDLIBS += -lmingw32
    CFLAGS += -D WIN32 -D CLI
endif
ifeq ($(PLATFORM), linux)
        CFLAGS += -D __linux__ -D CLI
endif
ifeq ($(PLATFORM), numworks)
    LDFLAGS += -Linc
    CFLAGS += -D NUMWORKS
endif
ifeq ($(OS), Windows_NT)
    LDLIBS += -lmingw32
    CFLAGS += -D WIN32
endif
ifeq ($(UNAME_S),Linux)
    CCFLAGS += -D __linux__
endif
ifeq ($(UNAME_S),Darwin)
    CCFLAGS += -D OSX -D CLI
endif




.PHONY: all clean

all: $(TARGET)
	@echo -e "$(PLATFORM) done.\n"

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@


clean:
	$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
	@echo -e "Clean.\n"

cleanandbuild: clean all

-include $(OBJ:.o=.d)
