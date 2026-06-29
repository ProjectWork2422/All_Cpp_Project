#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main()
{
    char buffer[1024];

    memset(buffer, 0, sizeof(buffer));

    // Read data sent by the client.
    // xinetd connects the client socket to standard input (fd 0).
    int n = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (n > 0)
    {
        cout << "Server received : " << buffer << endl;

        string reply = "Hello Client, Message Received";

        // Write the reply back to the client.
        // xinetd connects the client socket to standard output (fd 1).
        write(STDOUT_FILENO, reply.c_str(), reply.length());
    }

    return 0;
}
