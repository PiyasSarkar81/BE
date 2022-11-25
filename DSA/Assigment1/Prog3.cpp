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
SP sum[m+n];
for(int i=0;i<m+n;i++)
sum[i].exp=-1;
int i,j,c=0;
for(i=0,j=0;i<n&&j<m;)
{
if(arr[i].exp<arr2[j].exp)
{
sum[c].exp=arr[i].exp;
sum[c].coe=arr[i].coe;
i++;c++;
}
else if (arr[i].exp>arr2[j].exp)
{
sum[c].exp>arr2[j].exp;
sum[c].coe=arr2[j].coe;
j++;c++;
}
else                  
{
sum[c].exp=arr[i].exp;
sum[c].coe=arr[i].coe+arr2[j].coe;
i++;j++;c++;
}                 
}
while(j<m)
{
sum[c].exp=arr2[j].exp;                  
sum[c].coe=arr2[j].coe;
c++;j++;
}
while(i<n)
{
sum[c].exp=arr[i].exp;
sum[c].coe=arr[i].coe;
c++;i++;              
}
cout<<"Added Polynomial"<<endl;
for(i=0;i<c-1;i++)
{
cout<<sum[i].coe<<"x^"<<sum[i].exp<<"+";
}
cout<<sum[i].coe<<"x^"<<sum[i].exp<<endl;
return 0;              
} 
