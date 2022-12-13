#include<iostream>

using namespace std;

class ComplexNumber{
int real;
int imag;

public:
ComplexNumber() : real(0) , imag(0)
{ }
void setReal(int a)
{
real = a;
}
void setImag(int b)
{
imag = b;
}
void getReal()
{
int a;
cout<<"Enter the real value : ";
cin>>a;
real = a;
}

void getImag()
{
cout<<"Enter the imaginary value : ";
int b;
cin>>b;
imag = b;
}

void disp()
{
cout<<real<<" + "<<imag<<"i"<<endl; 
}

ComplexNumber sum(ComplexNumber & a)
{
ComplexNumber temp;
temp.imag = a.imag + imag;
temp.real = a.real + real;
return temp;
}

};

int main()
{
ComplexNumber n1,n2,n3;
n1.setReal(3);
n1.setImag(5);
cout<<"Get the complex second number "<<endl;
n2.getReal();
n2.getImag();
cout<<"First complex number: ";
n1.disp();
cout<<"Second complex number: ";
n2.disp();
n3 = n1.sum(n2);
cout<<"Sum of the two : ";
n3.disp();
return 0;
}
