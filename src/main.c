#include <stdio.h>
#include <stdlib.h>
#include "rot13.h"

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("%s\n", "Give a message to be encrypted");
        return EXIT_FAILURE;
    }
    
    char *msg = argv[1];

    char *decrypt = encrypt_rot13(msg);
    printf("%s\n", decrypt);

    decrypt = decrypt_rot13(decrypt);
    printf("%s\n", decrypt);

    return EXIT_SUCCESS;
}