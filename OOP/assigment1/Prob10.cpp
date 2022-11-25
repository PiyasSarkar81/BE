#include<bits/stdc++.h>
using namespace std;

inline int fact(int n){
return (n<2?1:n*fact(n-1));
}

int main(){
int x=4;
const int &p = x;
cout<<"Value of the read only value is: <<p<<endl;
cout<<"factorial of the number is : "<< fact(num)<<endl;
return 0;
}


