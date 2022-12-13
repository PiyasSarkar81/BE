#include<stdio.h>
using namespace std;

class Base1
{
int x;
public:

};

class Base2
{
int z;
public:

};


class Derive : public Base1 , public Base2
{
int y;
public:
};

int main()
{

Derive d;

return 0;
}
