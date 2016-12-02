bits  32
section         .text
        align   4           ;4 bytes
        dd      0x1BADB002  ;magic number buat bootloader
        dd      0x00        ;flags
        dd      - (0x1BADB002+0x00) ;checksumnya, m+f+c harus = 0
global start
extern kmain
start:
        cli     ;bersihin interrupt
        call kmain ;panggil fungsinya
        hlt
