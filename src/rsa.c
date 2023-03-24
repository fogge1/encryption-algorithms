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
int gcd(unsigned long a, unsigned long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

long long modular_inverse(unsigned long e, unsigned long tn) {
    long long tn0 = tn, y = 0, x =1;
    if (tn == 1) return 0;

    while (e > 1) {
        long long q = e/tn, t = tn;

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

This function will choose the highest number possible of e

which isn't optimal for large numbers of p and q as it will have the effect of having to take the power of numbers being in the millions
*/
long choose_e(unsigned long tn) {
    for (unsigned long i = tn-1; i > 2; i--) {
        if (gcd(i, tn) == 1) {
            return i;
        }
    }

    return -1;
}

void generate_keys(unsigned int p, unsigned int q, unsigned long *n, unsigned long *e, unsigned long *d) {
    *n = p*q;
    // the totient of n
    unsigned long tn = (p-1)*(q-1);
    *e = choose_e(tn);
    // the private key d = the modular inverse of e and the totient of n
    *d = modular_inverse(*e, tn);
}

// IMPLEMENT GENERATION OF PRIME NUMBERS

// int *firstPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
//     67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
//     157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,
//     251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
//     353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449,
//     457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
//     571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661,
//     673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
//     797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
//     911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 0
// };



// int isPrime(int p) {
//     for (int i = 0; firstPrimes[i] != 0; i++) {
//         if (p % firstPrimes[i] == 0) {
//             return 0;
//         }
//     }

//     if(rabin_miller(p)) return 1;
//     return 0;
// }

// int generate_prime(int min, int max) {
//     while (1) {
//         int p = (rand() % (max-min+1)+min);
//         if (is_prime(p)) {
//             return p;
//         }
//     }
// }

// modular power to avoid having to take the modulus of numbers like 104^e, where e = 2000
unsigned long int mod_pow(unsigned long base, unsigned long exponent, unsigned long mod) {
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

unsigned long* encrypt_rsa(char *msg, unsigned long e, unsigned long n, unsigned long *out) {
    printf("Encrypted: ");
    // loop through each character and set it to the encrypted number
    for (int i = 0; msg[i] != '\0'; i++) {
        out[i] = mod_pow(msg[i], e, n);
        printf("%ld ", out[i]);
    } 
    printf("\n");
    return out;
}

unsigned long* decrypt_rsa(unsigned long* encrypt, unsigned long d, unsigned long n, int len) {
    printf("Decrypted: ");
    for (int i = 0; i < len; i++) {
        encrypt[i] = mod_pow(encrypt[i], d, n);
        printf("%c", encrypt[i]);
    }
    printf("\n");

    return encrypt;
}

void rsa(char *msg) {
    printf("Encrypting with RSA...\n");
    printf("Generating keys...\n");
    // define primenumbers
    unsigned int p = 6947;//generate_prime(0,32767);
    unsigned int q = 4409;//generate_prime(0,32767);
    // define key values
    unsigned long n, e, d; 
    generate_keys(p, q, &n, &e, &d);
    
    printf("Public key: (%li, %li)\n", e, n);
    printf("Private key: (%li, %li)\n", d, n);
    // get the length of the message to use later when decrypting the message
    int len = strlen(msg);
    unsigned long out[len];
    unsigned long *encrypted = encrypt_rsa(msg, e, n, out);
    decrypt_rsa(encrypted, d, n, len);
    printf("\n");
}