#include<iostream>
using namespace std;

class Rectangle{
public:
int hight,bearth;
Rectangle(int h=0,int b=0){
this->hight=h;
this->bearth=b;
}
float area(){
return hight*bearth;
}

};

int main(){
Rectangle R1(1,2),R2(2,3),R3(3,4),R4(4,5);
cout<<"Area of the 4 rectangle are:"<<endl;
cout<<R1.area()<<" "<<R2.area()<<" "<<R3.area()<<" "<<R4.area()<<endl;
return 0;
}
