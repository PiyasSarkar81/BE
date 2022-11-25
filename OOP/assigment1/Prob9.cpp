#include<bits/stdc++.h>
using namespace std;

void swap(string *a, string *b){
string temp;
temp =*a;
*a=*b;
*b=temp;
}

void sp(string &a,string &b){
string temp;
temp =a;
a=b;
b=temp;
}


int main(){
string a,b;
a="Ram Das";
b="Sham Saha";
cout<<"a ="<< a<<" b ="<<b<<endl;
cout<<"After calling swap func without reference"<<endl;
swap(a,b);
cout<<"a ="<< a<<" b ="<<b<<endl;
cout<<"After calling swap function with reference"<<endl;
sp(a,b);
cout<<"a = "<<a<<" b = "<<b<<endl;


return 0;
}


