#include<bits/stdc++.h>
#include<pthread.h>
using namespace std;
void* posixthread1(void* arg){
int value=*(int*)arg;
cout<<"This the value from the thread 1:"<<value<<endl;
return NULL;
}

int main(){
pthread_t tid;
int  number;
cin>>number;
pthread_create(&tid,NULL,posixthread1,&number);
pthread_join(tid,NULL);

return 0;
}

 
