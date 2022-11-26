#include<iostream>
using namespace std;

class IntArray{
int n;
int *arr;

public:
IntArray(int x)
{
n=x;
arr = new int [x];
}
void setElement(int x,int i)
{
arr[i]=x;
}
void getElement(int i)
{
cout<<arr[i]<<" ";
}

void add(IntArray x)
{
cout<<"Addition:"<<endl;
for(int i=0;i<n;i++)
cout<<arr[i]+x.arr[i]<<" ";
cout<<endl;
}

};

int main()
{
int n;
cout<<"Enter the number of elements in the intiger Array."<<endl;
cin>>n;
IntArray arr1(n), arr2(n);
cout<<"Enter the  elements of the 1st Array"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
arr1.setElement(x,i);
}
cout<<"Enter the  elements of the 2st Array"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
arr2.setElement(x,i);
}
arr1.add(arr2);

return 0;
}
