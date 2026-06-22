#include<bits/stdc++.h>
#include<iostream>
#include<thread>
using namespace std;
int  counter=200;
mutex mtx;

void  task1();
int main(){
thread t1(task1);
thread  t2(task1);
t1.join();
t2.join();
return 0;
}
void task1(){
mtx.lock();
counter++;
cout<<counter;
mtx.unlock();
}
