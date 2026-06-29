#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main()
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(9090);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd,
               (sockaddr*)&server,
               sizeof(server)) < 0)
    {
        perror("connect");
        return 1;
    }

    string msg = "Hello Server";

    send(sockfd,
         msg.c_str(),
         msg.length(),
         0);

    char buffer[1024];

    memset(buffer,0,sizeof(buffer));

    recv(sockfd,
         buffer,
         sizeof(buffer),
         0);

    cout << "Reply : " << buffer << endl;

    close(sockfd);

    return 0;
}
