#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>  
#include <unistd.h>
#include <iostream>
#include "Crypto.hpp"



class Client
{

    int sockfd;
    int clifd;
    int port;

    socklen_t clientlength;

    struct sockaddr_in SunucuBilgileri;
    
    AES_KEY m_enc;

    Crypto crypto;

    unsigned char key[16] = {0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x85, 0x02, 0x05, 0x10, 0x8, 0x02, 0x05, 0x10, 0x85};


    public:

        unsigned char plainText[50];

        Client(int portnumber);

        void connection();
        void sendMessage(int fd);
        void receiveMessage(int fd);

        int GetFd(bool defination);//Server icin sockfd, client icin clifd dondurur.
};