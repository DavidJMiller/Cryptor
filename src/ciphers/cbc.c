//Written by: Jordan Mussman
//Just xor by previous cipher text

#include <stdio.h>

int main(int argc, char **argv){
  FILE* ptr;
  ptr = fopen("test","rb");  // r for read, b for binary
  fseek(ptr, 0L, SEEK_END);
  unsigned long long IV = ftell(ptr); //gets size of file
  return 0;
}
