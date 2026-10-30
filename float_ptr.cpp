#include<iostream>
using namespace std;
int main(){
    float num=10.5;
    float *ptr=&num;
    *ptr=50.5;
    cout<<"The value of the num after updating through pointer is : "<<num<<endl;
    return 0;
} 