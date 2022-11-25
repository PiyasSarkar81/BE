#include<bits/stdc++.h>
using namespace std;

const int fact(int n){
return (n<2?1:n*fact(n-1));
}

int main(){
int num;
cout<<"Enter the number : ";
cin>>num;
 cout<<"factorial of the number is : "<< fact(num)<<endl;
return 0;
}


