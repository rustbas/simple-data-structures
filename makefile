CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ansi -ggdb #-std=c89

all: main

main:
	$(CC) $(CFLAGS) main.c -o main.out
.PHONY: main
