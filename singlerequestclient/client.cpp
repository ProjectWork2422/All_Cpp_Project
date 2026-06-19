#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    sockaddr_in serv_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "192.168.2.19",
              &serv_addr.sin_addr);

    connect(sock,
            (struct sockaddr*)&serv_addr,
            sizeof(serv_addr));

    const char* msg = "Hello Server";
    send(sock, msg, strlen(msg), 0);

    char buffer[1024] = {0};
    recv(sock, buffer, 1024, 0);

    std::cout << "Server says: "
              << buffer << std::endl;

    close(sock);

    return 0;
}
