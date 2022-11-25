#include<bits/stdc++.h>
using namespace std;

inline int fact(int n){
return (n<2?1:n*fact(n-1));
}

int main(){
for(int i=1;i<=6;++i){
cout<<i<<"! = "<<fact(i)<<endl;
}
return 0;
}


