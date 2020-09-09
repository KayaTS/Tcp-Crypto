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
    unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};
    AES_KEY m_enc;
    struct sockaddr_in SunucuBilgileri,MusteriBilgileri;
    socklen_t clientlength;
    public:
        unsigned char plainText[50];
        Tcp(int portnumber);
        void TcpServer();
        void connection();
        void Listen();
        void sendMessageClient();
        void sendMessageServer();
        void receiveMessage();
};
