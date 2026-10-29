#include<iostream>
using  namespace std;
int main(){
    int a=100;
    char ch='A';
    int *ptr1=&a;
    char *ptr2=&ch;
    float f=100.5;
    float *ptr3=&f;
    string abc = "Hello";
    string *ptr4=&abc;
    cout<<"The value of the a is : "<<a<<endl;
    cout<<"The value of the a is : "<<*ptr1<<endl;
    cout<<"The value of the ch is : "<<ch<<endl;
    cout<<"The value of the ch is : "<<*ptr2<<endl; 
    cout<<"The value of the f is : "<<f<<endl;
    cout<<"The value of the f is : "<<*ptr3<<endl;
    cout<<"The value of the abc is : "<<abc<<endl;
    cout<<"The value of the abc is : "<<*ptr4<<endl;    
    cout<<"The address of  of the all pointers are : "<<endl;
    cout<<"The address of the ptr1 is : "<<ptr1<<endl;
    cout<<"The address of the ptr2 is : "<<ptr2<<endl;
    cout<<"The address of the ptr3 is : "<<ptr3<<endl;
    cout<<"The address of the ptr4 is : "<<ptr4<<endl;
    cout<<"The address of the a is : "<<&a<<endl;
    cout<<"The address of the ch is : "<<&ch<<endl;
    cout<<"The address of the f is : "<<&f<<endl;
    cout<<"The address of the abc is : "<<&abc<<endl;
    return 0;

}