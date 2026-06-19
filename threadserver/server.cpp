#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

void handleClient(int clientSocket)
{
    char buffer[1024];

    while (true)
    {
        memset(buffer, 0, sizeof(buffer));

        int bytesReceived = recv(clientSocket,
                                 buffer,
                                 sizeof(buffer),
                                 0);

        if (bytesReceived <= 0)
        {
            std::cout << "Client disconnected.\n";
            break;
        }

        std::cout << "Client says: "
                  << buffer
                  << std::endl;

        std::string reply =
            "Server received: " +
            std::string(buffer);

        send(clientSocket,
             reply.c_str(),
             reply.size(),
             0);
    }

    close(clientSocket);
}

int main()
{
    int serverSocket;
    sockaddr_in serverAddress;

    serverSocket = socket(AF_INET,
                          SOCK_STREAM,
                          0);

    if (serverSocket < 0)
    {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket,
             (sockaddr*)&serverAddress,
             sizeof(serverAddress)) < 0)
    {
        std::cerr << "Bind failed\n";
        return 1;
    }

    listen(serverSocket, 5);

    std::cout << "Server listening on port 8080...\n";

    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientLen =
            sizeof(clientAddress);

        int clientSocket =
            accept(serverSocket,
                   (sockaddr*)&clientAddress,
                   &clientLen);

        if (clientSocket < 0)
        {
            std::cerr << "Accept failed\n";
            continue;
        }

        std::cout
            << "New client connected\n";

        std::thread clientThread(
            handleClient,
            clientSocket);

        clientThread.detach();
    }

    close(serverSocket);

    return 0;
}
