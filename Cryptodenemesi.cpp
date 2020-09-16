#include <iostream>
#include "Crypto.hpp"
using namespace std;
int main() {
    unsigned char plainText[50];
    unsigned char cipherText[50];
    unsigned char decrypted[50];
    unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};
    Crypto deneme;
    cin >> plainText;
    deneme.AesEncryption(key, 128, plainText, cipherText, 50, 0);
    cout << "Mesaj" << plainText << endl;
    cout << "Sifreli mesaj" << cipherText << endl;
    deneme.AesDecryption(key, 128, cipherText, decrypted, 50, 0);
    cout << "modsuz sifre cozme;  " << decrypted << endl;
    deneme.AesEncryption(key, 128, plainText, cipherText, 50, 1);
    deneme.AesDecryption(key, 128, cipherText, decrypted, 50, 1);
    cout << "ecb modu ile sifre cozme;  " << decrypted << endl;
    deneme.AesEncryption(key, 128, plainText, cipherText, 16, 2);
    deneme.AesDecryption(key, 128, cipherText, decrypted, 0, 2);
    cout << "cbc modu ile sifre cozme;  " << decrypted << endl;
    return 0;

}
