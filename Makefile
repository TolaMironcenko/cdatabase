CC=gcc
CFLAGS=-Wall -o
CFILES=main.c
OUTFILES=cdatabase

all:
	make build
	make run

build:
	$(CC) $(CFLAGS) $(OUTFILES) $(CFILES)

run:
	./$(OUTFILES)