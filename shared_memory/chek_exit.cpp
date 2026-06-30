#include <iostream>
#include <cerrno>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

int main()
{
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666);

    if (shmid == -1)
    {
        cout << "Shared Memory does NOT exist." << endl;
        cout << "Error : " << strerror(errno) << endl;
    }
    else
    {
        cout << "Shared Memory exists." << endl;
        cout << "Shared Memory ID : " << shmid << endl;
    }

    return 0;
}