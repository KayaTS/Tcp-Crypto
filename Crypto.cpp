#include "Crypto.hpp"
using namespace std;

void Crypto::AesEncryption(const unsigned char * UserAeskey, int keysize, const unsigned char * in, unsigned char * out, int outlen, int mod = 0)
{
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
        RAND_bytes(iv, 16);
        AES_cbc_encrypt(in, out, outlen, &m_AesKey, iv, 1);
        break;
    case 3: // 
        RAND_bytes(iv, sizeof(iv));
        //AES_ofb128_encrypt(in, out, 8, &m_AesKey, IV, 1);
        break;    
    default:
        break;
    }
    
}
void Crypto::AesDecryption(const unsigned char * UserAesKey, int keysize, const unsigned char * in, unsigned char * out, int outlen, int mod)
{
    AES_set_decrypt_key(UserAesKey, keysize, &m_AesKey);
    switch (mod)// mod selection
    {
    case 0: // No mod default decryption
        AES_decrypt(in, out, &m_AesKey);
        break;
    case 1: //ECB mod decryption
        AES_ecb_encrypt(in, out, &m_AesKey, 0);
        break;
    case 2: // Cbc mod decryption
        RAND_bytes(iv, 16);
        AES_cbc_encrypt(in, out, outlen, &m_AesKey, iv, 0);
        break;
    case 3: // 
        RAND_bytes(iv, sizeof(iv));
        //AES_ofb128_encrypt(in, out, 8, &m_AesKey, IV, 0);
        break;    
    default:
        break;
    }
}
void Crypto::ModSelection()
{

}
void Crypto::DesEncryption()
{

}
void Crypto::DesDecryption()
{

}
void Crypto::BfEncryption(const unsigned char * UserKey, int keysize, const unsigned char * in, unsigned char * out, int mod = 0)
{
    BF_set_key(&m_BfKey, 128, UserKey);
    RAND_bytes(iv, sizeof(iv)); //ECB disindaki modlar icin IV
    switch (mod)// mod selection
    {
    case 1: //ECB mod decryption
        BF_ecb_encrypt(in, out, &m_BfKey, 1);
        break;
    case 2: // Cbc mod decryption
        BF_cbc_encrypt(in, out, 0, &m_BfKey, iv, 1);
        break;
    case 3: // 
        //AES_ofb128_encrypt(in, out, 8, &m_AesKey, IV, 1);
        break;    
    default:
        break;
    }
}
void Crypto::BfDecryption(const unsigned char * UserKey, int keysize, const unsigned char * in, unsigned char * out, int mod = 0)
{
    BF_set_key(&m_BfKey, 128, UserKey);
    RAND_bytes(iv, sizeof(iv)); //ECB disindaki modlar icin IV
    switch (mod)// mod selection
    {
    case 1: //ECB mod decryption
        BF_ecb_encrypt(in, out, &m_BfKey, 0);
        break;
    case 2: // Cbc mod decryption
        BF_cbc_encrypt(in, out, 0, &m_BfKey, iv, 0);
        break;
    case 3: // 
        //AES_ofb128_encrypt(in, out, 8, &m_AesKey, IV, 0);
        break;    
    default:
        break;
    }
}