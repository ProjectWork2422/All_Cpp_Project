#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

int main()
{
    // Generate the same key
    key_t key = ftok("shmfile", 65);

    // Access the existing shared memory
    int shmid = shmget(key, 1024, 0666);

    // Attach shared memory
    char *ptr = (char *)shmat(shmid, NULL, 0);

    // Read data from shared memory
    cout << "Data Read : " << ptr << endl;

    // Detach shared memory
    shmdt(ptr);

    return 0;
}

