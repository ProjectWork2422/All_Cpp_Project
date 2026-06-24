#include <iostream>
#include <pthread.h>

using namespace std;

struct Data
{
    int id;
    string name;
};

void* worker(void* arg)
{
    Data* d = (Data*)arg;

    cout << d.id
         << " "
         << d.name
         << endl;

    return NULL;
}

int main()
{
    pthread_t tid;

    Data d;

    d.id = 101;
    d.name = "Hanumant";

    pthread_create(
        &tid,
        NULL,
        worker,
        &d
    );

    pthread_join(tid, NULL);

    return 0;
}
