#include<bits/stdc++.h>
#include<thread>
using namespace std;
void  loop();
int main(){
cout<<"This is the main process";
thread t1(loop);
t1.detach();
this_thread::sleep_for(chrono::seconds(1));
cout<<"this is the main thread execute independentely after 1 second  of excution of the detachced  thread";
return 0;

}
void loop(){
for(int i=1;i<=10;i++){
cout<<i*2<<endl;
}

}
