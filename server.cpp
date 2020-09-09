#include <iostream>
#include "Tcp.hpp"

using namespace std;

int main(){
    Tcp server(5000);
    server.TcpServer();
    server.Listen();
    cout << "Metni Giriniz:" << endl;
    cin >> server.plainText;
    server.sendMessageServer();
    server.receiveMessage();

}
