/* Default linker script, for normal executables */
/* Copyright (C) 2014-2015 Free Software Foundation, Inc.
   Copying and distribution of this script, with or without modification,
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.  */
OUTPUT_FORMAT("a.out-i386-linux", "a.out-i386-linux",
	      "a.out-i386-linux")
OUTPUT_ARCH(i386)
SEARCH_DIR("=/usr/i386-linux-gnuaout/lib");
PROVIDE (__stack = 0);
SECTIONS
{
  . = 0x1020;
  .text :
  {
    CREATE_OBJECT_SYMBOLS
    *(.text)
    /* The next six sections are for SunOS dynamic linking.  The order
       is important.  */
    *(.dynrel)
    *(.hash)
    *(.dynsym)
    *(.dynstr)
    *(.rules)
    *(.need)
    _etext = .;
    __etext = .;
  }
  . = ALIGN(0x1000);
  .data :
  {
    /* The first three sections are for SunOS dynamic linking.  */
    *(.dynamic)
    *(.got)
    *(.plt)
    *(.data)
    *(.linux-dynamic) /* For Linux dynamic linking.  */
    CONSTRUCTORS
    _edata  =  .;
    __edata  =  .;
  }
  .bss :
  {
    __bss_start = .;
   *(.bss)
   *(COMMON)
   . = ALIGN(4);
   _end = . ;
   __end = . ;
  }
}
