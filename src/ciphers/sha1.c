#include "../common.h"
#include <openssl/sha.h>

void SHA1(char *plaintext)
{
    SHA_CTX state;
    SHA1_Init(&state);
    SHA1_Update(&state, plaintext, strlen(plaintext));
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1_Final(hash, &state);
    printf("SHA1 Hash: %s\n", hash);

    return;
}

int main(int argc, char *argv[])
{
    SHA1("hello");

    return 0;
}
