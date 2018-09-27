#include "cripto.h" 

byte 
cipher(byte message, byte key)
{
    return message + key;
}

byte 
decipher(byte cipher, byte key)
{
    return cipher - key;
}
