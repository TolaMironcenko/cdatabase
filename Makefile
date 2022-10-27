CC=gcc
CFLAGS=-Wall -o
CFILES=main.c lib/files/files.c lib/cdatabase/cdatabase.c lib/termcolors/termcolors.c
OUTFILES=cbase

all:
	make build
	make run

build:
	$(CC) $(CFLAGS) $(OUTFILES) $(CFILES)

run:
	./$(OUTFILES)