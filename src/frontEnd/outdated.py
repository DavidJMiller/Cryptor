import os
import sys

def main():
    print("\t\t:'######:'########:'##:::'##'########:'########:'#######:'########::")
    print("\t\t##... ##:##.... ##. ##:'##::##.... ##... ##..:'##.... ##:##.... ##:")
    print("\t\t##:::..::##:::: ##:. ####:::##:::: ##::: ##::::##:::: ##:##:::: ##:")
    print("\t\t##:::::::########:::. ##::::########:::: ##::::##:::: ##:########::")
    print("\t\t##:::::::##.. ##::::: ##::::##.....::::: ##::::##:::: ##:##.. ##:::")
    print("\t\t##::: ##:##::. ##:::: ##::::##:::::::::: ##::::##:::: ##:##::. ##::")
    print("\t\t.######::##:::. ##::: ##::::##:::::::::: ##:::. #######::##:::. ##:")
    print("\t\t:......::..:::::..::::..::::..:::::::::::..:::::.......::..:::::..::")
    flg = 0

    while(flg == 0):
        print("\n\t\t\t\t\tWelcome to Cryptor!")
        print("\nThe fun and educational tool that walks you through the basic modes of encryption with your own perrsonal files.")
        print("\nBut don't fret,\n\tnot only will we show you how to encrypt those files\nbut we will decrypt them too!\n")
        print("Let's begin! Choose a file you would like to encrypt. It may be a text file or photo or any file imaginable!")
        file_name = raw_input("")
        print("Next we will choose our mode of encryption.")
        print("------------------------------------------------------------------------------\n")
        print("A mode of encryption is a group of encryption algorithms dedicated to provide confidentiality or authenticity to blocks of data with a predetermined block cipher (E.g. AES)\n")
        print("Cipher Block Chaining, cbc, works by first XOR'ing an initalization vector (IV), a random string a bits, to a block of a message. That result is then passed into the block cipher to be encrypted with a key. That is one round of encryption on one block of data. The second round would begin by XOR'ing the previous round's ciphertext with the current round's plaintext and then passing that through the block cipher. This would repeat until the entire message was operated upon.\n")
        print("Electronic Code Book, ecb, is a very simple algorithm that inputs a block of plaintext into a block cipher along with a key and the output for that round is that ciphertext. Note, each rounds encryption has nothing to do with previous one.\n")
        print("Cipher Feedback, cfb, is a little more complicated. First, the IV will be encrypted by a block cipher with a key and that result will be XOR'd with a block of plaintext to get the ciphertext. The next round will begin by encrypting the previous round's ciphertext in the block cipher to repeat the process.\n")
        print("Output Feedback, ofb, is very much like cfb. The only difference is instead of the cipbertext from a previous round being passed to the next, it is the output from the encryption cipher. This technique allows for error correcting codes to be included in the data without being lost during the encryption, specifically the XOR operation.\n")
        print("Counter, ctr, mode is unique in that it turns a block cipher into a stream cipher. The algorithm generates a keystream block by encrypting incrimental values from the IV. That value is is encrypted in a block cipher and then XOR'd with the plantext. As stated, a following round would then simply impliment the counter and input that new value into the block cipher to repeat on the next block of plaintext data to be encrypted.\n")
        #Merkle Damgard Hash
        #RC4
        #Vinerge
        #Caesar
        print("Now, what mode would you like to use? Please enter the abbreviation here.")
        mode_of_encryption = raw_input("")
        print("------------------------------------------------------------------------------\n")
        print("Onto the block functions");
        print("Within each mode of encryption there is still the block function to chose")
        print("We have made it possible for you to encrypt your files with the AES, RC4, and DES ciphers")
        print("AES is a block cipher which generates a certain key size determines the amount of rounds a cipher will run for")
        print("Which block function would you like to use: AES, RC4, or DES?")
        block_func = raw_input("")
        print("------------------------------------------------------------------------------\n")
        print("As with most block functions, we need a key length.")
        print("So, the greater the key length, the more secure an encryption scheme is.")
        print("Note, by more secure, we mean that it is more computationally intensive, or infeasible, to bruteforce the keys of an algorithm within a reasonable amount of time")
        print("The recommended key sizes for:")
        print("\tAES - 128 or 192 or 256")
        key_size = raw_input("")
        print("------------------------------------------------------------------------------\n")
        print("Last, we just need to decide the action to take: Encrypt, Decrypt, Sign, or Authenticate(Auth)?")
        print("To encrypt or decrypt your data is a trivial operation")
        print("To hash your file would be to use one of our two hash functions we have implimented: MD5 or SHA1")
        print("To sign is to hash a copy of the last encrypted block of data to send concatenated to the end of your data to verify the message's integrity")
        print("What will you choose to do?")
        action = raw_input("")
        print("------------------------------------------------------------------------------\n")

        print("\nJust to be sure, you've chosen:")
        print("\tFile: " + file_name)
        print("\tMode of encryption: " + mode_of_encryption)
        print("\tBlock function: " + block_func)
        print("\tKey Length: " + key_size)
        print("\tAction: " + action)

        good = raw_input("Is this all correct? ")
        if(good == "YES") or (good == "yes") or (good == "y") or (good == "Y"):
            print("\nPlease wait while we operate on your file\n\n")
            flg = 1

            #Reformat action to expected parse
            if(action == "encrypt"):
                action = "e"
            elif(action == "decrypt"):
                action = "d"
            elif(action == "auth"):
                action = "a"
            elif(action == "sign"):
                action = "s"

            #Write config file in certain format for parsing
            f = open("../ciphers/config_file", "w+")
            f.write("action " + action + "\n")
            f.write("blockfunc " + block_func + "\n")
            f.write("keylen " + key_size + "\n")
            f.write("filein " + file_name + "\n")
            f.close()

            #Call certain executable based on elif(mode_of_encryption)
            cmd = ""
            if(action == "a"):
                cmd = '../ciphers/mdh ../ciphers/config_file'
            elif(action == "s"):
                cmd = '../ciphers/mdh ../ciphers/config_file'
            elif(mode_of_encryption.lower() == "ecb"):
                cmd = '../ciphers/ecb config_file'
            elif(mode_of_encryption.lower() == "cbc"):
                cmd = '../ciphers/cbc config_file'
            elif(mode_of_encryption.lower() == "ofb"):
                cmd = '../ciphers/ofb config_file'
            elif(mode_of_encryption.lower() == "cfb"):
                cmd = '../ciphers/cfb config_file'
            elif(mode_of_encryption.lower() == "ctr"):
                cmd = '../ciphers/ctr config_file'
            #vignere
            #rc4
            #caesar
            else:
                print("The mode entered is not a valid mode of encryption")

            print("Executing " + mode_of_encryption + " now!")

            #Actual execution
            os.system(cmd)

            #os.system("nc 192.168.43.83 6655 < config_file && nc -l -w 7 6655 && cat file.decrypt")

        else:
            print("\nOkay, let's try this again\n")
            flg = 0

def other():
    print("\t\t:'######:'########:'##:::'##'########:'########:'#######:'########::")
    print("\t\t##... ##:##.... ##. ##:'##::##.... ##... ##..:'##.... ##:##.... ##:")
    print("\t\t##:::..::##:::: ##:. ####:::##:::: ##::: ##::::##:::: ##:##:::: ##:")
    print("\t\t##:::::::########:::. ##::::########:::: ##::::##:::: ##:########::")
    print("\t\t##:::::::##.. ##::::: ##::::##.....::::: ##::::##:::: ##:##.. ##:::")
    print("\t\t##::: ##:##::. ##:::: ##::::##:::::::::: ##::::##:::: ##:##::. ##::")
    print("\t\t.######::##:::. ##::: ##::::##:::::::::: ##:::. #######::##:::. ##:")
    print("\t\t:......::..:::::..::::..::::..:::::::::::..:::::.......::..:::::..::")
    flg = 0

    while(flg == 0):
        print("\n\t\t\t\tWelcome to Cryptor functional!")

        file_name = raw_input("File name: ")
        mode_of_encryption = raw_input("Mode of Encryption: ")
        print("AES?: ")
        raw_input("") #this does nothing since AES is hardcoded
        block_func = "AES"
        key_size = raw_input("Key size? Recommended AES - 128 or 192 or 256: ")
        action = raw_input("Action? Encrypt, Decrypt, Sign, or Hash: ")

        print("\nJust to be sure, you've chosen:")
        print("\tFile: " + file_name)
        print("\tMode of encryption: " + mode_of_encryption)
        print("\tBlock function: " + block_func)
        print("\tKey Length: " + key_size)
        print("\tAction: " + action)

        good = raw_input("Is this all correct? ")
        if(good == "YES") or (good == "yes") or (good == "y") or (good == "Y"):
            print("\nPlease wait while we operate on your file\n\n")
            flg = 1

            #Reformat action to expected parse
            if(action == "encrypt"):
                action = "e"
            elif(action == "decrypt"):
                action = "d"
            elif(action == "hash"):
                action = "h"
            elif(action == "sign"):
                action = "s"

            #Write config file in certain format for parsing
            f = open("config_file", "w+")
            f.write("action " + action + "\n")
            f.write("blockfunc " + block_func + "\n")
            f.write("keylen " + key_size + "\n")
            f.write("filein " + file_name + "\n")
            f.close()

            #Call certain executable based on elif(mode_of_encryption)
            cmd = ""
            if(action == "h"):
                cmd = '../ciphers/hash config_file'
            elif(action == "s"):
                cmd = '../ciphers/sign config_file'
            elif(mode_of_encryption.lower() == "ecb"):
                cmd = '../ciphers/ecb config_file'
            elif(mode_of_encryption.lower() == "cbc"):
                cmd = '../ciphers/cbc config_file'
            elif(mode_of_encryption.lower() == "ofb"):
                cmd = '../ciphers/ofb config_file'
            elif(mode_of_encryption.lower() == "cfb"):
                cmd = '../ciphers/cfb config_file'
            elif(mode_of_encryption.lower() == "ctr"):
                cmd = '../ciphers/ctr config_file'
            else:
                print("The mode entered is not a valid mode of encryption")

            print("Executing " + mode_of_encryption + " now!")

            #Actual execution
        #            os.system(cmd)

            os.system("nc 192.168.1.100 6655 < config_file && nc -lp 6655 -w 4 > testfile.decrypt && cat testfile.decrypt")

        else:
            print("\nOkay, let's try this again\n")
            flg = 0



if __name__ == "__main__":
    if(len(sys.argv) > 1):
        other()
    else:
        main()
