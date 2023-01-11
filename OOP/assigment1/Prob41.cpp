#include<iostream>
using namespace std;

class Person{
string name;
int age;
double hight;

public:

Person(string name = "", int age = 0, double hight = 0.0)
{
this -> name = name;
this-> age = age;
this -> hight = hight;
} 

string get_name()
{
return name;
}

int get_age()
{
return age;
}

double get_hight()
{
return hight;
}

void set_name(string n)
{
name = n;
}

void set_age(int a)
{
age =a;
}

void set_hight(double h)
{
hight = h;
}

virtual void printDetails()
{
cout<<"NAME : "<<name<<endl;
cout<<"AGE : "<<age<<endl; 
cout<<"HIGHT : "<<hight<<endl;

}

};

class Student : public Person
{
int roll;
string yoa;

public:

Student(string name, int age, double hight,int roll = 0, string yoa = "") : Person (name,age,hight)
{
this -> roll = roll;
this -> yoa = yoa;
}

int get_rollno()
{
return roll;
}

string get_yearOfAdmission()
{
return yoa;
}

void set_rollno(int r)
{
roll = r;
}

void set_yearOfAdmission(string y )
{
yoa = y;
}

void printDetails()
{
Person :: printDetails();
cout<<"ROLL : "<<roll<<endl;
cout<<"YEAR OF ADMISSION : "<<yoa<<endl;
}
};

int main()
{
cout<<"Enter the details of the person."<<endl;
Person *a[4];

a[0] = new Person("Ram",15,156);
a[1] = new Person("Sham ",30,180);
a[2] = new Student("Animesh",20,170,149,"2021");
a[3] = new Student("Soham",19,180,143,"2022");

for(int i =0;i<4;i++)
{
a[i]->printDetails();
cout<<endl;
}

return 0;
}

