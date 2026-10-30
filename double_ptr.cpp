#include<iostream>
using namespace std;
int main(){
   double num=10.5;
   double   *ptr=&num;
   *ptr=500.5;
    cout<<"The value of the num after updating through pointer is : "<<num<<endl;
    return 0;
}