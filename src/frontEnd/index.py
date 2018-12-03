import os
import sys

def main(): #this is interactive mode
    print("\n\t\t:'######:'########:'##:::'##'########:'########:'#######:'########::")
    print("\t\t##... ##:##.... ##. ##:'##::##.... ##... ##..:'##.... ##:##.... ##:")
    print("\t\t##:::..::##:::: ##:. ####:::##:::: ##::: ##::::##:::: ##:##:::: ##:")
    print("\t\t##:::::::########:::. ##::::########:::: ##::::##:::: ##:########::")
    print("\t\t##:::::::##.. ##::::: ##::::##.....::::: ##::::##:::: ##:##.. ##:::")
    print("\t\t##::: ##:##::. ##:::: ##::::##:::::::::: ##::::##:::: ##:##::. ##::")
    print("\t\t.######::##:::. ##::: ##::::##:::::::::: ##:::. #######::##:::. ##:")
    print("\t\t:......::..:::::..::::..::::..:::::::::::..:::::.......::..:::::..::")
    flg = 0

    while flg == 0:
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
        print("Output Feedback, ofb, is very much like cfb. The only difference is instead of the ciphertext from a previous round being passed to the next, it is the output from the encryption cipher. This technique allows for error correcting codes to be included in the data without being lost during the encryption, specifically the XOR operation.\n")
        print("Counter, ctr, mode is unique in that it turns a block cipher into a stream cipher. The algorithm generates a keystream block by encrypting incrimental values from the IV. That value is is encrypted in a block cipher and then XOR'd with the plantext. As stated, a following round would then simply impliment the counter and input that new value into the block cipher to repeat on the next block of plaintext data to be encrypted.\n")
        print("Merkle-Damgard is a type of collision-resistant cryptographic hash construction that uses a one-way compression function that inputs the prevoius round's hash along with the current round's plaintext. At the end of the hahsing- to pad, this method uses a special padding block.\n")#Merkle Damgard Hash
        print("For Merkle-Damgard, just type 'hash'")
        print("RC4 (rc4) stream cipher simply generates a pseudo-random key stream which then endures various byte manipulations to yeild a ciphertextself.\n")
        print("Vignere (vig) cipher copies a keyword however many times over in order to encrypt each character of a plaintext by a letter within that word.\n")#vignere
        print("Caesar (caes) cipher is a simple alphabetical shift cipher that depending on the key will shift each letter a certain number of letters alphabetically to create the ciphertext.\n")
        print("Now, what mode would you like to use? Please enter the abbreviation here.")
        mode_of_encryption = raw_input("")
        print("Next we will pick our encrypting block function.")
        print("------------------------------------------------------------------------------\n")
        print("Onto the block functions!");
        print("Within each mode of encryption there is still the block function to chose.\n")
        print("We have made it possible for you to encrypt your files with the AES, RC4, and DES ciphers.\n")
        print("AES is a block cipher which generates a certain key size determines the amount of rounds a cipher will run for.\n")
        print("Which block function would you like to use: AES, RC4, or DES?\n")
        print("  **If you want to use our Merkle-Damgard hash, enter 'hash' here.\n")
        block_func = raw_input("")
       # block_func = "AES" #since this is the only one we currently have implimented
        print("Next we will pick our encrypting block function's key size.")
        print("------------------------------------------------------------------------------\n")
        print("As with most block functions, we need a key length.")
        print("So, the greater the key length, the more secure an encryption scheme is.")
        print("Note, by more secure, we mean that it is more computationally intensive, or infeasible, to bruteforce the keys of an algorithm within a reasonable amount of time")
        print("The recommended key sizes for:")
        print("\tAES - 128 or 192 or 256")
        print("  **If you want to use our Merkle-Damgard hash, enter 'hash' here.\n")
        key_size = raw_input("")
        print("Next we will pick our action.")
        print("------------------------------------------------------------------------------\n")
        print("Last, we just need to decide the action to take: Encrypt, Decrypt, Sign, or Authenticate (Auth)?")
        print("To encrypt or decrypt your data is a trivial operation.")
        print("To hash your file would be to use one of our two hash functions we have implimented: MD5 or SHA1.")
        print("To sign is to hash a copy of the last encrypted block of data to send concatenated to the end of your data to verify the message's integrity.")
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
        if (good == "YES") or (good == "yes") or (good == "y") or (good == "Y"):
            print("\nPlease wait while we operate on your file...\n\n")
            flg = 1

            #Reformat action to expected parse
            if action == "encrypt":
                action = "e"
            elif action == "decrypt":
                action = "d"
            elif action == "auth":
                action = "a"
            elif action == "sign":
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
            if action == "a":
                cmd = '../ciphers/mdh ../ciphers/config_file'
            elif action == "s":
                cmd = '../ciphers/mdh ../ciphers/config_file'
            elif mode_of_encryption.lower() == "ecb":
                cmd = '../ciphers/ecb ../ciphers/config_file'
            elif mode_of_encryption.lower() == "cbc":
                cmd = '../ciphers/cbc ../ciphers/config_file'
            elif mode_of_encryption.lower() == "ofb":
                cmd = '../ciphers/ofb ../ciphers/config_file'
            elif mode_of_encryption.lower() == "cfb":
                cmd = '../ciphers/cfb ../ciphers/config_file'
            elif mode_of_encryption.lower() == "ctr":
                cmd = '../ciphers/ctr ../ciphers/config_file'
            elif mode_of_encryption.lower() == "rc4":
                cmd = '../ciphers/RC4 ../ciphers/config_file'
            elif mode_of_encryption.lower() == "vigenere":
                cmd = '../ciphers/vigenere ../ciphers/config_file'
            else:
                print("The mode entered is not a valid mode of encryption")

            print("Executing " + mode_of_encryption + " now!")

            #Actual execution - local
            os.system(cmd)

        else:
            print("\nOkay, let's try this again\n")

def functional(): #this is TUI mode which is for cloud!
    print("\n\t\t:'######:'########:'##:::'##'########:'########:'#######:'########::")
    print("\t\t##... ##:##.... ##. ##:'##::##.... ##... ##..:'##.... ##:##.... ##:")
    print("\t\t##:::..::##:::: ##:. ####:::##:::: ##::: ##::::##:::: ##:##:::: ##:")
    print("\t\t##:::::::########:::. ##::::########:::: ##::::##:::: ##:########::")
    print("\t\t##:::::::##.. ##::::: ##::::##.....::::: ##::::##:::: ##:##.. ##:::")
    print("\t\t##::: ##:##::. ##:::: ##::::##:::::::::: ##::::##:::: ##:##::. ##::")
    print("\t\t.######::##:::. ##::: ##::::##:::::::::: ##:::. #######::##:::. ##:")
    print("\t\t:......::..:::::..::::..::::..:::::::::::..:::::.......::..:::::..::")
    flg = 0

    while flg == 0:
        print("\n\t\t\t\tWelcome to Cryptor functional!")

        file_name = raw_input("File name: ")
        mode_of_encryption = raw_input("Mode of Encryption: ")
        raw_input("AES?: ") #this does nothing since AES is hardcoded
        block_func = "AES"
        key_size = raw_input("Key size? Recommended AES - 128 or 192 or 256: ")
        action = raw_input("Action? Encrypt, Decrypt, Sign, or Auth: ")

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
            if action.lower() == "encrypt":
                action = "e"
            elif action.lower() == "decrypt":
                action = "d"
            elif action.lower() == "auth":
                action = "a"
            elif action.lower() == "sign":
                action = "s"

            #Write config file in certain format for parsing
            f = open("config_file", "w+")
            f.write("action " + action + "\n")
            f.write("blockfunc " + block_func + "\n")
            f.write("keylen " + key_size + "\n")
            f.write("filein " + file_name + "\n")
            f.close()

            print("Executing " + mode_of_encryption + " now!")

            #Actual execution - cloud
            os.system("nc 192.168.1.101 6655 < config_file && nc -lp 6655 -w 4 > file.decrypt && cat file.decrypt")

        else:
            print("\nOkay, let's try this again\n")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        functional()
    else:
        main()
