ENTRY(interrupt_reset)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0000000, LENGTH = 0x80000
    STACK (rw): ORIGIN = 0x20004FFC, LENGTH = 0K
    RAM (rw) : ORIGIN = 0x20010000, LENGTH = 0x10000
}
 
SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table))
        *(.text)
    } >FLASH
    
    .stack :
    {
        _STACK_HEAD = .;
    } >STACK
}  
