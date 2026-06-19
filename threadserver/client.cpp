#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int clientSocket;
    sockaddr_in serverAddress;

    clientSocket = socket(AF_INET,
                          SOCK_STREAM,
                          0);

    if (clientSocket < 0)
    {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serverAddress.sin_addr);

    if (connect(clientSocket,
                (sockaddr*)&serverAddress,
                sizeof(serverAddress)) < 0)
    {
        std::cerr << "Connection failed\n";
        return 1;
    }

    char buffer[1024];
    std::string message;

    while (true)
    {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        if (message == "exit")
            break;

        send(clientSocket,
             message.c_str(),
             message.size(),
             0);

        memset(buffer, 0, sizeof(buffer));

        recv(clientSocket,
             buffer,
             sizeof(buffer),
             0);

        std::cout
            << "Server: "
            << buffer
            << std::endl;
    }

    close(clientSocket);

    return 0;
}
