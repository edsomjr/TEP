#ifndef CRIPTO_H
#define CRIPTO_H

typedef char byte;

extern byte cipher(byte message, byte key);
extern byte decipher(byte cipher, byte key);

#endif
