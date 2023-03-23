#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rot13.h"
#include "rsa.h"

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("%s\n", "Give a message to be encrypted");
        return EXIT_FAILURE;
    }
    
    char *msg = argv[1];

    /*
    char *decrypt = encrypt_rot13(msg);
    printf("%s\n", decrypt);

    decrypt = decrypt_rot13(decrypt);
    printf("%s\n", decrypt); 
    */

    int p = 61;
    int q = 53;
    
    long n = p*q;
    long tn = (p-1)*(q-1); // totient of n
    long e = 17;//choose_e(tn);
    long d = modular_inverse(e, tn);
    
    printf("Public key: (%li, %li)\n", e, n);
    printf("Private key: (%li, %li)\n", d, n);
    
    int encrypted[strlen(msg)+1];
    encrypt_rsa(msg, e, n, encrypted);
    decrypt_rsa(encrypted, d, n);
    //printf("Decrypted message:\n%s\n", decrypt_rsa(encrypted, d, n));

    return EXIT_SUCCESS;
}