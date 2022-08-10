
UNAME_S := $(shell uname -s)

NUMWORKS_API := api/ibapi.a

TARGET = game

SRC := $(wildcard *.c) 
OBJ := $(SRC:%.c=%.o)

CFLAGS := -Wall
CPPFLAGS := -Iinc -MMD -MP
LDFLAGS :=
LDLIBS :=




ifeq ($(PLATFORM), windows)
    CC = gcc
    LDLIBS += -lmingw32
    CFLAGS += -D WIN32 -D CLI
endif
ifeq ($(PLATFORM), linux)
    CC = gcc
    CFLAGS += -D __linux__ -D CLI
endif
ifeq ($(PLATFORM), numworks)
    CC = arm-none-eabi-gcc
    OBJCOPY = arm-none-eabi-OBJCOPY
    AR = arm-none-eabi-ar
    CFLAGS += -D NUMWORKS -DNDEBUG -ggdb3 -Os -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=soft -fno-common -fdata-sections -ffunction-sections -fno-exceptions
    CPPFLAGS += -Iapi
    LDFLAGS += -Wl,-Lapi -Wl,--gc-sections -Wl,--entry=entrypoint --specs=nosys.specs -nostartfiles -Wl,-Ur 
    LDLIBS += -lapi -lc
    TARGET = app.elf
else 
    ifeq ($(OS), Windows_NT)
        CC = gcc
        LDLIBS += -lmingw32
        CFLAGS += -D WIN32 -D CLI
    endif
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D __linux__
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX -D CLI
    endif
endif




.PHONY: all clean

all: $(TARGET)
	@echo -e "Done.\n"

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) *.o
	$(RM) *.d
	$(RM) app.elf
	$(RM) game

	@echo -e "Clean.\n"

cleanandbuild: clean all

-include $(OBJ:.o=.d)
