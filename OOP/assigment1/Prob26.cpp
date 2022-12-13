#include<iostream>
using namespace std;

class Stack {
int *buffer, top;

public :
Stack(int n =0)
{
top = -1;
buffer = new int [n];
}		

void push(int a)
{
top++;
buffer[top] = a;
}

int pop()
{
int tmp = buffer[top];
top--;
return tmp;
}

void disp()
{
for(int i = top ; i>=0; i--)
cout<<buffer[i]<<" ";
cout<<endl;
}
};

int main()
{
Stack s(10);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.pop();
s.disp();

return 0;
}

