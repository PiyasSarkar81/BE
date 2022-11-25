#include<bits/stdc++.h>
using namespace std;

inline int fact(int n){ 
const int &p = n;
return (p<2?1:p*fact(p-1));
}

int main(){
int x=4;
cout<<"Value of the 'x' is: "<<x<<endl;
cout<<"factorial with read only refarence of the number is : "<< fact(x)<<endl; 
return 0;
}


