#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rot13.h"
#include "rsa.h"
#include "caesar.h"
#include "vignere.h"

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("%s\n", "Give a message to be encrypted");
        return EXIT_FAILURE;
    }
    
    char *msg = argv[1];

    /*rot13(msg);
    caesar(msg, 3);
    rsa(msg); */
    vignere(msg);
    
    return EXIT_SUCCESS;
}