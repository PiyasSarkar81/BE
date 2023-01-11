#include<iostream>
using namespace std;

class Person{

string name;
double hight;

public:

Person(string n= "",double h = 0)
{
name = n;
hight = h;
}
void setName(string n = "")
{
name = n;
}

void setHight(double h=0)
{
hight = h;
}

string getName() const
{
return name;
}

double getHight() const
{
return hight;
}

void disp()
{
cout<<"Name :"<<name<<endl;
cout<<"Hight :"<<hight<<endl;
}
};

class Employee : virtual public Person{                         //use of virtual base class
string type;
public:

Employee( string n, double h, string t = "") : Person(n,h)  
{
type = t;
} 

void setType(string t)
{
type = t;
}

string getType() const
{
return type;
}

void disp()
{
Person :: disp();
cout<<"Type : "<<type<<endl;
}
};

class Student : virtual public Person              //use of virtual base class
{
int ID;

public:

Student(string n, double h, int id) : Person(n,h)
{
ID = id;
}

void setId( int id)
{
ID = id;
}

int getId() const
{
return ID;
}

void disp()
{
Person :: disp();
cout<<"ID :"<<ID;
}
};

class Manager : public Employee, public Student{
public:
void disp()
{
Employee :: disp();
Student :: disp();
}
}; 

int main()
{

return 0;
}
