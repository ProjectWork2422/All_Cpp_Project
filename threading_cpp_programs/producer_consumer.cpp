#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>     // sleep(), usleep()

using namespace std;

queue<int> buffer;

const int MAX_SIZE = 5;

// Mutex
pthread_mutex_t mutex1;

// Condition Variables
pthread_cond_t notFull;
pthread_cond_t notEmpty;

// Producer Thread
void* producer(void* arg)
{
    for(int i = 1; i <= 15; i++)
    {
        // Lock the mutex
        pthread_mutex_lock(&mutex1);

        // Wait if buffer is full
        while(buffer.size() == MAX_SIZE)
        {
            pthread_cond_wait(&notFull, &mutex1);
        }

        // Produce data
        buffer.push(i);

        cout << "Produced : " << i << endl;

        // Notify consumer that buffer has data
        pthread_cond_signal(&notEmpty);

        // Unlock mutex
        pthread_mutex_unlock(&mutex1);

        usleep(500000);     // 500 milliseconds
    }

    return NULL;
}

// Consumer Thread
void* consumer(void* arg)
{
    for(int i = 1; i <= 15; i++)
    {
        // Lock the mutex
        pthread_mutex_lock(&mutex1);

        // Wait if buffer is empty
        while(buffer.empty())
        {
            pthread_cond_wait(&notEmpty, &mutex1);
        }

        // Consume data
        int value = buffer.front();
        buffer.pop();

        cout << "Consumed : " << value << endl;

        // Notify producer that buffer has space
        pthread_cond_signal(&notFull);

        // Unlock mutex
        pthread_mutex_unlock(&mutex1);

        usleep(700000);     // 700 milliseconds
    }

    return NULL;
}

int main()
{
    pthread_t producerThread;
    pthread_t consumerThread;

    // Initialize mutex
    pthread_mutex_init(&mutex1, NULL);

    // Initialize condition variables
    pthread_cond_init(&notFull, NULL);
    pthread_cond_init(&notEmpty, NULL);

    // Create producer thread
    pthread_create(&producerThread, NULL, producer, NULL);

    // Create consumer thread
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex1);

    // Destroy condition variables
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    return 0;
}
