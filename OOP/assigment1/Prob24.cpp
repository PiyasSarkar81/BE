
#include<iostream>
using namespace std;

class Demo
{
int x;
mutable int y;

public:
	
void set_data_x(int a)
{
x=a;
}

void set_data_y(int b) const
{
y=b;
}

int get_data_x() const		 //constant member function
{
//++x;				 // Error while attempting to modify the data member
return x;
}

int get_data_y() const
{
++y;
return y;
}

};


main()
{
Demo d;
d.set_data_x(10);
d.set_data_y(20);
cout<<d.get_data_x()<<endl;
cout<<d.get_data_y<<endl;

return 0;
}

