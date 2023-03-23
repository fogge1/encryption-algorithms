#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
    C Implementation of the RSA algorithm
*/

/* 
The Euclidean algorithm
*/
int gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

long modular_inverse(long e, long tn) {
    long tn0 = tn, y = 0, x =1;
    if (tn == 1) return 0;

    while (e > 1) {
        long q = e/tn, t = tn;

        tn = e % tn;
        e = t;
        t = y;

        y = x - q*y;
        x = t;
    }

    return x+tn0*(x < 0);
}

/* 
Choose e such that 2 < e < nd
*/
long choose_e(long tn) {
    for (long i = tn-1; i > 2; i--) {
        if (gcd(i, tn) == 1) {
            return i;
        }
    }

    return -1;
}

long int mod_pow(long base, long exponent, long mod) {
    long x = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x*base)%mod;
        }
        base = (base*base)%mod;
        exponent /= 2;
    }

    return x%mod;
}

int* encrypt_rsa(char *msg, long e, long n, int *out) {
    printf("Encrypted: ");
    for (int i = 0; msg[i] != '\0'; i++) {
        out[i] = mod_pow(msg[i], e, n);
        printf("%d ", out[i]);
    } 
    printf("\n");
    return out;
}

int* decrypt_rsa(int* encrypt, long d, long n, int len) {
    printf("Decrypted: ");
    for (int i = 0; i < len; i++) {
        encrypt[i] = mod_pow(encrypt[i], d, n);
        printf("%c", encrypt[i]);
    }
    printf("\n");

    return encrypt;
}

void generate_keys(int p, int q, long *n, long *e, long *d) {
    *n = p*q;
    long tn = (p-1)*(q-1); // totient of n
    *e = 17;//choose_e(tn);
    *d = modular_inverse(*e, tn);
}

void rsa(char *msg) {
    printf("Encrypting with RSA...");
    printf("Generating keys...\n");
    int p = 61;
    int q = 53;
    long n, e, d; 
    generate_keys(p, q, &n, &e, &d);
    
    printf("Public key: (%li, %li)\n", e, n);
    printf("Private key: (%li, %li)\n", d, n);
    int len = strlen(msg);
    int out[len];
    int *encrypted = encrypt_rsa(msg, e, n, out);
    decrypt_rsa(encrypted, d, n, len);
}