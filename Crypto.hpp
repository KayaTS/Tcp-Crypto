#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<openssl/aes.h>
#include<openssl/des.h>
#include<openssl/blowfish.h>
#include<openssl/rand.h>
using namespace std;

class Crypto{
    AES_KEY m_AesKey;
    unsigned char iv[8];
public:
    void AesEncryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in,
       unsigned char * out, int mod, unsigned char * IV);
    void AesDecryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in, unsigned char * out, int mod, unsigned char * IV);
    void ModSelection();
    void DesEncryption();
    void DesDecryption();
    void BfEncryption();
    void BfDecryption();
};