#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sock;

    sockaddr_in serv_addr{};

    sock = socket(AF_INET,
                  SOCK_STREAM,
                  0);

    if (sock < 0)
    {
        std::cerr
            << "Socket creation failed\n";
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serv_addr.sin_addr);

    if (connect(sock,
                (sockaddr*)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        std::cerr
            << "Connection Failed\n";
        return 1;
    }

    std::cout
        << "Connected To Server\n";

    std::string message;

    char buffer[1024];

    while (true)
    {
        std::cout
            << "\nEnter Request (type exit to quit): ";

        std::getline(std::cin, message);

        send(sock,
             message.c_str(),
             message.length(),
             0);

        memset(buffer, 0, sizeof(buffer));

        int bytes =
            recv(sock,
                 buffer,
                 sizeof(buffer) - 1,
                 0);

        if (bytes <= 0)
        {
            std::cout
                << "Server Closed Connection\n";
            break;
        }

        buffer[bytes] = '\0';

        std::cout
            << "Server Response: "
            << buffer
            << std::endl;

        if (message == "exit")
        {
            std::cout
                << "\nClient Terminated Successfully\n";
            break;
        }
    }

    close(sock);

    return 0;
}