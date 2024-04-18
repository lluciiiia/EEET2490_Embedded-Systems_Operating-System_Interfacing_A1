#--------------------------------------Makefile-------------------------------------

CFILES = $(wildcard ./kernel/*.c)
OFILES = $(CFILES:./kernel/%.c=./object/%.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib

all: clean gpio_build uart1_build ./object/kernel8.img run1
uart1: clean gpio_build uart1_build ./object/kernel8.img run1
uart0: clean gpio_build uart0_build ./object/kernel8.img run0

./object/boot.o: ./kernel/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./kernel/boot.S -o ./object/boot.o

uart1_build: ./kernel/uart1.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./kernel/uart1.c -o ./object/uart.o

uart0_build: ./peripheral/uart0.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./peripheral/uart0.c -o ./object/uart.o

gpio_build: ./peripheral/gpio.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./peripheral/gpio.c -o ./object/gpio.o

./object/kernel.o: ./kernel/kernel.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

./object/kernel8.img: ./object/boot.o ./object/uart.o ./object/gpio.o ./object/kernel.o
	aarch64-none-elf-ld -nostdlib ./object/boot.o ./object/uart.o ./object/gpio.o ./object/kernel.o -T ./kernel/link.ld -o ./object/kernel8.elf
	aarch64-none-elf-objcopy -O binary ./object/kernel8.elf ./object/kernel8.img

clean:
	del .\object\kernel8.elf *.o *.img

# Run emulation with QEMU
run1: 
	@echo UART1!!!!
	qemu-system-aarch64 -M raspi3 -kernel ./object/kernel8.img -serial null -serial stdio

run0: 
	@echo UART0!!!!
	qemu-system-aarch64 -M raspi3 -kernel ./object/kernel8.img -serial stdio
