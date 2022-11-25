#include<iostream>
#include<math.h>
using namespace std;

class Device
{
int x,y,id,r;
Public:
Device(){
this->x=0;
this->y=0;
this->id=0;
this->r=0;
}

void get(int x, int y, int id, int r)
{

}

void neighbor(int *arr){
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
float d;
if(i!=j)
d = sqrt(pow(arr[i].x-arr[j].x,2)+pow(arr[i].y-arr[j].y));
if(d<arr[i].r)
cout<<arr[j].id<<" ";
}
cout<<endl;
}
}
};

int main(){

Device arr[10];
for(int i=0;i<10;i++){
int x,y,r;
cout<<"Enter the location of the device(x,y) "<<i+1<<endl;
cin>>x>>y;
cout<<"Enter the range of the device "<<i+1<<endl;
cin>>r;

}

cout<<"Neighbor functions are:"<<endl;
for(int i=0;i<10;i++){
cout<<arr[i].neighbor(arr);
}
 
return 0;
}

