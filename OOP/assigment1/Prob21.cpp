#include<iostream>
using namespace std;
class Vector{
int n;
int *arr;

public:

Vector(int x = 0){
n=x;
arr = new int [x];
}

Vector( Vector & a)
{
    n = a.n;
    arr = new int [a.n];
    for(int i =0;i<a.n;i++){
        arr[i] = a.arr[i]; 
    } 
}

void eleSet(int y,int i)
{
arr[i] = y;
}

void addition(Vector x, Vector y)
{
cout<<"Addition :";
for(int i=0;i<x.n;i++)
{
cout<<x.arr[i]+y.arr[i]<<" "; 
}
cout<<endl;
}

void subtration(Vector x,Vector y)
{
cout<<"Subtration :";
for(int i=0;i<x.n;i++) 
{
cout<<x.arr[i]-y.arr[i]<<" ";
}
cout<<endl;
}

int compare(Vector x, Vector y)
{
for(int i=0;i<x.n;i++)
{
if(x.arr[i]>y.arr[i])
{
return 1;
}
if(x.arr[i]<y.arr[i])
{
return -1;
}
}
return 0;
}

};

int main(){
cout<<"Enter the number of elements int the vector."<<endl;
int n;
cin>>n;
Vector v1(n), v2(n);
cout<<"Enter the elements of the 1st vector:"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
v1.eleSet(x,i);
}
cout<<"Enter the elements of the 2nd vector:"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
v2.eleSet(x,i);
}

 v1.addition(v1,v2);
 v1.subtration(v1,v2);
 if(v1.compare(v1,v2)==1) cout<<"1st vector is greater than 2nd. "<<endl;
 else if(v1.compare(v1,v2)==-1) cout<<"2nd vector is bigger."<<endl; 
 else cout<<"Both vectors are equal."<<endl;

return 0;
}
