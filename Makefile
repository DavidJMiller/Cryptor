CC = gcc
CFLAGS = -std=c11 -Wall -g -O0

all: cipher

CIPHER = $(wildcard src/ciphers/*.c)
CIPHEROBJ = $(CIPHER:.c=.o)

cipher: $(CIPHEROBJ)
	$(CC) $(CFLAGS) -I../ -I. -o $@ $^
