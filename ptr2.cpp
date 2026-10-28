#include<iostream>
using namespace std;
int main(){
    int a=10;
    int b=20;
    int *ptr1=&a;
    int *ptr2=&b;
    cout<<"The product of  two value is : "<<(*ptr1)*(*ptr2)<<endl;
    return 0;
    
}