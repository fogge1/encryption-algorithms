int* encrypt_rsa(char *msg, long e, long n, int *encrypted);
int* decrypt_rsa(int *encrypt, long d, long n);
int choose_e(long dn);
long modular_inverse(long e, long tn);