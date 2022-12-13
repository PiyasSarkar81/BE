#include<stdio.h>
using namespace std;

class A
{
int a;
public:

};

class B
{
int b;
public:

};

class C
{
int c;
public:
};

class D : public A, public B
{
int d;
public:
};

class E : public B , public C
{
int e;
public:
};

class F : public D , public E
{
int f;
public:
};

int main()
{
F a;
return 0;
}
