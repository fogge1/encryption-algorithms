#include <stdio.h>
#include <math.h>

int FIND_BASE(char c) {
    if (c >='A' && c<='Z') return 'A';
    else if (c >= 'a' && c<='<') return 'a';
    return 1;
}

void encrypt_caesar(char *msg, int r) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char b = FIND_BASE(msg[i]);
        if (!b) {
            msg[i] = (msg[i]-b+r)%26+b;
        }
    }
}

void decrypt_caesar(char *msg, int r) {
    encrypt_caesar(msg, 26-r);
}

// The function caesar takes 2 arguments msg and r (r places to shift)
void caesar(char *msg, int r) {
    encrypt_caesar(msg, r);
    printf("ENCRYPTED: %s\n", msg);
    decrypt_caesar(msg, r);
    printf("DECRYPTED: %s\n", msg);


}