#include<iostream>
using namespace std;        
int main(){
    int a,b;            
    cout<<"Enter two numbers: ";
    cin>>a>>b;      
    /*addition of the numbers*/
    int c = a + b;
    if(c>0){
        cout<<"The sum of   two number is : "<<c<<endl;
    }
    else{
        cout<<"Invalid   sum";
    }
    
    return 0;
}
