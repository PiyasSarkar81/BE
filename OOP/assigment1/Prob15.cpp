#include<iostream>
using namespace std;

int Max(int x, int y,int z){
return (x>y && x>z)?x:(y>z)?y:z;
}

int Max(int* arr,int n){
int m = arr[0];
for(int i=1;i<n;i++){
if(m<arr[i])m=arr[i];
}
return m;
}

int main(){
int a,b,c;
cout<<"Enter three numbers"<<endl;
cin>>a>>b>>c;
cout<<"Maximum number among the 3 numbers is"<<Max(a,b,c)<<endl;
int n;
cout<<"Enter the number of elements in an array"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements of the array"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
}
cout<<"The maximum number in the array is: "<<Max(arr,n)<<endl;
return 0;
}
