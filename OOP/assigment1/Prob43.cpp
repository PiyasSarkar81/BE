#include<iostream>

using namespace std;



class Shape2D{
public:
Shape2D()
{ }

virtual double parimeter()=0;

virtual double area()=0;

};

class Rect : public Shape2D
{
double length,wirth;

public:

Rect(double l = 0,double w = 0)
{
length = l;
wirth = w;
}

double parimeter()
{
return 2*(length+wirth);
}

double area()
{
return length * wirth;
}

};

class Circle : public Shape2D
{
double redious;

public:

Circle(double r =0)
{
redious = r;
}

double parimeter()
{
return 2*3.14*redious;
}

double area()
{
return 3.14*redious*redious;
}

};



int main()
{



return 0;
}
