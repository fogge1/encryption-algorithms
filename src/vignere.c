#include <stdio.h>
#include <string.h>
#include "caesar.h"

void encrypt_vigenere(char *msg, char *key) {
    int key_len = strlen(key);
    for (int i = 0, j = 0; msg[i] != '\0'; i++) {
        char b = FIND_BASE(msg[i]);
        if (b != 1) {
            int r = key[j % key_len] - FIND_BASE(key[j % key_len]);
            msg[i] = (msg[i] - b + r) % 26 + b;
            j++;
        }
    }
}

void decrypt_vigenere(char *msg, char *key) {
    int key_len = strlen(key);
    for (int i = 0, j = 0; msg[i] != '\0'; i++) {
        char b = FIND_BASE(msg[i]);
        if (b != 1) {
            int r = key[j % key_len] - FIND_BASE(key[j % key_len]);
            msg[i] = (msg[i] - b - r + 26) % 26 + b;
            j++;
        }
    }
}

void vignere(char *msg) {
    char *key = "MATH";
    printf("ENCRYPTING WITH VIGNERE, KEY=%s\n", key);
    encrypt_vigenere(msg, key);
    printf("ENCRYPTED: %s\n", msg);

    decrypt_vigenere(msg, key);
    printf("DECRYPTED: %s\n", msg);
}