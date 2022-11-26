#include<iostream>
#include<math.h>
using namespace std;

class Device
{
int x,y,id,r;

public:

Device(){
this->x=0;
this->y=0;
this->id=0;
this->r=0;
}

void set(int a, int b, int uid, int d)
{
x=a;
y=b;
id = uid;
r =d;
}

void neighbor( Device a){
double dist = sqrt(pow(x-a.x,2)+pow(y-a.y,2));
if(dist<r)
cout<<a.id<<" ";
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
arr[i].set(x,y,i+1,r);
}

for(int i=0;i<10;i++){
cout<<"Neighbor elements of "<<i+1<<" are: "<<endl;
for(int j=0;j<10;j++){
if(i != j){
arr[i].neighbor(arr[j]);
}
}
cout<<endl;
}
 
return 0;
}

