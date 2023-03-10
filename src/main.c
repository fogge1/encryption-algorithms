#include <stdio.h>
#include <stdlib.h>
#include "rot13.h"

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("%s\n", "Give a message to be encrypted");
        return EXIT_FAILURE;
    }
    // First argument equals message to be encrypted
    char *msg = argv[1];

    rot(msg);

    return EXIT_SUCCESS;
}