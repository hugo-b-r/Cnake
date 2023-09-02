
UNAME_S := $(shell uname -s)

NUMWORKS_API := api/ibapi.a

TARGET = game

SRC := $(addprefix src/, main.c game.c positions.c)


CFLAGS := -Wall -Isrc
CPPFLAGS := -MMD -MP
LDFLAGS :=
LDLIBS :=





ifeq ($(PLATFORM), windows)
    SRC += src/windows.c
    CC = gcc
    LDLIBS += -lmingw32
    CFLAGS += -D WIN32 -D CLI -D PLATFORM=windows

endif
ifeq ($(PLATFORM), linux)
    SRC += src/linux.c
    CC = gcc
	LDFLAGS += -lncurses -ltinfo
    CFLAGS += -D __linux__ -D CLI -D PLATFORM=linux
endif
ifeq ($(PLATFORM), numworks)
    SRC += src/numworks.c
    CC = arm-none-eabi-gcc
    OBJCOPY = arm-none-eabi-OBJCOPY
    AR = arm-none-eabi-ar
    CFLAGS += -D NUMWORKS -DNDEBUG -ggdb3 -Os -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=soft -fno-common -fdata-sections -ffunction-sections -fno-exceptions -D PLATFORM=numworks
    CPPFLAGS += -Iapi
    LDFLAGS += -Wl,-Lapi -Wl,--gc-sections -Wl,--entry=entrypoint --specs=nosys.specs -nostartfiles -Wl,-Ur
    LDLIBS += -lapi -lc
    TARGET = app.elf
    SRC += $(addprefix src/numworks/, init.c platform.c)
else
    ifeq ($(OS), Windows_NT)
        SRC += src/windows.c
        CC = gcc
        LDLIBS += -lmingw32
        CFLAGS += -D WIN32 -D CLI
    endif
    ifeq ($(UNAME_S),Linux)
        SRC += src/linux.c
		LDFLAGS += -lncurses -ltinfo
        CFLAGS += -D __linux__
    endif
endif

OBJ := $(SRC:%.c=%.o)


.PHONY: all clean

all: $(TARGET)
	@echo -e "Done.\n"

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $^ $(LDLIBS) -o $@ $(LDFLAGS)

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
