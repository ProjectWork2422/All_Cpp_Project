#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/socket.h>

using namespace std;

int main()
{
int server_fd;
int client_socket;


sockaddr_in server_addr{};
sockaddr_in client_addr{};

socklen_t client_len = sizeof(client_addr);

// Create Socket
server_fd = socket(AF_INET, SOCK_STREAM, 0);

if(server_fd < 0)
{
    cerr << "Socket Creation Failed\n";
    return 1;
}

// Server Configuration
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);
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
if(listen(server_fd, 5) < 0)
{
    cerr << "Listen Failed\n";
    return 1;
}

cout << "Server Listening on Port 8080..." << endl;

while(true)
{
    // Accept Client
    client_socket =
        accept(server_fd,
               (sockaddr*)&client_addr,
               &client_len);

    if(client_socket < 0)
    {
        cerr << "Accept Failed\n";
        continue;
    }

    cout << "Client Connected" << endl;

    pid_t pid = fork();

    if(pid == 0)
    {
        // Child Process

        close(server_fd);

        char buffer[1024];

        memset(buffer, 0, sizeof(buffer));

        read(client_socket,
             buffer,
             sizeof(buffer));

        cout << "Message From Client: "
             << buffer
             << endl;

        const char* reply =
            "Hello From Child Process";

        send(client_socket,
             reply,
             strlen(reply),
             0);

        close(client_socket);

        return 0;
    }
    else if(pid > 0)
    {
        // Parent Process

        close(client_socket);
    }
    else
    {
        cerr << "Fork Failed\n";
    }
}

close(server_fd);

return 0;


}
