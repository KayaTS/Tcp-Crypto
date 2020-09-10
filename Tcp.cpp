#include "Tcp.hpp"
using namespace std;

    Tcp::Tcp(int portnumber){
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

    void Tcp::tcpServer(){
	int kontrol=bind(sockfd,(struct sockaddr *)&SunucuBilgileri,sizeof(SunucuBilgileri));
	if(kontrol<0)
	cout<<"IP ADRES KONTROL ET"  ; 
	else
	cout<<"SOKET OK\n" ;    
    };

    void Tcp::Listen(){
        listen(sockfd,5);
        clientlength=sizeof(MusteriBilgileri);
        clifd=accept(sockfd,(struct sockaddr*)&MusteriBilgileri,&clientlength);
        if(clifd==-1)
            cout<<"Baglantı Kabul Edilmedi";
        else
            cout<<"Bağlantı Kabul Edildi\n";
    }

    void Tcp::connection(){
        int dogrulama=connect(sockfd,(struct sockaddr*)&SunucuBilgileri,sizeof(SunucuBilgileri));
        if(dogrulama<0)
            cout<<"baglantı problemi";
        else 
            cout<<"Baglandi\n\n";
    }

    int Tcp::GetFd(bool defination){ // Server icin 1 gir, client icin 0
        if(defination == true)
            return sockfd;
        return clifd;
    }

    void Tcp::sendMessage(int fd){//Mesaji gonderen server icin clifd, client icin sockfd
        unsigned char chipherText[50];
        AES_set_encrypt_key(key, 128, &m_enc);
        AES_encrypt(plainText, chipherText, &m_enc);
        int mesaj_yazildi = write(fd, chipherText, sizeof(chipherText));
        cout<<"log send message lend : \n" << mesaj_yazildi  <<endl;
        if(mesaj_yazildi<0)
            cout<<"MESAJ YAZILAMADI";
    }
    void Tcp::receiveMessage(int fd){//Mesaji alan server icin clifd, client icin sockfd
        unsigned char metin[1024]="\n";
        unsigned char metin2[1024];
        AES_set_decrypt_key(key, 128, &m_enc);
        int mesaj_okundu=read(fd,metin,1024);
        AES_decrypt(metin, metin2, &m_enc);  
        if(mesaj_okundu<0)
            cout<<"MESAJ OKUNAMADI";
        cout<<"Gelen Metin:"<< endl << metin2<< endl;
    }
