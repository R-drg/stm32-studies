
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall
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

flash: bin
	@echo "Flashing..."
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c init -c "reset halt" -c "flash write_image erase build/blink.bin 0x08000000" -c exit

bin: elf
	arm-none-eabi-objcopy -O binary $(OUT_DIR)/blink.elf $(OUT_DIR)/blink.bin

elf: $(OBJECT)
	arm-none-eabi-gcc -nostdlib -T stm32f411-rom.ld build/main.o build/startup.o -o build/blink.elf

obj: $(OBJECT)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@
clean:
	$(RM) *.o $(OUT_DIR)
	