#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>  
#include <unistd.h>
#include <iostream>
#include <openssl/aes.h>

using namespace std;

class Tcp{
    int sockfd;
    int clifd;
    int port;
    unsigned char plainText[50] = "Merhaba";
    unsigned char key[16];           
    AES_KEY m_enc;
    struct sockaddr_in SunucuBilgileri,MusteriBilgileri;
    socklen_t clientlength;
    public:
        Tcp(int portnumber);
        void TcpServer();
        void connection();
        void Listen();
        void sendMessageS();
        void sendMessageC();
        void receiveMessage();
};
