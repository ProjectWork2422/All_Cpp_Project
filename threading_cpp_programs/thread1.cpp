#include<bits/stdc++.h>
using namespace std;
void hello(){
cout<<"This is the thread 1"<<endl;
}
int main(){
cout<<"This is  the  is the main thread   which run first before  running the   thread  beacause"<<endl;
thread task1(hello);
task1.join();
cout<<"i Guess this is going to print after running the thread"<<endl;
return 0;
}
	

