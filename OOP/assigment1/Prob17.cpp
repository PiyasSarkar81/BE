#include<iostream>
using namespace std;

int add (int a=0,int b=0,int c=0){
return a+b+c;
}
int main(){
int x,y,z;
cout<<"Enter the value of three numbers: "<<endl;
cin>>x>>y>>z;
cout<<add(x+y+z)<<endl;
cout<<add(x+y)<<endl;
cout<<add(x)<<endl;
cout<<add()<<endl;

return 0;
}
