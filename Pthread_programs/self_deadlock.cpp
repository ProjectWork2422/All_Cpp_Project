#include <iostream>
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
pthread_mutex_t mut;
void *worker(void *args)
{
    pthread_mutex_lock(&mut);
    cout << "This is the  first  lock ";
    pthread_mutex_lock(&mut);
    cout << "This  is the second lock ";
    pthread_mutex_unlock(&mut);
    pthread_mutex_unlock(&mut);
    return NULL;
}
int main()
{
    pthread_t t;
    pthread_mutex_init(&mut, NULL);
    pthread_create(&t, NULL, worker, NULL);
    pthread_join(t, NULL);
    pthread_mutex_destroy(&mut);
    return 0;
}
