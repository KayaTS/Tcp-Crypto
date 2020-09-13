#include "Crypto.hpp"
using namespace std;

void Crypto::AesEncryption(const unsigned char * UserAeskey, int keysize, const unsigned char * in, unsigned char * out, int mod = 0, unsigned char * IV = 0){
    AES_set_encrypt_key(UserAeskey, keysize, &m_AesKey);    
    switch (mod)
    {
    case 0: // no mod default encryption
        AES_encrypt(in, out, &m_AesKey);
        break;
    case 1: //Ecb mod encryption
        AES_ecb_encrypt(in, out, &m_AesKey, 1);
        break;
    case 2: // Cbc mod encryption
        if(IV = 0)
            RAND_bytes(IV, sizeof(IV));
        AES_cbc_encrypt(in, out, strlen((const char *)in), &m_AesKey, IV, 1);
        break;
    case 3: // 
        if(IV = 0)
            RAND_bytes(IV, sizeof(IV));
        //AES_ofb128_encrypt(in, out, 8, &m_AesKey, IV, 1);
        break;    
    default:
        break;
    }
    
}
void Crypto::AesDecryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in, unsigned char * out, int mod, unsigned char * IV){
    AES_set_decrypt_key(UserAesKey, keysize, &m_AesKey);
    switch (mod)// mod selection
    {
    case 0:
        /* code */
        break;
    
    default:
        break;
    }
}