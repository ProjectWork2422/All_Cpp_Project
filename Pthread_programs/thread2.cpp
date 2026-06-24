#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;
void*  arraythread(void *args){
int id =*(int*)args;
cout<<"This is the thread "<<id<<endl;
return NULL;

}


int  main(){
pthread_t thread[5];
int  data[5];
for(int i=0;i<5;i++){

data[i]=i+1;
pthread_create(&thread[i],NULL,arraythread,&data[i]);

}
for(int i=0;i<5;i++){
pthread_join(thread[i],NULL);
}
return 0;
}


