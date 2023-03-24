#include <stdio.h>
#include "rot13.h"
/*
ROT13 encryption algorithm

The ROT13 encryption algorithm works by replacing a character
with the 13th letter that comes after it in the alphabet.

a b c d e f g h i j k l m
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^
∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨ ∨
n o p q r s t u v w x y z

*/

char* encrypt_rot13(char *msg) {
    char *out = msg;

    for (int i = 0; msg[i] != '\0'; i++) {
        char c = msg[i];

        // if it is in the range of m <= c < z then wrap around by subtracting
        if (('z' >= c && c > 'm' ) || ('Z' >= c && c > 'M')) {
            c -= 13;
        }
        // if it is in the range of a <= c < m then wrap around by adding
        else if (('m' >= c && c >= 'a' ) || ('M' >= c && c >= 'A')){
            c += 13;
        }
        
        *(out + i) = c;
    }
    return out;
}

char* decrypt_rot13(char *encrypted) {
    return encrypt_rot13(encrypted);
}

void rot13(char *msg) {
    printf("ENCRYPTING WITH ROT13...\n");
    printf("ENCRYPTED msg: %s\n", encrypt_rot13(msg));
    printf("DECRYPTED: %s\n", decrypt_rot13(msg));
    printf("\n");
}