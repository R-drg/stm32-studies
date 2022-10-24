MEMORY
{
    FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rx):   ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS{
    /* This section must contain the .text section of all objs files */

    .text :
    {
        *(.isr_vectors)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _la_data = .;
        
    } > FLASH

    .data :
    {
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    } > SRAM AT> FLASH

    .bss :
    {
        _sbss = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > SRAM

}