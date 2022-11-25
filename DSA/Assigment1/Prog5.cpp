#include<iostream>
using namespace std;
typedef struct {
int exp,coe;
}SP;
int main()
{
cout<<"Enter the no of elements :"<<endl;
int n;
cin>>n;
SP arr[n];
cout<<"Enter the elements "<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i].coe>>arr[i].exp;
}

cout<<"Enter no of elements of 2nd polynomial"<<endl;
int m;
cin>>m;
SP arr2[m];
cout<<"Enter the elements "<<endl;
for(int i=0;i<m;i++)
cin>>arr2[i].coe>>arr2[i].exp;


SP mult[m*n];

for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
mult[i*m+j].exp=arr[i].exp+arr2[j].exp;              
mult[i*m+j].coe=arr[i].coe*arr2[j].coe;
}      
}          


//sort

for(int i=0;i<m*n-1;i++)
{            
for(int j=i+1;j<m*n-1;j++)
{
if(mult[j].coe>mult[j+1].coe)
{
SP temp;
temp = mult[j];
mult[j]=mult[j+1];
mult[j+1]=temp;
}
}
}

for(int i=0;i<m*n;i++)
{
if(mult[i].exp==mult[i+1].exp)
{
int k=mult[i].exp;
int e=mult[i].coe;
mult[i].coe=0;

while(k==mult[i].exp)
{              
e=e+mult[i].coe;
mult[i].coe=0;
i++;
}
i--;                  
mult[i].coe=e;
}
}
cout<<"Multiplied Polynomial"<<endl;
for(int i=0;i<m*n;i++)
{             
if(mult[i].coe!=0)
{cout<<mult[i].coe<<"x^"<<mult[i].exp;
if(i!=m*n-1)   
cout<<"+";      
}             
}   

cout<<endl;           
return 0;     
}

