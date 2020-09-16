# Tcp-Crypto
TCP communication with symmetric cipher algorithms

# Kurulum için :

sudo apt-get install libssl-dev

### Derlemek için:
```
- g++ server.cpp Crypto.cpp -L/usr/lib -lssl -lcrypto -o server -g
- g++ client.cpp Crypto.cpp -L/usr/lib -lssl -lcrypto -o client -g
```
---
### Çalıştırmak için:
```
- ./server
- ./client (İkinci bir terminalde)
```  
Son olarak metin girip, mesajı yollayın.

