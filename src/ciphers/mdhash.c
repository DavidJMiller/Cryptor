#include "../common.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int keyLen = 128;

int main(int argc, char **argv)
{
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
        else if(!strcmp(title, "filein"))
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
    if (action == 's')
    {
        snprintf(fileout, sizeof(fileout), "%s.sign", filein);
    } 
    if (action == 'a')
    {
        snprintf(fileout, sizeof(fileout), "%s.auth", filein);
    }
    FILE *file_open, *out_open;
    uint8_t cipher;
    uint8_t S[256];
    file_open = fopen(filein,"r"); 
    out_open = fopen(fileout, "w");
    uint8_t buffer[16];
    uint8_t IV[16] = {0x12, 0xd2, 0xcc, 0x10, 0x00, 0xa8, 0x5b, 0x33,
                      0x04, 0xee, 0xae, 0x9d, 0xfe, 0x22, 0x19, 0xa4};
    memset(buffer, 1, 16 * sizeof(buffer[0]));
    uint8_t check[16];
    memset(buffer, 1, 16 * sizeof(buffer[0]));  
	
    int blocks = 0;
    printf("ACTION: %c\n", action);
    memset(buffer, 0, 16 * sizeof(buffer[0]));  
    if(action == 'a')
    {
         while(fread(check, 1, 16, file_open)){blocks++;}
         fseek(file_open, 0, SEEK_SET);
    }
    int l;
    blocks = blocks - 1;
    uint8_t m = 1;
    int j = 0;
    while(fread(buffer, 1, 16, file_open))
    {
        if((action == 'a') && (blocks <= 0)){break;}
        for(j = 0; j < 16; j++)
        {
            IV[j] = IV[j] ^ (buffer[j] ^ m);
        }
        m << 1;
        blocks = blocks - 1;
        if(action == 's')
        {
            fwrite(buffer, 1, 16, out_open);
            memset(buffer, 1, 16 * sizeof(buffer[0])); 
	}
    }
    fclose(file_open);
    fclose(out_open);
    if(action == 's')
    {
        FILE *sign = fopen(fileout, "a");
        fwrite(IV, 1, 16, sign);
    }
    else
    {
        for(j = 0; j < 16; j++)
        {
            if(check[j] != IV[j])
            {
                printf("Not Authorized!\n");
                return -1;
            }
        }
        printf("Authorized!\n");
        return 0;
    }
}
