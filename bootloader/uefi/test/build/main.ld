OUTPUT_FORMAT(elf64-x86-64)
OUTPUT_ARCH(i386:x86-64)
ENTRY(efi_main)
SECTIONS
{
    . = 0x2000;
    . = ALIGN(0x1000);
    .text :
    {
       *(.text)
       *(.text.*)
       . = ALIGN(0x10);
    }

    . = ALIGN(0x1000);
    .data :
    {
        *(.rodata*)
        *(.got.plt)
        *(.got)
        *(.data*)
        *(.sdata)
        /* TODO: figure out how to move .bss in such a way that the PE32+ loader
         * doesn't complain.
         */
        *(.sbss)
        *(.scommon)
        *(.dynbss)
        *(.bss)
        *(COMMON)
        *(.rel.local)
    }

    . = ALIGN(0x1000);

    /* A .reloc section is required to flag the final PE32+ file as relocatable.
     * Here we hardcode one block with one entry to keep the PE32+ loader happy.
     */
    _a = .;
    . = ALIGN(0x1000);
    .reloc :
    {
        LONG(. - _a);
        LONG(0x0a);
        SHORT(0x00);
    }
}