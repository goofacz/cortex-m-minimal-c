/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <stdint.h>

extern uint32_t _BSS_BEGIN;
extern uint32_t _BSS_END;
extern uint32_t _DATA_FLASH_BEGIN;
extern uint32_t _DATA_FLASH_END;
extern uint32_t _DATA_RAM_BEGIN;
extern uint32_t _DATA_RAM_END;

extern int main (void);

static void initialize_bss_section (void)
{
    for (uint32_t* bss_word = &_BSS_BEGIN; bss_word < &_BSS_END; bss_word++)    {
        *bss_word = 0;
    }
}

static void initialize_data_section (void)
{
    uint32_t* data_flash_word = &_DATA_FLASH_BEGIN;
    for (uint32_t* data_ram_word = &_DATA_RAM_BEGIN; data_ram_word < &_DATA_RAM_END; data_ram_word++)
    {
        *data_ram_word = *data_flash_word;
        data_flash_word++;
    }
}

void interrupt_reset ()
{
    initialize_bss_section ();
    initialize_data_section ();

    main ();
    
    while (1)    {
        // ...
    }
}

void interrupt_nmi ()
{
    while (1)    {
        // ...
    }
}

void interrupt_hard_fault ()
{
    while (1)    {
        // ...
    }
}

void interrupt_memmanage ()
{
    while (1)    {
        // ...
    }
}

void interrupt_bus_fault ()
{
    while (1)    {
        // ...
    }
}

void interrupt_usage_fault ()
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_0 ()
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_1 ()
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_2 ()
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_3 ()
{
    while (1)    {
        // ...
    }
}

void interrupt_svcall ()
{
    while (1)    {
        // ...
    }
}

void interrupt_debug ()
{
    while (1)    {
        // ...
    }
}


void interrupt_reserved_4 ()
{
    while (1)    {
        // ...
    }
}

void interrupt_pendsv ()
{
    while (1)    {
        // ...
    }
}

void interrupt_systick ()
{
    while (1)    {
        // ...
    }
}
