#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
int temp;
temp =a;
a=b;
b=temp;
}


int main(){
int a,b;
a=3;
b=4;
cout<<"a ="<< a<<"b ="<<b<<endl;
cout<<"After calling swap func"<<endl;
swap(a,b);
cout<<"a ="<< a<<"b ="<<b<<endl;

return 0;
}
