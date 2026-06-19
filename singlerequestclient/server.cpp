#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_socket;
    sockaddr_in address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, 3);

    std::cout << "Server waiting..." << std::endl;

    socklen_t addrlen = sizeof(address);
    client_socket = accept(server_fd,
                          (struct sockaddr*)&address,
                          &addrlen);

    char buffer[1024] = {0};
    recv(client_socket, buffer, 1024, 0);

    std::cout << "Client says: " << buffer << std::endl;

    const char* msg = "Hello from Server";
    send(client_socket, msg, strlen(msg), 0);

    close(client_socket);
    close(server_fd);

    return 0;
}
