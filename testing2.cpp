#include<iostream>
using namespace std;        
int main(){
    int a,b;            
    cout<<"Enter two numbers: ";
    cin>>a>>b;      
    /*addition of the numbers*/
    int c = a + b;
    int d = a - b;
    int m=a * b;
    float u=a/b;
    int l=a%b;


    if(c>0){
        cout<<"The sum of   two number is : "<<c<<endl;
    }
    else{
        cout<<"sum is less than zero which is invalid :"<<c<<endl;
    }
    cout<<"This are the operations  excepts the   addition of two numbers"<<endl;
    if(a>b){
    cout<<"The reminder  of the two number is "<<l<<endl;
    }
    cout<<"The difference of two number is : "<<d<<endl;
    cout<<"The multiplication of two number is : "<<m<<endl;
    cout<<"The dividation of two  numbers is : "<<u<<endl;
    
    return 0;
}
