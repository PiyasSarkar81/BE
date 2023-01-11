#include<iostream>
using namespace std;

class Shape { 
double Area;
 
public:
 
Shape(double a = 0) 
{
Area = a;
} 
virtual double area() = 0; 
virtual void display() = 0;

};

class Circle : public Shape
{
double redious;

public:

Circle(double r=0) : Shape(3.14*redious*redious)
{
redious = r;
}

double area() const 
{
return 3.14*redious*redious;
}
void disp() 
{
cout<<"area of the circle is : "<<area()<<endl;
}

}; 

class Rectangle : public Shape
{
double length,wirth;

public:

Rectangle(double l=0, double w=0) : Shape(l*w)
{
length = l;
wirth = w;
}

double area() const
{
return length *wirth;
}

void disp() 
{
cout<<"Area of the Rectangle : "<<area()<<endl;
}
};

class Trapezoid : public Shape
{
double par_a, par_b, hight;

public:

Trapezoid(double a = 0, double b = 0, double h =0) : Shape(((a+b)/2)*h)
{
par_a = a;
par_b = b;
hight = h;
}

double area() const
{
return ((par_a + par_b)/2)* hight;
}
void disp() 
{
cout<<"Area of the Trapezoid : "<<area()<<endl;
}
};

int main()
{


return 0;
}
