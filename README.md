# Tcp-Crypto
TCP communication with symmetric cipher algorithms

Derlemek için:
1-)g++ server.cpp Crypto.cpp -L/usr/lib -lssl -lcrypto -o server -g
2-)g++ client.cpp Crypto.cpp -L/usr/lib -lssl -lcrypto -o client -g

Çalıştırmak için:
1-)./server
2-)./client(İkinci bir terminalde)
3-)Metin girip, mesajı yollayın.

