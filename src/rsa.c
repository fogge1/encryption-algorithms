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

int* encrypt_rsa(char *msg, long e, long n, int *encrypted) {
    int len = strlen(msg)+1;
    

    for (int i = 0; msg[i] != '\0'; i++) {
        encrypted[i] = mod_pow(msg[i], e, n);
        printf("%d ", encrypted[i]);
    } 
    encrypted[len] = 0;
    printf("\n");
    return encrypted;
}

int* decrypt_rsa(int* encrypt, long d, long n) {
    int *out = encrypt;
    
    for (int i = 0; encrypt[i] !=0; i++) {
        out[i] = mod_pow(encrypt[i], d, n);
        printf("%c", out[i]);
    }
    printf("\n");

    return out;
}