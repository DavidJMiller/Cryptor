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
    if (action == 'e')
    {
        snprintf(fileout, sizeof(fileout), "%s.encrypt", filein);
    } 
    if (action == 'd')
    {
        snprintf(fileout, sizeof(fileout), "%s.decrypt", filein);
    }
    FILE *file_open, *out_open;
    file_open = fopen(filein,"r"); 
    out_open = fopen(fileout, "w");
    char r, c;
    int shift, n, max;
        
    n = -1;
    while((c = fgetc(file_open)) != EOF)
    {
        if(((c <= 90) && (c >= 65)) || ((c <= 122) && (c >= 97)))
        {
            if(action == 'e')
            {
                max = strlen(filein);
                n = ++n % max;
                keyLen = filein[n];
                (filein[n] <= 90) ? (keyLen = keyLen - 65):(keyLen = keyLen - 97);
            }
            else
            {
                char *name = strtok(filein, ".");
                max = strlen(name);
                n = ++n % max;
                keyLen = name[n];
                (name[n] <= 90) ? (keyLen = keyLen - 65):(keyLen = keyLen - 97);
            }
            action == 'e' ? (shift = keyLen):(shift = -1 * keyLen);
            if((c <= 90) && (c >= 65))
            {
                while((shift + c) > 90){shift = shift - 26;}
                if(shift + c < 65){shift = shift + 26;}
                r = shift + c;
                fwrite(&r, 1, 1, out_open);
            }
            else
            {
                while((shift + c) > 122){shift = shift - 26;}
                if((shift + c) < 97){shift = shift + 26;}
                r = shift + c;
                fwrite(&r, 1, 1, out_open);
            }
        }
        else
        {
            r = c;
            fwrite(&r, 1, 1, out_open);    
        }
    }

    fclose(file_open);
    fclose(out_open);

    return 0;
}
