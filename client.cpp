#include <iostream>
#include "Tcp.hpp"

#define Clifd 0
#define Sockfd 1

using namespace std;

int main(){

    Tcp Client(5000);
    Client.connection();
    cout << "Metni Giriniz:" << endl;
    cin >> Client.plainText;
    Client.sendMessage(Client.GetFd(Sockfd));
    Client.receiveMessage(Client.GetFd(Sockfd));
    
}


