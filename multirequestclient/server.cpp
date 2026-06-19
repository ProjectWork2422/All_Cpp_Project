#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd;

    sockaddr_in address{};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd,
             (sockaddr*)&address,
             sizeof(address)) < 0)
    {
        std::cerr << "Bind failed\n";
        return 1;
    }

    if (listen(server_fd, 5) < 0)
    {
        std::cerr << "Listen failed\n";
        return 1;
    }

    std::cout
        << "Server listening on port 8080...\n";

    socklen_t addrlen = sizeof(address);

    bool shutdown_server = false;

    while (!shutdown_server)
    {
        int client_socket =
            accept(server_fd,
                   (sockaddr*)&address,
                   &addrlen);

        if (client_socket < 0)
        {
            std::cerr << "Accept failed\n";
            continue;
        }

        std::cout
            << "\nClient Connected\n";

        char buffer[1024];

        while (true)
        {
            memset(buffer, 0, sizeof(buffer));

            int bytes =
                recv(client_socket,
                     buffer,
                     sizeof(buffer) - 1,
                     0);

            if (bytes <= 0)
            {
                std::cout
                    << "Client Disconnected\n";
                break;
            }

            buffer[bytes] = '\0';

            std::string request(buffer);

            if (request == "exit")
            {
                std::cout
                    << "\nShutdown Command Received\n";

                shutdown_server = true;

                std::string msg =
                    "Server shutting down...";

                send(client_socket,
                     msg.c_str(),
                     msg.length(),
                     0);

                break;
            }

            std::cout
                << "Client Request: "
                << request
                << std::endl;

            std::string response =
                "Server processed: " + request;

            send(client_socket,
                 response.c_str(),
                 response.length(),
                 0);
        }

        close(client_socket);
    }

    close(server_fd);

    std::cout
        << "\nServer Terminated Successfully\n";

    return 0;
}