#include<iostream>
using namespace std;

inline void sum(int a, int b,int c){
cout<<"sum = "<<a+b+c<<endl;
}

int main(){
int a,b,c;
cout<<"Enter the three integer numbers"<<endl;
cin>>a>>b>>c;
sum(a,b,c);
return 0;
}
