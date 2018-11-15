//Written by: Joshua Bittel
//Electronic Code Block

#include "../common.h"
#include <stdio.h>

//argv: 1 = usageFlag['e', 'd'], inputfile, output, file, --optional [blocksize] [blockfunction]

int main(int argc, char **argv){
  if (argc < 4){
    printf("Usage: ./ecb [usage] [inputFile] [outputFile] <keysize> <blockfunction>\n");
    exit(EXIT_FAILURE);
  }

  uint8_t key[16] =        { (uint8_t) 0x2b, (uint8_t) 0x7e, (uint8_t) 0x15, (uint8_t) 0x16, (uint8_t) 0x28, (uint8_t) 0xae, (uint8_t) 0xd2, (uint8_t) 0xa6, (uint8_t) 0xab, (uint8_t) 0xf7, (uint8_t) 0x15, (uint8_t) 0x88, (uint8_t) 0x09, (uint8_t) 0xcf, (uint8_t) 0x4f, (uint8_t) 0x3c };
  
  
  //TODO: do a switch based on blockCipherType
  int blockCipherSize;
  if (argc > 4)
    blockCipherSize = atoi(argv[4]);
  char * filein = argv[2];
  char * fileout = argv[3];
  
  uint8_t buffer[16];
  uint8_t ciphered[16];
  FILE* file_open, * out_open;
  file_open = fopen(filein,"rb");  // r for read, b for binary
  out_open = fopen(fileout, "wb");
  fseek(file_open, 0L, SEEK_END);
  rewind(file_open);
  unsigned long long file_size = ftell(file_open); //gets size of file

  //TODO: pad the file with correct block cipher size here
  
  while(fread(buffer, 1, 16, file_open)){
    //call usage function here ie: encrypt, decrypt, sign, authenticate
    AES_encrypt(buffer, key, ciphered, 16);
    size_t count_write = fwrite(ciphered, 1, 16, out_open);
    if (count_write != 16){
      perror("Write error\n");
    }
    
  }
  fclose(file_open);
  fclose(out_open);
  
  return 0;
}
