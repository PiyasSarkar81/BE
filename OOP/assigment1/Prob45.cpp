#include<iostream>
using namespace std;

class Base
{
    public :
    Base()
    {
        cout << "This is inside Base constructor\n";
    }
   // virtual ~Base()                                            //give an error
   // {
   //     cout << "This is inside Base destructor\n";
   // }

	
};

class Derived : public Base
{
    public :
    Derived()
    {
        cout << "This is inside Derived constructor\n";
    }
    ~Derived()
    {
        cout << "This is insdie Derived destructor\n";
    }
    
};


int main()
{
   Base *ptr;
   Derived ob;
   ptr = &ob;
   delete ptr; 
}
