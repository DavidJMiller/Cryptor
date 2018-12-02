all: ecb ctr cbc ofb

ecb: ecb.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o ecb ecb.c ../blockfuncs/blockfuncs.c

ctr: ctr.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o ctr ctr.c ../blockfuncs/blockfuncs.c

cbc: cbc.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o cbc cbc.c ../blockfuncs/blockfuncs.c

ofb: ofb.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o ofb ofb.c ../blockfuncs/blockfuncs.c
