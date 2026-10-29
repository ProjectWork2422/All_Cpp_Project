#include<iostream>
using namespace std;
int main(){
   char ch='B';
   char *ptr=&ch;
   *ptr='Z';
   cout<<"The value of the ch after updating through pointer is : "<<ch<<endl;
   return 0;
}