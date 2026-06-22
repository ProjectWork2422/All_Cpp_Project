#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main()
{
    char buffer[1024];

    memset(buffer, 0, sizeof(buffer));

    read(STDIN_FILENO,
         buffer,
         sizeof(buffer));

    ofstream file("server.log", ios::app);

    file << "Server Received: "
         << buffer
         << endl;

    file.close();

    return 0;
}
