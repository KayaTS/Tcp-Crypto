#include <iostream>
#include "Tcp.hpp"

using namespace std;

int main(){

    Tcp Client(5000);
    Client.connection();
    cout << "Metni Giriniz:" << endl;
    cin >> Client.plainText;
    Client.sendMessageClient();
    Client.receiveMessage();
    
}


