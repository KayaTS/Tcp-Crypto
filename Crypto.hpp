#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <openssl/aes.h>
#include <openssl/des.h>
#include <openssl/blowfish.h>
#include <openssl/rand.h>
using namespace std;

class Crypto{
    AES_KEY m_AesKey;
    BF_KEY m_BfKey;
    unsigned char iv[16];
public:
    void AesEncryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in, unsigned char * out, int outlen, int mod);
    void AesDecryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in, unsigned char * out, int outlen, int mod);
    void ModSelection();
    void DesEncryption();
    void DesDecryption();
    void BfEncryption(const unsigned char * UserKey, int keysize, const unsigned char * in, unsigned char * out, int mod);
    void BfDecryption(const unsigned char * UserKey, int keysize, const unsigned char * in, unsigned char * out, int mod);
};