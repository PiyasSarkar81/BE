#include<iostream>
using namespace std;

void print(int v[], int n){ 
for(int i=0;i<n;i++){
cout<<v[i]<<" ";
}
cout<<endl;
}

void print (int v[][], int m,int n){
for(int i=0;i<m;i++){
for(int j=0;j<n;i++){
cout<<v[i][j]<<" ";
}
cout<<endl;
}
}


int main(){
cout<<"Enter the number of element in the array."<<endl;
int n;
cin>>n;
int a[n];
cout<<"Enter the elements of the array"<<endl;
for(int i=0;i<n;i++){
cin>>a[i];
}
cout<<"Elements of the array are"<<endl<<print(a,n);

cout<<"Enter the number of raw and colome in the amtrix"<<endl;
int r,c;
cin>>r>>c;
int b[r][c];
cout<<"Enter the elements of the matrix"<<endl;
for(int i = 0;i<r;i++){
for(int j=0;j<c;i++){
cin>>b[i][j];
}
}
cout<<"Elements of the matrix are:"<<endl<<print(b,r,c); 

return 0;
} 

