//Written by: Jordan Mussman
//Just xor by previous cipher text

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  FILE* ptr;
  
  ptr = fopen("test","rb");  // r for read, b for binary
  fseek(ptr, 0L, SEEK_END);
  unsigned long long filesize = ftell(ptr); //gets size of file
  char *IV = (char*) malloc(sizeof(char) * (filesize + 1));
  sprintf(IV,"%0*d\n", (int)filesize, 0);
  printf("IV[%llu] is: %s\n",filesize,IV);

  fclose(ptr);
  return 0;
}
