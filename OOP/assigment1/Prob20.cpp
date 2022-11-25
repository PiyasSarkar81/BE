#include<iostream>
#include<math.h>
using namespace std;

class Device{
public:
int x,y,id,r;
Device(int x=0,int y=0, int id=0,int r=0){
this->x=x;
this->y=y;
this->id=id;
this->r=r;
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
cout<<"Enter the location of the device(x,y) "<<i+1<<endl;
cin>>arr[i].x>>arr[i].y;
cout<<"Enter the unique id of the device "<<i+1<<endl;
cin>>arr[i].id;
cout<<"Enter the range of the device"<<i+1<<endl;
cin>>arr[i].r;
}

cout<<"Neighbor functions are:"<<endl;
for(int i=0;i<10;i++){
cout<<arr[i].neighbor(arr);
}
 
return 0;
}

