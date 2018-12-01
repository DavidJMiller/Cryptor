#include "../common.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char key[256] = "Key";
int keyLen = 3;

/* key scheduler algorithm */
void keySchedule(unsigned char *S)
{
    int i, j;
    unsigned char tmp;

    for(i = 0; i < 255; i++)
        S[i] = i;

    j = 0;
    for(i = 0; i < 255; i++)
    {
        j = (j + S[i] + key[i % keyLen]) % 256;
        tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
    }

    return;
}

void PRGA(unsigned char *S, char *p, unsigned char *c)
{
    int i, j;
    unsigned char tmp;

    i = 0;
    j = 0;
    for(i = 0; i < strlen(p); i++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
        c[i] = S[(S[i] + S[j]) % 256];
    }

    return;
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return -1;

    unsigned char *ciphertext = malloc(sizeof(int) * strlen(argv[1]));
    keySchedule(ciphertext);
    printf("%s\n", ciphertext);
}
