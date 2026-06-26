#include<bits/stdc++.h>
#include<pthread.h>
#include<unctrl.h>
using namespace std;
pthread_mutex_t lockaA;
pthread_mutex_t  lockB;
void  *thread1(void *args){
    pthread_mutex_lock(&lockaA);
    cout<<"Thread 1 has acquired lock A"<<endl;
    sleep(1);
    cout<<"Thread 1 is waiting for lock B"<<endl;
    pthread_mutex_lock(&lockB);
    cout<<"Thread 1 has acquired lock B"<<endl;
    pthread_mutex_unlock(&lockB);
    pthread_mutex_unlock(&lockaA);
    return NULL;
}

void  *thread2(void *args){
    pthread_mutex_lock(&lockB);
    cout<<"Thread 2 has acquired lock B"<<endl;
    sleep(1);
    cout<<"Thread 2 is waiting for lock A"<<endl;
    pthread_mutex_lock(&lockaA);
    cout<<"Thread 2 has acquired lock A"<<endl;
    pthread_mutex_unlock(&lockaA);
    pthread_mutex_unlock(&lockB);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&lockaA,NULL);
    pthread_mutex_init(&lockB,NULL);
    pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}