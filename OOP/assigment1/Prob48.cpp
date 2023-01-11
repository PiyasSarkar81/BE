#include<iostream>

using namespace std;

class Student{
string name;
int id;

public:

Student(string n ="", int i = 0)
{
name = n;
id = i;
}

void setName(string n)
{
name = n;
}

void setId(int i)
{
id = i;
}

string getName() const
{
return name;
}

int getId() const
{
return id;
}

virtual void disp()
{
cout<<"Name : "<<getName()<<endl;
cout<<"ID : "<<getId()<<endl;
}
};

class Engineering : public Student
{
string dept;
public:

Engineering(string n, int i, string d) : Student (n, i)
{
dept = d;
}

void setDept(string d)
{
dept = d;
}

string getdept() const
{
return dept;
}

void disp()
{
Student :: disp();
cout<<"Dept : "<<dept<<endl;
}
};

class Medicine : public Student
{
string dept;
public:

Medicine(string n, int i, string d) : Student (n, i)
{
dept = d;
}

void setDept(string d)
{
dept = d;
}

string getdept() const
{
return dept;
}

void disp()
{
Student :: disp();
cout<<"Dept : "<<dept<<endl;
}

};

class Science : public Student
{
string dept;
public:

Science(string n, int i, string d) : Student (n, i)
{
dept = d;
}

void setDept(string d)
{
dept = d;
}

string getdept() const
{
return dept;
}

void disp()
{
Student :: disp();
cout<<"Dept : "<<dept<<endl;
}

};

int main()
{
Student *st[3];

st[0] = new Engineering("Ranar", 150,"IT");
st[1] = new Medicine("Suman", 183,"Orthopedics");
st[2] = new Science("Visal",456,"Mathematics");

for(int i = 0;i<3;i++)
{
st[i] -> disp();
cout<<endl;
}


return 0;
}


