#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>  
#include <unistd.h>
#include <iostream>
#include <openssl/aes.h>

using namespace std;

class Client{

    
    int sockfd;
    int port;
    struct sockaddr_in SunucuBilgileri;
    unsigned char plainText[50];
    unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};           
    AES_KEY m_enc;
    public:
        Client(int portnumber){
            port=portnumber;
            sockfd=socket(AF_INET,SOCK_STREAM,0);
            if(sockfd==-1)
                cout<<"soket acilmadi";
            SunucuBilgileri.sin_family=AF_INET;
            SunucuBilgileri.sin_addr.s_addr=htonl(INADDR_ANY);
            SunucuBilgileri.sin_port=htons(port);

        };

        void connection(){
            int dogrulama=connect(sockfd,(struct sockaddr*)&SunucuBilgileri,sizeof(SunucuBilgileri));
            if(dogrulama<0)
                cout<<"baglantı problemi";
            else 
                cout<<"Baglandi\n\n";
        }

        void sendMessage(){
            unsigned char chipherText[50];
            AES_set_encrypt_key(key, 128, &m_enc);
            cout<<"Metni giriniz:" << endl;
            cin >> plainText; 
            AES_encrypt(plainText, chipherText, &m_enc);
            int mesaj_yazildi = write(sockfd, chipherText, sizeof(chipherText));
            cout<<"log send message lend : \n" << mesaj_yazildi  << std::endl;
            if(mesaj_yazildi<0)
                cout<<"MESAJ YAZILAMADI";
            
        }

    
    
        void receiveMessage(){
            unsigned char metin[1024]="\0";
            unsigned char metin2[1024];
            unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};
            AES_KEY m_enc;
            AES_set_decrypt_key(key, 128, &m_enc);
            int mesaj_okundu=read(sockfd,metin,1024);
            AES_decrypt(metin, metin2, &m_enc);  
            if(mesaj_okundu<0)
                cout<<"MESAJ OKUNAMADI";
            cout<<"Gelen Metin:"<< endl << metin2<< endl;
        }
};

int main(){
    Client a(5000);
    a.connection();
    a.sendMessage();
    a.receiveMessage();
    
    
     
    
    }


