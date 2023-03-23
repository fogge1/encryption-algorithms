#include <stdio.h>
#include <math.h>

int FIND_BASE(char c) {
    if (c >='A' && c<='Z') return 'A';
    return 'a';
}

void encrypt_caesar(char *msg, int r) {
    for (int i = 0; msg[i] != '\0'; i++) {
        char b = FIND_BASE(msg[i]);
        msg[i] = (msg[i]-b+r)%26+b;
    }
    printf("%s\n", msg);
}

// The function caesar takes 2 arguments msg and r (r places to shift)
void caesar(char *msg, int r) {
    encrypt_caesar(msg, r);
}