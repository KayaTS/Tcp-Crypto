#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>  
#include <unistd.h>
#include <iostream>
#include <openssl/aes.h>
//#include "openssl.hpp"


#define DEBUG
#ifdef  DEBUG
#define log_debug(x) std::cout << (x) << std::endl;
#else
#define log_debug(x)
#endif 

using namespace std;

class Server{
    socklen_t clientlength;
    
    int sockfd;
    int clifd;
    int port;
    unsigned char plainText[50];
    unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};           
    AES_KEY m_enc;
    struct sockaddr_in SunucuBilgileri,MusteriBilgileri;
    public:
        Server(int portnumber){
            port=portnumber;
            sockfd=socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd==-1)
                cout<<"soket acilmadi";
            else
                cout<<"soket acildi\n";
            SunucuBilgileri.sin_family=AF_INET;
            SunucuBilgileri.sin_addr.s_addr=htonl(INADDR_ANY);
            SunucuBilgileri.sin_port = htons(port);
            int kontrol=bind(sockfd,(struct sockaddr *)&SunucuBilgileri,sizeof(SunucuBilgileri));
            if(kontrol<0)
                cout<<"IP ADRES KONTROL ET"  ; 
            else
                cout<<"SOKET OK\n" ;    

	   

        };

        void Listen(){
            listen(sockfd,5);
            clientlength=sizeof(MusteriBilgileri);
            clifd=accept(sockfd,(struct sockaddr*)&MusteriBilgileri,&clientlength);
            if(clifd==-1)
                cout<<"Baglantı Kabul Edilmedi";
            else
                cout<<"Bağlantı Kabul Edildi\n";
        }
        void sendMessage(){
            unsigned char chipherText[50];
            AES_set_encrypt_key(key, 128, &m_enc);
            cout<<"Metni giriniz:" << endl;
            cin >> plainText; 
            AES_encrypt(plainText, chipherText, &m_enc);
            int mesaj_yazildi=write(clifd, chipherText, strlen((const char *)chipherText));
            if(mesaj_yazildi<0)
                cout<<"MESAJ YAZILAMADI/n";
        }

        void * receiveMessage(){
            unsigned char metin[1024] = "\n";
            unsigned char metin2[1024];
            AES_set_decrypt_key(key, 128, &m_enc);
            int mesaj_okundu = read(clifd, metin, 1024);
            AES_decrypt(metin, metin2, &m_enc);  
            cout << "server len : " << strlen((const char *)metin2) << endl;
            if(mesaj_okundu < 0){
               perror("error : "); 
                cout<<"MESAJ OKUNAMADI\n";
            }
            cout<<"Gelen Metin:" << endl << metin2<<endl;
                    
        }
};

int main(){

    Server server(5000);
    server.Listen();
    server.receiveMessage();
    server.sendMessage();
    

}
