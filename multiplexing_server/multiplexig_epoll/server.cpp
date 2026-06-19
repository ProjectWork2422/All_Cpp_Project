#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>
#include <sys/epoll.h>

using namespace std;

#define PORT 8080
#define MAX_EVENTS 10

int main()
{
    int server_fd;

    sockaddr_in server_addr{}, client_addr{};
    socklen_t client_len = sizeof(client_addr);

    // Create Socket
    server_fd = socket(AF_INET,
                       SOCK_STREAM,
                       0);

    if(server_fd < 0)
    {
        cerr << "Socket Creation Failed\n";
        return 1;
    }

    // Configure Address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if(bind(server_fd,
            (sockaddr*)&server_addr,
            sizeof(server_addr)) < 0)
    {
        cerr << "Bind Failed\n";
        return 1;
    }

    // Listen
    listen(server_fd, 5);

    cout << "epoll Server Running...\n";

    // Create epoll instance
    int epfd = epoll_create1(0);

    if(epfd == -1)
    {
        cerr << "epoll_create1 Failed\n";
        return 1;
    }

    // Add server socket to epoll
    epoll_event event{};
    event.events = EPOLLIN;
    event.data.fd = server_fd;

    epoll_ctl(epfd,
              EPOLL_CTL_ADD,
              server_fd,
              &event);

    epoll_event events[MAX_EVENTS];

    while(true)
    {
        int ready =
            epoll_wait(epfd,
                       events,
                       MAX_EVENTS,
                       -1);

        for(int i = 0; i < ready; i++)
        {
            int fd = events[i].data.fd;

            // New connection
            if(fd == server_fd)
            {
                int client_socket =
                    accept(server_fd,
                           (sockaddr*)&client_addr,
                           &client_len);

                cout << "Client Connected\n";

                epoll_event client_event{};
                client_event.events = EPOLLIN;
                client_event.data.fd = client_socket;

                epoll_ctl(epfd,
                          EPOLL_CTL_ADD,
                          client_socket,
                          &client_event);
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

                    epoll_ctl(epfd,
                              EPOLL_CTL_DEL,
                              fd,
                              nullptr);
                }
                else
                {
                    cout << "Received: "
                         << buffer
                         << endl;

                    const char* reply =
                        "Hello From epoll Server";

                    send(fd,
                         reply,
                         strlen(reply),
                         0);
                }
            }
        }
    }

    close(server_fd);
    close(epfd);

    return 0;
}
