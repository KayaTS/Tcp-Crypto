#include <iostream>
#include "Tcp.hpp"

using namespace std;

int main(){
    Tcp server(5000);
    server.TcpServer();
    server.Listen();
    server.sendMessageC();
    server.receiveMessage();

}
