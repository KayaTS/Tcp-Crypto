#include <iostream>
#include "Tcp.hpp"

using namespace std;

int main(){

    Tcp Client(5000);
    Client.connection();
    Client.sendMessageS();
    Client.receiveMessage();
    
}


