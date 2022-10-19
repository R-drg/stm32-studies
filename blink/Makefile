
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall
LFLAGS = -mcpu=cortex-m4 -mthumb -Wall -nostartfiles 
RM = rm -rf
SRC_FILES = main.c \
			startup.c
SRC_DIR = src
SOURCE = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OUT_DIR = build
# we use :.c=.o to replace .c with .o
#$(VARIABLE:OLD_SUFFIX=NEW_SUFFIX)
OBJECT = $(subst $(SRC_DIR), $(OUT_DIR), $(SOURCE:.c=.o))

$(shell mkdir -p $(OUT_DIR))

all: obj elf

elf:
	$(CC) $(LFLAGS) $(OBJECT) --specs=nosys.specs -o $(OUT_DIR)/main.elf

obj: $(OBJECT)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@
clean:
	$(RM) *.o $(OUT_DIR)