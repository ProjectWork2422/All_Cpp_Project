#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>
#include <sys/select.h>

using namespace std;

int main()
{
    int server_fd, client_socket;
    sockaddr_in server_addr{}, client_addr{};

    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd < 0)
    {
        cerr << "Socket Creation Failed\n";
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_fd,
            (sockaddr*)&server_addr,
            sizeof(server_addr)) < 0)
    {
        cerr << "Bind Failed\n";
        return 1;
    }

    listen(server_fd, 5);

    cout << "Multiplexing Server Running...\n";

    fd_set master_set;
    fd_set read_set;

    FD_ZERO(&master_set);

    FD_SET(server_fd, &master_set);

    int max_fd = server_fd;

    while(true)
    {
        read_set = master_set;

        int activity =
            select(max_fd + 1,
                   &read_set,
                   NULL,
                   NULL,
                   NULL);

        if(activity < 0)
        {
            cerr << "Select Error\n";
            continue;
        }

        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(FD_ISSET(fd, &read_set))
            {
                // New Client Connection
                if(fd == server_fd)
                {
                    client_socket =
                        accept(server_fd,
                               (sockaddr*)&client_addr,
                               &client_len);

                    if(client_socket >= 0)
                    {
                        FD_SET(client_socket,
                               &master_set);

                        if(client_socket > max_fd)
                        {
                            max_fd = client_socket;
                        }

                        cout << "New Client Connected\n";
                    }
                }
                else
                {
                    char buffer[1024];

                    memset(buffer,
                           0,
                           sizeof(buffer));

                    int bytes =
                        read(fd,
                             buffer,
                             sizeof(buffer));

                    if(bytes <= 0)
                    {
                        cout << "Client Disconnected\n";

                        close(fd);

                        FD_CLR(fd,
                               &master_set);
                    }
                    else
                    {
                        cout << "Message: "
                             << buffer
                             << endl;

                        const char* reply =
                            "Message Received";

                        send(fd,
                             reply,
                             strlen(reply),
                             0);
                    }
                }
            }
        }
    }

    close(server_fd);

    return 0;
}
