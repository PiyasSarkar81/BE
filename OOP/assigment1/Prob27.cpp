#include<iostream>
using namespace std;

class Queue {
int *data;
int front, rear;

public :
Queue(int n)
{
front = -1;
rear = -1;
data = new int [n];
}
void add(int a)
{
if(front == -1) front = 0;
rear++;
data[rear] = a;
}

int remove()
{
if(front == -1 || rear < front )
cout<<"Queue is empty"<<endl;
int tmp = data[rear];
rear--;

}

void disp()
{
if(front == -1 || rear < front ) 
cout<<"Queue is empty"<<endl;
for(int i =front;i<=rear ; i++)
{
cout<<data[i]<<" ";
}
cout<<endl;
}

};

int main()
{
Queue q(10);
q.add(2);
q.add(3);
q.add(4);
q.add(5);
q.remove();
q.remove();
q.disp();

return 0;
}
