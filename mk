#!/bin/bash

# Compile bs.s bc.c
	echo compiling...
	as86 -o bs.o  bs.s
	bcc -c -ansi  bc.c 
	bcc -c -ansi  io.c
	ld86 -d bs.o bc.o io.o /usr/lib/bcc/libc.a
	#x86_64-linux-gnu/libc.a

# make a fresh copy of vdisk
	echo copying virtual disk
	cp vdisk vdiskcp

# dump a.out to a VIRTUAL HD:
	echo dumping a.out to virtual disk
	dd if=a.out of=vdiskcp bs=16 count=27 conv=notrunc
	dd if=a.out of=vdiskcp bs=512 seek=1  conv=notrunc

# Run QEMU on vdiskcp
	echo running qemu
	qemu-system-x86_64 -hda vdiskcp

