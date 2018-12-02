CC = gcc
CFLAGS = -std=c11 -Wall -g -O0

SOURCE = src/ciphers/

all: ecb cbc ofb ctr

ecb: $(SOURCE)ecb.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ecb $(SOURCE)ecb.c src/blockfuncs/blockfuncs.c

ctr: $(SOURCE)ctr.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ctr $(SOURCE)ctr.c src/blockfuncs/blockfuncs.c

cbc: $(SOURCE)cbc.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)cbc $(SOURCE)cbc.c src/blockfuncs/blockfuncs.c

ofb: $(SOURCE)ofb.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ofb $(SOURCE)ofb.c src/blockfuncs/blockfuncs.c

rc4: $(SOURCE)Rc4.c
	gcc -g -O0 -I. -o $(SOURCE)Rc4 $(SOURCE)Rc4.c

clean:
	rm $(SOURCE)ecb $(SOURCE)ctr $(SOURCE)cbc $(SOURCE)ofb $(SOURCE)Rc4
