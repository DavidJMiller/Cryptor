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
 - Block size n must satsify n = 2^i for some i = 5, 6, ..., 9
 - Block size must be appropriate 

Dependances:
 - None

AES Documentation:
 - AES is a variant of Rijndael which has a fixed block size of 128 bits, and a key size of 128, 192, or 256 bits. By contrast, Rijndael per se is specified with block and key sizes that may be any multiple of 32 bitswith a minimum of 128 and a maximum of 256 bits. (Credit to tiny-aes)

How to does it work:
 Front End:
  - Welcome schpel
  - Query user for:
	- file to encrypt
	- mode of encryption
	- block
	- key length (give recommended sizes)
 	- Action: encrypt, decrpyt, sign, auth
  - Front end will call ./(mode of encryption) config_file

Config_file:
 action 	{action}
 blockfunc 	{block_function}
 keylen 	{key_length}
 filename	{file_name}
