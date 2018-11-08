//Written by: Joshua Bittel
//Electronic Code Block

#include <common.h>
#include <stdio.h>

//argv: 1 = usageFlag[0-4], inputfile, output, file, --optional [blocksize] [blockfunction]

int main(int argc, char **argv){
  if (argc < 5){
    printf("Usage: ./ecb [blockCipherType] [blockCipherSize] [inputFile] [outputFile]\n");
    exit(EXIT_FAILURE);
  }

  //TODO: do a switch based on blockCipherType

  int blockCipherSize = atoi(argv[2]);
  char * filein = argv[3];
  char * fileout = argv[4];
  
  uint8_t buffer[blockCipherSize];
  FILE* file_open, * out_open;
  file_open = fopen(filein,"rb");  // r for read, b for binary
  out_open = fopen(fileout, "wb");
  fseek(file_open, 0L, SEEK_END);
  rewind(file_open);
  unsigned long long file_size = ftell(file_open); //gets size of file

  //TODO: pad the file with correct block cipher size here
  
  while(fread(buffer, 1, blockCipherSize, file_open)){
    //call usage function here ie: encrypt, decrypt, sign, authenticate
    size_t count_write = fwrite(buffer, 1, blockCipherSize, out_open);
    if (count_write != blockCipherSize){
      perror("Write error\n");
    }
  }
  fclose(file_open);
  fclose(out_open);
  
  return 0;
}
