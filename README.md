# Cryptor

README --> this file
/src
   common.h
      -global standardization
   /blockfuncs
      aes.c
        -just import library
      des.c
        -just import library
   /frontEnd
      -python implementation for "gui"
   /ciphers
      -methods for encrypting, decrypting, signing, and authenticating

RESTRICTIONS:
-Block size n must satsify n = 2^i for some i = 5, 6, ..., 9

Dependances:
- Crypto++: apt-get install libcrypto++8 libcrypto++8-dbg libcrypto++-dev OR brew install cryptopp
   - Make sure #include <cryptopp/*.h>
   - Remember to compile with -lcryptopp flag

AES Documentation:
 - AES is a variant of Rijndael which has a fixed block size of 128 bits, and a key size of 128, 192, or 256 bits. By contrast, Rijndael per se is specified with block and key sizes that may be any multiple of 32 bitswith a minimum of 128 and a maximum of 256 bits.