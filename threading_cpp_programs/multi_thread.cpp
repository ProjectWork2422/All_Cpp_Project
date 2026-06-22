#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<thread>
void task();
int  main(){

cout<<"This  is the main  thread "<<endl;
thread t1(task);
t1.join();
cout<<"Task one  completed  by the thread1"<<endl;
thread t2(task);
t2.join();
cout<<"Task 1  is  completed  by the thread2 "<<endl;
thread t3(task);
t3.join();
cout<<"Task 1  is completed  by the  thread3"<<endl;
thread t4(task);
t4.join();
cout<<"Task 1 is  completed by the  thread4"<<endl;
thread t5(task);
t5.join();
cout<<"Task 1 is completed by the  thread5"<<endl;

/* cout<<"THis is the  thread1 "<<endl;
t1.join();
 cout<<"This  is the thread2 "<<endl;
t2.join();
cout<<" This is the the thread3"<<endl;
t3.join();
cout<<"THis is the  thread4 "<<endl;
t4.join();
cout<<"THis  is the  thread5"<<endl;
t5.join();
*/

}

void task(){
cout<<"This is the  task1 which is used   in the comman   threads"<<endl;
}
