#include "../common.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b,  
                     0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81, 0x11, 0x1f,  
                     0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98,  
                     0x10, 0xa3, 0x09, 0x14, 0xdf};
int keyLen = 256;

/* key scheduler algorithm */
void keySchedule(uint8_t S[256])
{
    uint8_t i, j;
    uint8_t tmp;

    for(i = 0; i < 256; i++)
        S[i] = i;

    j = 0;
    for(i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % keyLen]) % 256;
        tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
    }

    return;
}

void PRGA(uint8_t S[256], FILE *srcFile, FILE *destFile)
{
    uint8_t i, j;
    uint8_t tmp, *c, *buffer;

    i = 0;
    j = 0;
    while(fread(buffer, 1, 1, srcFile))                                       
    {                                                                           
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
        *c = S[(S[i] + S[j]) % 256];
        fwrite(c, 1, 1, destFile);
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Incorrect usage\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    char title[255];
    char value[255];
    char action;
    char filein[255];
    char blockfunc[255];
    int func_index;

    fp = fopen(argv[1], "r");
    while(fscanf(fp, "%s %s", title, value) != EOF)
    {
        if(!strcmp(title, "action"))
        {
            action = value[0];
        }
        else if(!strcmp(title, "blockfunc"))
        {
            strcpy(blockfunc, value);
        }
        else if(!strcmp(title, "keylen"))
        {
            keyLen = atoi(value);
        }
        else if(!strcmp(title, "keylen"))
        {
            strcpy(filein, value);
        }
    }

    if(!strcmp(blockfunc, "aes"))
    {
        func_index = 0;
    }
    else if(!strcmp(blockfunc, "test1"))
    {
        func_index = 0;
    }
    else if(!strcmp(blockfunc, "test2"))
    {
        func_index = 0;
    }

    char fileout[255];
    if (action == 'e')
    {
        snprintf(fileout, sizeof(fileout), "%s.encrypt", filein);
    } 
    if (action == 'd')
    {
        snprintf(fileout, sizeof(fileout), "%s.decrypt", filein);
    }
    FILE *file_open, *out_open;
    uint8_t cipher;
    uint8_t S[256];
    file_open = fopen(filein,"r"); 
    out_open = fopen(fileout, "w");

    keySchedule(S);
    PRGA(S, file_open, out_open);

    fclose(file_open);
    fclose(out_open);
}
