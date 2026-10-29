#include<iostream>
using namespace std;
int main(){
    int no =100;
    int *ptr=&no;
    cout<<"The value of the address of the  variable is:"<<(void *)ptr<<endl;
    cout<<"The value of the address of the  variable is:"<<(void *)&no<<endl;
    cout<<"The value of the address of the  variable is:"<<(void *)&ptr<<endl;
    return 0;

}