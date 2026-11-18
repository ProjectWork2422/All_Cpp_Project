#include<iostream>
using namespace std;
int main(){
 int arr1[5],n;
 cout<<"Enter the size of the array :";
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr1[i];
 }
 for(int i=0;i<n;i++){
    cout<<arr1[i]<<endl;
 }
 int *ptr=arr1;
 cout<<"The first element of the array is:"<<*ptr<<endl;
 cout<<"The  second element of the array is:"<<*(ptr+1)<<endl;
 cout<<"The third elemnet of the array is:"<<*(ptr+2)<<endl;
 cout<<"The fourth element of the array is:"<<*(ptr+3)<<endl;
 cout<<"The fifth element of the array is:"<<*(ptr+4)<<endl;
 return 0;
}
