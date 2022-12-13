#include<iostream>

using namespace std;

class Employee{
string name;
double salary;

public:

Employee(string n ="", double s = 0.0)
{
name = n;
salary =s;
}

string getName()
{
return name;
}

double getSalary()
{
return salary;
}

void setName(string n)
{
name = n;
}

void setSalary(double s)
{
salary = s;
}

virtual void printDetails()
{
cout<<"NAME : "<<name<<endl;
cout<<"SALARY : "<<salary<<endl;
}

};

class Manager : public Employee
{
string type;

public:

Manager(string name, double salary, string t="") : Employee(name,salary)
{
type = t;
}

void printDetails()
{
Employee :: printDetails();
cout<<"TYPE : "<<type<<endl;
}
};

class Clerk : public Employee
{
double allowance;

public:

Clerk(string name, double salary, double a = 0.0) : Employee(name,salary)
{
allowance = a;
}

void printDetails()
{
Employee :: printDetails();
cout<<"ALLOWANCE : "<<allowance<<endl;
}

};

int main()
{
Employee *arr[6];
arr[0] = new Employee("Person1", 10000.00);
arr[1] = new Employee("Person2", 12000.00);
arr[2] = new Manager("Person3",46000.00,"Merkating");
arr[3] = new Manager("Person4",45000.00,"Seales");
arr[4] = new Clerk("Person5",20000.00,1200.00);
arr[5] = new Clerk("Person6",20000.00,1000.00);

cout<<"Enter the Detals of all employee\n\n";

for(int i ; i<6;i++)
{
arr[i]->printDetails();
}

return 0;
}
