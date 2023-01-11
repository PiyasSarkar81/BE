

#include<iostream>
using namespace std;

class Shape2D
{
    public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};


class Circle :  public Shape2D
{
    public :
    int radius;
    Circle()
    {
        cout << "Enter the radius of the circle :\n";
        int r;
        cin >> r;
        this->radius = r;
    }
    void area()
    {
        cout << "The area is " << 3.14*radius*radius << "\n";
    }
    void perimeter()
    {
           cout << "The perimeter is " << 2*3.14*radius << "\n";
    }
};

class Rectangle : public Shape2D
{
    public :
    int len,bre;
    Rectangle()
    {
        cout << "Enter the length of the rectangle :\n";
        int x;
        cin >> x;
        cout << "Enter the breadth of the rectangle :\n";
        int y;
        cin >> y;
        this->len = x;
        this->bre = y;
    }
    void area()
    {
        cout << "The area is " << len*bre << "\n";
    }
    void perimeter()
    {
        cout << "The perimeter is " << 2*(len+bre) << "\n";
    }
};


int main()
{
    Shape2D *ptr[5];
    Circle ob1,ob2,ob3;
    Rectangle obj1,obj2;
    ptr[0] = &ob1;
    ptr[1] = &ob2;
    ptr[2] = &ob3;
    ptr[3] = &obj1;
    ptr[4] = &obj2;
    for(int i = 0; i < 5; i++)
    {
        ptr[i]->area();
        ptr[i]->perimeter();
    }
}
