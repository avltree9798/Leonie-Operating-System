COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
CFLAGS = -m32 -c -ffreestanding
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T src/link.ld
EMULATOR = qemu-system-i386
EMULATOR_FLAGS = -kernel

OBJS = obj/kasm.o obj/kc.o obj/idt.o obj/isr.o obj/keyboard.o obj/monitor.o obj/string.o obj/system.o obj/stdlib.o obj/bash.o
OUTPUT = leonieOS/boot/kernel.bin

run: all
	$(EMULATOR) $(EMULATOR_FLAGS) $(OUTPUT)

all:$(OBJS)
	mkdir leonieOS/boot/ -p
	$(LINKER) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

obj/kasm.o:src/kernel.asm
	$(ASSEMBLER) $(ASFLAGS) -o obj/kasm.o src/kernel.asm

obj/kc.o:src/kernel.c
	$(COMPILER) $(CFLAGS) src/kernel.c -o obj/kc.o

obj/idt.o:src/idt.c
	$(COMPILER) $(CFLAGS) src/idt.c -o obj/idt.o

obj/keyboard.o:src/keyboard.c
	$(COMPILER) $(CFLAGS) src/keyboard.c -o obj/keyboard.o

obj/isr.o:src/isr.c
	$(COMPILER) $(CFLAGS) src/isr.c -o obj/isr.o

obj/monitor.o:src/monitor.c
	$(COMPILER) $(CFLAGS) src/monitor.c -o obj/monitor.o

obj/string.o:src/string.c
	$(COMPILER) $(CFLAGS) src/string.c -o obj/string.o

obj/system.o:src/system.c
	$(COMPILER) $(CFLAGS) src/system.c -o obj/system.o

obj/stdlib.o:src/stdlib.c
	$(COMPILER) $(CFLAGS) src/stdlib.c -o obj/stdlib.o

obj/bash.o:src/bash.c
	$(COMPILER) $(CFLAGS) src/bash.c -o obj/bash.o

build:all
	#Activate the install xorr if you do not have it already installed
	sudo apt-get install xorriso
	rm leonieOS/boot/grub/ -r -f
	mkdir leonieOS/boot/grub/
	echo set default=0 >> leonieOS/boot/grub/grub.cfg
	echo set timeout=0 >> leonieOS/boot/grub/grub.cfg
	echo menuentry "leonieOS" { >> leonieOS/boot/grub/grub.cfg
	echo         set root='(hd96)' >> leonieOS/boot/grub/grub.cfg
	echo         multiboot /boot/kernel.bin >> leonieOS/boot/grub/grub.cfg
	echo } >> leonieOS/boot/grub/grub.cfg

	grub-mkrescue -o leonieOS.iso leonieOS/

clear:
	rm -f obj/*.o
	rm -r -f leonieOS/
