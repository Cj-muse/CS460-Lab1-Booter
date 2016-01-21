#!/bin/bash

# Compile bs.s bc.c
	as86 -o bs.o  bs.s
	bcc -c -ansi  bc.c
	ld86 -d bs.o bc.o io.o /usr/lib/bcc/libc.a  # io.o is from KCW's io.c

# make a fresh copy of vdisk
	cp vdisk vdiskcp

# dump a.out to a VIRTUAL HD:
	dd if=a.out of=vdiskcp bs=16 count=27 conv=notrunc
	dd if=a.out of=vdiskcp bs=512 seek=1  conv=notrunc

# Run QEMU on vdiskcp
	qemu -hda vdiskcp

