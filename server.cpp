#include <iostream>
#include "Tcp.hpp"
#define Clifd 0
#define Sockfd 1
using namespace std;

int main(){
    Tcp server(5000);
    server.tcpServer();
    server.Listen();
    cout << "Metni Giriniz:" << endl;
    cin >> server.plainText;
    server.sendMessage(server.GetFd(Clifd));
    server.receiveMessage(server.GetFd(Clifd));
}
