#include <iostream>
#include "server.hpp"

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

    };

    void Server::tcpServer()
    {

	int kontrol=bind(sockfd,(struct sockaddr *)&SunucuBilgileri,sizeof(SunucuBilgileri));
	
    if(kontrol<0)
	cout<<"IP ADRES KONTROL ET"  ; 

	else
	cout<<"SOKET OK\n" ; 

    };

    void Server::Listen()
    {
        listen(sockfd,5);

        clientlength=sizeof(MusteriBilgileri);
        clifd=accept(sockfd,(struct sockaddr*)&MusteriBilgileri,&clientlength);

        if(clifd==-1)
            cout<<"Baglantı Kabul Edilmedi";

        else
            cout<<"Bağlantı Kabul Edildi\n";

    };

    

    int Server::GetFd(bool defination)
    { // Server icin 1 gir, client icin 0
        
        if(defination == true)
            return sockfd;
        return clifd;
    };

    void Server::sendMessage(int fd) //Mesaji gonderirken server icin clifd, client icin sockfd
    {
        unsigned char chipherText[50];

        crypto.AesEncryption(key, 128, plainText, chipherText, ECB); // Encryption with CBC

        int mesaj_yazildi = write(fd, chipherText, sizeof(chipherText));
        cout<<"log send message lend : \n" << mesaj_yazildi  <<endl;

        if(mesaj_yazildi<0)
            cout<<"MESAJ YAZILAMADI";
    };
    
    void Server::receiveMessage(int fd) //Mesaji alirken server icin clifd, client icin sockfd
    {
        unsigned char metin[1024]="\n";
        unsigned char metin2[1024];

        int mesaj_okundu=read(fd,metin,1024);

        crypto.AesDecryption(key, 128, metin, metin2, ECB); // Encryption with CBC

        if(mesaj_okundu<0)
            cout<<"MESAJ OKUNAMADI";
        cout<<"Gelen Metin:"<< endl << metin2<< endl;
    };


int main(){
    Server server(5000);
    server.tcpServer();
    server.Listen();
    cout << "Metni Giriniz:" << endl;
    cin >> server.plainText;
    server.sendMessage(server.GetFd(Clifd));
    server.receiveMessage(server.GetFd(Clifd));
}
