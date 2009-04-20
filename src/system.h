//////////////////////////////////////////////////////////////////////
// File: system.h

#ifndef __SYSTEM_H
#define __SYSTEM_H

/* MEMORY.C */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

/* STRING.C */
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);
extern void kprintf( const char *format, ... );

/* SCRN.C */
extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

/* GDT.C */
typedef struct {
  unsigned short limit;
  unsigned short base;
  unsigned char  base1;
  unsigned char  access;
  unsigned char  flags;
  unsigned char  base2;
} gdt_entry_t;

extern void init_gdt();

/* IDT.C */
typedef struct {
   unsigned short offset_1; // offset bits 0..15
   unsigned short selector; // a code segment selector in GDT or LDT
   unsigned char zero;      // unused, set to 0
   unsigned char type_attr; // type and attributes, see below
   unsigned short offset_2; // offset bits 16..31
} idt_entry_t;

extern void init_idt();
extern void set_handler(idt_entry_t table[], int inter_num, int present, void (*handler)(void));

/* TSS.C */
typedef struct {
  unsigned long unused0;
  unsigned long esp0;
  unsigned long unused1;
  unsigned long esp1;
  unsigned long unused2;
  unsigned long esp2;
  unsigned long unused3;
  unsigned long unused4;
  unsigned long unused5;
  unsigned long unused6;
  unsigned long unused7;
  unsigned long unused8;
  unsigned long unused9;
  unsigned long unused10;
  unsigned long unused11;
  unsigned long unused12;
  unsigned long unused13;
  unsigned long unused14;
  unsigned long unused15;
  unsigned long unused16;
  unsigned long unused17;
  unsigned long unused18;
  unsigned long unused19;
  unsigned long unused20;
  unsigned long unused21;
  unsigned long unused22;
} tss_entry_t;

extern void init_tss();

#endif /* __SYSTEM_H */

