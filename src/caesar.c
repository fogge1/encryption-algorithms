#include <stdio.h>
#include <math.h>

// find if c is lowercase, uppercase or just dont do anything with it
int FIND_BASE(char c) {
    if (c >='A' && c<='Z') return 'A';
    else if (c >= 'a' && c<='z') return 'a';
    return 1;
}

//  takes 2 arguments msg and r (r places to shift)
void encrypt_caesar(char *msg, int r) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char b = FIND_BASE(msg[i]);
        // dont do anything with the letter if it isn't lower case
        if (b != 1) {
            // you take away the base b, which is a for lowercase and A for uppercase
            // this is to get msg[i] + r in the interval of 0-25
            // then you add b again to get the ascii value
            msg[i] = (msg[i]-b+r)%26+b;
        }
    }
}


void decrypt_caesar(char *msg, int r) {
    // 26-r instead of just -r to avoid using negatives in the implementation of 
    encrypt_caesar(msg, 26-r);
}

void caesar(char *msg, int r) {
    printf("ENCRYPTING WITH CAESAR WITH SHIFT=%d\n", r);
    encrypt_caesar(msg, r);
    printf("ENCRYPTED: %s\n", msg);
    decrypt_caesar(msg, r);
    printf("DECRYPTED: %s\n", msg);
    printf("\n");
}