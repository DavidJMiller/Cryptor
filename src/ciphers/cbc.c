//Written by: Jordan Mussman
//Just xor by previous cipher text

//argv: 1 = usageFlag['e', 'd'], inputfile, output, file, --optional [blockfunction]

#include "../common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
  FILE *file_in, *file_out;
 //open 
  file_in = fopen(argv[2],"r");  // r for read, b for binary
  file_out = fopen(argv[3],"w");
  //pad - 1(0)*
  fseek(file_in, 0L, SEEK_END);
  unsigned long long filesize = ftell(file_in); //gets size of file
  
  //To Do: add padding

  uint8_t IV[16] = { (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t)     0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00, (uint8_t) 0x00 };
  uint8_t key[16] = { (uint8_t) 0x2b, (uint8_t) 0x7e, (uint8_t) 0x15, (uint8_t) 0x16, (uint8_t) 0x28, (uint8_t) 0xae, (uint8_t) 0xd2, (uint8_t) 0xa6, (uint8_t) 0xab, (uint8_t) 0xf7, (uint8_t) 0x15, (uint8_t) 0x88, (uint8_t) 0x09, (uint8_t) 0xcf, (uint8_t) 0x4f, (uint8_t) 0x3c };
  uint8_t *ctxt[16];
  memcpy(ctxt, &IV,sizeof(ctxt));
  uint8_t buf[16];
  if(strcmp(argv[1], "e")==0){
  //encryption
      while(fread(buf,1,16,file_in)){
        ctxt ^= buf; 
        //make if/else_if for aes or des
	AES_encrypt(buf, key, ctxt, 16);

        if(fwrite(ctxt, 1, 16, file_out) != 16)
          perror("Write error\n");
      } 
  }else if(strcmp(argv[1],"d")==0){
  //decryption
      while(fread(buf,1,16,file_in)){
        ctxt ^= buf;
        //make if/else_if for aes or des
	AES_encrypt(buf, key, ctxt, 16);
     
        if(fwrite(ctxt, 1, 16, file_out) != 16)
          perror("Write error\n");
      }
  }
  fclose(file_out);
  fclose(file_in);
  return 0;
}
