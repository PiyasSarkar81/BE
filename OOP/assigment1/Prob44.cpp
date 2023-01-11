#include<iostream>
using namespace std;

class Shape
{

};

class TwoDShape : public Shape
{

public:
    
    virtual void getArea()
    {

    }

};

class ThreeDShape : public Shape
{	
public:
    virtual void getArea()
    {

    }

    virtual void getVolume()
    {

    }
};

class Circle : public TwoDShape
{
int redious;
public:
Circle(){
cout<<"Enter the redious of the circle";
int r;
cin>>r;
redious = r;
}
    void getArea()
    {
	cout<<"Area of the Circle is : "<<3.14*redious*redious<<endl;
    }
};

class Triangle : public TwoDShape
{
double base,hight;
public:
Triangle()
{
cout<<"Enter the base and hight of the Triangle : ";
int b,h;
cin>>b>>h;
base = b;
hight = h;
}
    void getArea()
    {
	cout<<"Area of the Triangle "<< 0.5*base*hight<<endl;
    }

};

class Ellipsee : public TwoDShape
{
double aAxis, bAxis;
public:
Ellipsee()
{
cout<<"Enter the a asix and b axix of the ellipsee : ";
double a,b;
cin>>a>>b;
aAxis = a;
bAxis = b;
}
    void getArea()
    {
	cout<<"Area of the ellipsee : "<<3.14*aAxis*bAxis<<endl;
    }
};

class Sphere : public ThreeDShape
{
double redious;
public:
Sphere()
{
cout<<"Enter the radious of the Sphere : ";
double r;
redious = r;
}
    void getArea()
    {
        cout<<"Area of the sphere is : "<<4*3.14*redious*redious<<endl;
    }

    void getVolume()
    {
	cout<<"Volume of the sphere is : "<<(4*3.14*redious*redious*redious)/3<<endl;
    }
};

class Cube : public ThreeDShape
{
double side;
public:
Cube()
{
cout<<"Enter the radious of the cube:";
double a;
cin>>a;
side = a;
}
    void getArea()
    {
	cout<<"Surface area of the Cube : "<<6*side*side<<endl;
    }

    void getVolume()
    {
	cout<<"Volume of the Cube : "<<side*side*side<<endl;
    }
};



int main()
{	

    
    return 0;   
}
