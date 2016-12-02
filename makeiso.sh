rm leonieOS/boot/grub/ -r -f
        mkdir leonieOS/boot/grub/
        echo set default=0 >> leonieOS/boot/grub/grub.cfg
        echo set timeout=0 >> leonieOS/boot/grub/grub.cfg
        echo menuentry "leonieOS" { >> leonieOS/boot/grub/grub.cfg
        echo         set root='(hd96)' >> leonieOS/boot/grub/grub.cfg
        echo         multiboot /boot/kernel.bin >> leonieOS/boot/grub/grub.cfg
        echo } >> leonieOS/boot/grub/grub.cfg

        grub-mkrescue -o leonieOS.iso leonieOS/

