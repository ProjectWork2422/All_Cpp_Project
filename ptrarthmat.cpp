#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *ptr=&a;
    cout<<"The Addition of the  pointer arthmatic is :"<<*ptr+10<<endl;
    cout<<"The substraction of the pointer arthmatic is:"<<*ptr-10<<endl;
    cout<<"The multiplication of the pointer arthmatic is:"<<*ptr*10<<endl;
    cout<<"The address of the pointer arthmatic is:"<< ptr<<endl;
    cout<<"The addition of the pointer arthmatic is:"<< ptr+10<<endl;
    cout<<"The substraction of the pointer arthmatic is:"<< ptr-10<<endl;
    cout<<"The increament operator of this pointer arthmatic is:"<< ++ptr<<endl;
    cout<<"The decreament operator of this pointer artmatic is :"<< --ptr<<endl;
    return 0; 

}