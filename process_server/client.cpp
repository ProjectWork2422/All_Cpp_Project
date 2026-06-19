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

// Create Socket
client_fd = socket(AF_INET, SOCK_STREAM, 0);

if(client_fd < 0)
{
    cerr << "Socket Creation Failed\n";
    return 1;
}

// Server Configuration
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);

inet_pton(AF_INET,
          "127.0.0.1",
          &server_addr.sin_addr);

// Connect to Server
if(connect(client_fd,
           (sockaddr*)&server_addr,
           sizeof(server_addr)) < 0)
{
    cerr << "Connection Failed\n";
    return 1;
}

cout << "Connected To Server\n";

string message;

cout << "Enter Message: ";
getline(cin, message);

send(client_fd,
     message.c_str(),
     message.length(),
     0);

char buffer[1024];

memset(buffer, 0, sizeof(buffer));

read(client_fd,
     buffer,
     sizeof(buffer));

cout << "Server Reply: "
     << buffer
     << endl;

close(client_fd);

return 0;


}
