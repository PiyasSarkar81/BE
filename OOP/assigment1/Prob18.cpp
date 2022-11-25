#include<iostream>
#include<math.h>
using namespace std;

class Point{
public:
int x,y,z;
Point(){
this->x=0;
this->y=0;
this->z=0;
}
Point(int x, int y,int z){
this->x=x;
this->y=y;
this->z=z;
}
float distance(Point a,Point b){
return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}
};


int main(){
Point p1, p2;
cout<<"Enter the firat point in (i,j,k)"<<endl;
int x,y,z;
cin>>x>>y>>z;
p1.x=x;
p1.y=y;
p1.z=z;
cout<<"Enter the second point in (i,j,k)"<<endl;
cin>>x>>y>>z;
p2.x=x;
p2.y=y;
p2.z=z;
cout<<"The distance between the two point is: "<< p1.distance(p1,p2)<<endl;

return 0;
}
