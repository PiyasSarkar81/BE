
#include<iostream>
#include <algorithm>
using namespace std;

class IntArray{
int n;
int *arr;

public:
IntArray() : n(0) {}
IntArray(int x) : n(x)
{
arr = new int [x];
}
IntArray( IntArray & a)
<<<<<<< HEAD
{
    n = a.n;
    arr = new int [a.n];
    for(int i =0;i<a.n;i++){
        arr[i] = a.arr[i]; 
    } 
}
void setElements()
{
cout<<"Enter the "<<n<<" elements of the Array"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
arr[i] = x;
}
}
void getElements()
{
=======
{
    n = a.n;
    arr = new int [a.n];
    for(int i =0;i<a.n;i++){
        arr[i] = a.arr[i]; 
    } 
}
void setElements()
{
cout<<"Enter the "<<n<<" elements of the Array"<<endl;
for(int i=0;i<n;i++)
{
int x;
cin>>x;
arr[i] = x;
}
}
void getElements()
{
>>>>>>> 19a0694f24409804a952c3851cecb9a7cce026bc
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<endl;
}

void add(IntArray x)
{
for(int i=0;i<n;i++)
cout<<arr[i]+x.arr[i]<<" ";
cout<<endl;
}

void Sort() 
{
    sort(arr, arr+n);
}

void Reverse()
{
    reverse(arr,arr+n);
}

};

int main()
{
int n;
cout<<"Enter the number of elements in the intiger Array."<<endl;
cin>>n;
IntArray arr1(n);
arr1.setElements();
IntArray arr2(arr1);
<<<<<<< HEAD
cout<<"Second array"<<endl;
arr2.getElements();
arr2.Reverse();
cout<<"After reverse"<<endl;
cout<<"first array : ";
arr1.getElements();
cout<<"second array : ";
=======
arr2.getElements();
arr2.Reverse();
arr1.getElements();
>>>>>>> 19a0694f24409804a952c3851cecb9a7cce026bc
arr2.getElements();

return 0;
}

