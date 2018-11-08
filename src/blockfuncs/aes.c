#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    FILE *f_input, *f_enc, *f_dec;

    /* Make sure user provides the input file */
    if (argc != 2) {
        printf("Usage: %s /path/to/file\n", argv[0]);
        return -1;
    }

    cipher_params_t *params = (cipher_params_t *)malloc(sizeof(cipher_params_t));
    if (!params) {
        /* Unable to allocate memory on heap*/
        fprintf(stderr, "ERROR: malloc error: %s\n", strerror(errno));
        return errno;
    }

    /* Key to use for encrpytion and decryption */
    unsigned char key[AES_256_KEY_SIZE];

    /* Initialization Vector */
    unsigned char iv[AES_BLOCK_SIZE];

    /* Generate cryptographically strong pseudo-random bytes for key and IV */
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        /* OpenSSL reports a failure, act accordingly */
        fprintf(stderr, "ERROR: RAND_bytes error: %s\n", strerror(errno));
        return errno;
    }
    params->key = key;
    params->iv = iv;

    /* Indicate that we want to encrypt */
    params->encrypt = 1;

    /* Set the cipher type you want for encryption-decryption */
    params->cipher_type = EVP_aes_256_cbc();

    /* Open the input file for reading in binary ("rb" mode) */
    f_input = fopen(argv[1], "rb");
    if (!f_input) {
        /* Unable to open file for reading */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return errno;
    }

    /* Open and truncate file to zero length or create ciphertext file for writing */
    f_enc = fopen("encrypted_file", "wb");
    if (!f_enc) {
        /* Unable to open file for writing */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return errno;
    }

    /* Encrypt the given file */
    file_encrypt_decrypt(params, f_input, f_enc);

    /* Encryption done, close the file descriptors */
    fclose(f_input);
    fclose(f_enc);

    /* Decrypt the file */
    /* Indicate that we want to decrypt */
    params->encrypt = 0;

    /* Open the encrypted file for reading in binary ("rb" mode) */
    f_input = fopen("encrypted_file", "rb");
    if (!f_input) {
        /* Unable to open file for reading */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return errno;
    }

    /* Open and truncate file to zero length or create decrypted file for writing */
    f_dec = fopen("decrypted_file", "wb");
    if (!f_dec) {
        /* Unable to open file for writing */
        fprintf(stderr, "ERROR: fopen error: %s\n", strerror(errno));
        return errno;
    }

    /* Decrypt the given file */
    file_encrypt_decrypt(params, f_input, f_dec);

    /* Close the open file descriptors */
    fclose(f_input);
    fclose(f_dec);

    /* Free the memory allocated to our structure */
    free(params);

    return 0;
}
