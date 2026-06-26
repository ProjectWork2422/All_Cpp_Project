#include<bits/stdc++.h>
#include<unistd.h>
using  namespace std;


int  main(){
pid_t pid = fork();
if(pid>0){
cout<<"your in the  parent  process"<<endl;
cout << "PID  : " << getpid() << endl;
cout << "Child PID : " << pid << endl;
cout << "Parent PID : " << getppid() << endl;

}
else if(pid ==0){
cout<<"your in the  child   process";
cout << "PID  : " << getpid() << endl;
cout << "Parent PID : " << getppid() << endl;
}
else{
cout<<"fatal  error";
}

return 0;

}

