CC = gcc
CFLAGS = -std=c11 -Wall -g -O0

SOURCE = src/ciphers/

all: ecb cbc ofb ctr rc4 cfb

ecb: $(SOURCE)ecb.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ecb $(SOURCE)ecb.c src/blockfuncs/blockfuncs.c

ctr: $(SOURCE)ctr.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ctr $(SOURCE)ctr.c src/blockfuncs/blockfuncs.c

cbc: $(SOURCE)cbc.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)cbc $(SOURCE)cbc.c src/blockfuncs/blockfuncs.c

ofb: $(SOURCE)ofb.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)ofb $(SOURCE)ofb.c src/blockfuncs/blockfuncs.c

rc4: $(SOURCE)RC4.c
	gcc -g -O0 -I. -o $(SOURCE)RC4 $(SOURCE)RC4.c

cfb: $(SOURCE)cfb.c src/blockfuncs/blockfuncs.c
	gcc -g -O0 -Isrc/blockfuncs -I. -o $(SOURCE)cfb $(SOURCE)cfb.c src/blockfuncs/blockfuncs.c

clean:
	rm $(SOURCE)ecb $(SOURCE)ctr $(SOURCE)cbc $(SOURCE)ofb $(SOURCE)Rc4 $(SOURCE)cfb
