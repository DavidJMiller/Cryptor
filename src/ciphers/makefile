all: ecb ctr cbc

ecb: ecb.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o ecb ecb.c ../blockfuncs/blockfuncs.c

ctr: ctr.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o ctr ctr.c ../blockfuncs/blockfuncs.c

cbc: cbc.c ../blockfuncs/blockfuncs.c
	gcc -g -O0 -I../blockfuncs -I. -o cbc cbc.c ../blockfuncs/blockfuncs.c
