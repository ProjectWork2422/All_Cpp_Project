#include <iostream>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

int main()
{
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    // Attach shared memory
    char *ptr = (char *)shmat(shmid, NULL, 0);

    // Write data into shared memory
    strcpy(ptr, "Hello Shared Memory");

    cout << "Data Written Successfully" << endl;

    // Detach shared memory
    shmdt(ptr);

    return 0;
}