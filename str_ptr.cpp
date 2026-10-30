#include<iostream>
using namespace std;
int main(){
    string str1="Hanumant_jadhav";
    string *ptr=&str1;
    *ptr="Hanumant_jadhav_123";
    cout<<"The value of the str1 after updating through pointer is : "<<str1<<endl;
    return 0;
}