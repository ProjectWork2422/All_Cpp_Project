 #include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

using namespace std;

int main()
{
    int client_fd;

    sockaddr_in server_addr{};

    client_fd =
        socket(AF_INET,
               SOCK_STREAM,
               0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);

    connect(client_fd,
            (sockaddr*)&server_addr,
            sizeof(server_addr));

    const char* msg =
        "Hello xinetd Server";

    send(client_fd,
         msg,
         strlen(msg),
         0);

    close(client_fd);

    return 0;
}
