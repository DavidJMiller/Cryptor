//Written by: Joshua Bittel
//Electronic Code Block

//#include <common.h>
#include <stdio.h>

int main(int argc, char **argv){
  char buffer[64];
  FILE* file_open, * out_open;
  file_open = fopen("test","rb");  // r for read, b for binary
  out_open = fopen("out", "wb");
  fseek(file_open, 0L, SEEK_END);
  rewind(file_open);
  unsigned long long file_size = ftell(file_open); //gets size of file
  while(fread(buffer, 1, 64, file_open)){
    //call encryption function here
    size_t count_write = fwrite(buffer, 1, 64, out_open);
    if (count_write != 64){
      perror("Write error\n");
    }
  }
  return 0;
}
