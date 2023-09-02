
UNAME_S := $(shell uname -s)

NUMWORKS_API := api/ibapi.a

TARGET = game

SRC := $(addprefix src/, main.c game.c positions.c)


CFLAGS := -Wall
CPPFLAGS := -MMD -MP
LDFLAGS :=
LDLIBS :=

WINDOWS_INCLUDE := windows
LINUX_INCLUDE := linux
NUMWORKS_INCLUDE := numworks
INCLUDE_PATH := -Isrc



ifeq ($(PLATFORM), windows)
    SRC += $(addprefix src/windows/, init.c platform.c)
    INCLUDE_PATH += $(addprefix -I, src/windows)
    CC = gcc
    LDLIBS += -lmingw32
    CFLAGS += -D WIN32 -D CLI -D PLATFORM=windows $(INCLUDE_PATH)

endif
ifeq ($(PLATFORM), linux)
    SRC += $(addprefix src/linux/, init.c platform.c)
    INCLUDE_PATH += $(addprefix -I, src/linux)
    CC = gcc
	LDFLAGS += -lncurses -ltinfo
    CFLAGS += -D __linux__ -D CLI -D PLATFORM=linux $(INCLUDE_PATH)
endif
ifeq ($(PLATFORM), numworks)
    SRC += $(addprefix src/numworks/, init.c platform.c)
    INCLUDE_PATH += $(addprefix -I, src/numworks)
    CC = arm-none-eabi-gcc
    OBJCOPY = arm-none-eabi-OBJCOPY
    AR = arm-none-eabi-ar
    CFLAGS += -D NUMWORKS -DNDEBUG -ggdb3 -Os -mcpu=cortex-m7 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=soft -fno-common -fdata-sections -ffunction-sections -fno-exceptions -D PLATFORM=numworks $(INCLUDE_PATH)
    CPPFLAGS += -Iapi
    LDFLAGS += -Wl,-Lapi -Wl,--gc-sections -Wl,--entry=entrypoint --specs=nosys.specs -nostartfiles -Wl,-Ur
    LDLIBS += -lapi -lc
    TARGET = app.elf
    SRC += $(addprefix src/numworks/, init.c platform.c)
else
    ifeq ($(OS), Windows_NT)
        SRC += $(addprefix src/windows/, init.c platform.c)
        INCLUDE_PATH += $(addprefix -I, src/windows)
        CC = gcc
        LDLIBS += -lmingw32
        CFLAGS += -D WIN32 -D CLI $(INCLUDE_PATH)
    endif
    ifeq ($(UNAME_S),Linux)
        SRC += $(addprefix src/linux/, init.c platform.c)
        INCLUDE_PATH += $(addprefix -I, src/linux)
		LDFLAGS += -lncurses -ltinfo
        CFLAGS += -D __linux__ $(INCLUDE_PATH)
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
