#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

int main()
{
    // Generate the same key
    key_t key = ftok("shmfile", 65);

    // Get the shared memory ID
    int shmid = shmget(key, 1024, 0666);

    // Remove the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    cout << "Shared Memory Deleted Successfully" << endl;

    return 0;
}