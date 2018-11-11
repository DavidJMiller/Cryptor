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
- Crypto++: apt-get install libcrypto++8 libcrypto++8-dbg libcrypto++-dev
   - Make sure #include <cryptopp/*.h>
   - Remember to compile with -lcryptopp flag
