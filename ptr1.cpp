#include<iostream>
using namespace std;
int main(){
    int a=100;
    int *ptr1=&a;
    cout<<"The value of the a is : "<<a<<endl;
    cout<<"The value of the a is : "<<*ptr1<<endl;
    *ptr1+=1;
    cout<<"The value of the a is : "<<*ptr1<<endl;
    cout<<"The address   of the  variable is : "<<ptr1<<endl;
    return 0;
}
  