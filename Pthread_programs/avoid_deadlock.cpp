#include<iostream>
#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;
pthread_mutex_t lockA;
pthread_mutex_t lockB;

void* worker1(void* args){   
    pthread_mutex_lock(&lockA);
    pthread_mutex_lock(&lockB);
    cout<<"this   is the first rc ";
    pthread_mutex_unlock(&lockB);
    pthread_mutex_unlock(&lockA);
    return  NULL;
}
void* worker2(void* args){
;
    pthread_mutex_lock(&lockA);
    pthread_mutex_lock(&lockB);
    cout<<"this   is the second rc ";
    pthread_mutex_unlock(&lockB);
    pthread_mutex_unlock(&lockA);
    return  NULL;
}

int  main(){
pthread_t t1,t2;
pthread_mutex_init(&lockA,NULL);
pthread_mutex_init(&lockB,NULL);
pthread_create(&t1,NULL,worker1,NULL);
pthread_create(&t2,NULL,worker2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_mutex_destroy(&lockA);
pthread_mutex_destroy(&lockB);
return 0;
}       