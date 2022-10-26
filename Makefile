CC=gcc
CFLAGS=-Wall -o
CFILES=main.c lib/files/files.c lib/cdatabase/cdatabase.c
OUTFILES=cdatabase

all:
	make build
	make run

build:
	$(CC) $(CFLAGS) $(OUTFILES) $(CFILES)

run:
	./$(OUTFILES)