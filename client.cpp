#include <iostream>
#include "client.hpp"

#define Clifd 0
#define Sockfd 1

//Encryption mods
#define Default 0
#define ECB 1
#define CBC 2
#define OFB 3
#define CFB 4
#define CTR 5


using namespace std;

Client::Client(int portnumber)
{
    port=portnumber;
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1)
	cout<<"soket acilmadi";
	else
	cout<<"soket acildi\n";
	SunucuBilgileri.sin_family=AF_INET;
	SunucuBilgileri.sin_addr.s_addr=htonl(INADDR_ANY);
	SunucuBilgileri.sin_port = htons(port);
};

void Client::connection()
{
        int dogrulama=connect(sockfd,(struct sockaddr*)&SunucuBilgileri,sizeof(SunucuBilgileri));
        if(dogrulama<0)
            cout<<"baglantı problemi";
        else 
            cout<<"Baglandi\n\n";
}
int Client::GetFd(bool defination)// Server icin 1 gir, client icin 0
{ 
        if(defination == true)
            return sockfd;
        return clifd;
}

void Client::sendMessage(int fd)//Mesaji gonderirken server icin clifd, client icin sockfd
{
        unsigned char chipherText[50];
        crypto.AesEncryption(key, 128, plainText, chipherText, 50, ECB); // Encryption with CBC
        int mesaj_yazildi = write(fd, chipherText, sizeof(chipherText));
        cout<<"log send message lend : \n" << mesaj_yazildi  <<endl;
        if(mesaj_yazildi<0)
            cout<<"MESAJ YAZILAMADI";
}
void Client::receiveMessage(int fd)//Mesaji alirken server icin clifd, client icin sockfd
{
        unsigned char metin[1024]="\n";
        unsigned char metin2[1024];
        int mesaj_okundu=read(fd,metin,1024);
        crypto.AesDecryption(key, 128, metin, metin2, 50, ECB);// Encryption with CBC
        if(mesaj_okundu<0)
            cout<<"MESAJ OKUNAMADI";
        cout<<"Gelen Metin(ECB):"<< endl << metin2<< endl;
}


int main()
{

    Client Client(5000);
    Client.connection();
    cout << "Metni Giriniz:" << endl;
    cin >> Client.plainText;
    Client.sendMessage(Client.GetFd(Sockfd));
    Client.receiveMessage(Client.GetFd(Sockfd));
    
}


