#include<iostream>
using namespace std;
typedef struct ary{
int *a;
int n;
int m;
}ary;

void createary(ary &a,int n,int m)
{
a.a=new int[m*n];
a.n=n;
a.m=m;
for(int i=0;i<m*n;i++)
{
cin>>a.a[i];
}
}

void printelement(ary &a,int i,int j)
{
cout<<a.a[a.m*i+j]<<endl;
}

int main()
{
cout<<"Enter the size of the double dimensional aray"<<endl;
int n,m;
cin>>n>>m;
ary a;
cout<<"Enter the elements of the array "<<endl;
createary(a,n,m);
cout<<"Enter the index you like to print:"<<endl;
int i;int j;
cin>>i>>j;
cout<<"The element at "<<i<<","<<j<<" is ";
printelement(a,i-1,j-1);
return 0;
}
