/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

ENTRY(interrupt_reset)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0000000, LENGTH = 0x80000
    STACK (rw): ORIGIN = 0x20004FFC, LENGTH = 0K
    RAM (rw) : ORIGIN = 0x20000000, LENGTH = 0x10000
}
 
SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table))
        *(.text)
    } >FLASH
    
    .bss :
    {
        _BSS_BEGIN = .;
        *(.bss.*)
        _BSS_END = .;
    } >RAM

    .stack :
    {
        _STACK_HEAD = .;
    } >STACK
}  
