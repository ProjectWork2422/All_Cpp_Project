#include <iostream>
#include <pthread.h>

using namespace std;
int counter = 0;

pthread_mutex_t lock;

void* increment(void* arg)
{
    for(int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;
        
    }

    return NULL;
}
int main()
{   
    pthread_t t1, t2;

    pthread_mutex_init(
        &lock,
        NULL
    );

    pthread_create(
        &t1,
        NULL,
        increment,
        NULL
    );

    pthread_create(
        &t2,
        NULL,
        increment,
        NULL
    );

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    cout << "Counter = "
         << counter
         << endl;

    pthread_mutex_destroy(
        &lock
    );

    return 0;
}
