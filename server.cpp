#include "server.hpp"

//Encryption mods
#define Default 0
#define ECB 1
#define CBC 2
#define OFB 3
#define CFB 4
#define CTR 5

using namespace std;


Server::Server(int portnumber)
{

    port=portnumber;
    sockfd=socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd==-1)
        cout<<"soket acilmadi";
    else
        cout<<"soket acildi\n";

    SunucuBilgileri.sin_family=AF_INET;
    SunucuBilgileri.sin_addr.s_addr=htonl(INADDR_ANY);
    SunucuBilgileri.sin_port = htons(port);
    int kontrol=bind(sockfd,(struct sockaddr *)&SunucuBilgileri,sizeof(SunucuBilgileri));

    if (kontrol<0)
        cout<<"IP ADRES KONTROL ET"  ; 
    else
        cout<<"SOKET OK\n" ; 
};

void Server::Listen()
{
    listen(sockfd,5);

    clientlength=sizeof(MusteriBilgileri);
    clifd=accept(sockfd,(struct sockaddr*)&MusteriBilgileri,&clientlength);

    if (clifd==-1)
        cout<<"Baglantı Kabul Edilmedi";
    else
        cout<<"Bağlantı Kabul Edildi\n";

};


void Server::sendMessage()
{
    unsigned char chipherText[50];

    crypto.AesEncryption(key, 128, plainText, chipherText, 50, ECB); // Encryption with CBC

    int mesaj_yazildi = write(clifd, chipherText, sizeof(chipherText));
    cout<<"log send message lend : \n" << mesaj_yazildi  <<endl;

    if(mesaj_yazildi<0)
        cout<<"MESAJ YAZILAMADI";
};

void Server::receiveMessage() 
{
    unsigned char metin[1024]="\n";
    unsigned char metin2[1024];

    int mesaj_okundu=read(clifd,metin,1024);

    crypto.AesDecryption(key, 128, metin, metin2, 50, ECB); // Encryption with CBC

    if(mesaj_okundu<0)
        cout<<"MESAJ OKUNAMADI";
    cout<<"Gelen Metin(ECB):"<< endl << metin2<< endl;
};


int main()
{
    Server server(5000);
    server.Listen();
    for(;;)
    {
    server.receiveMessage();
	}
}

