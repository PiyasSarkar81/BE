#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
if(front == -1) return 1;
else return 0;
}

int isFull()
{
    if((front==0 && rear == MAX-1)  || front == rear+1) return 1;
    else return 0;
}

void insert(int item)
{
    if(isFull())
    {
        printf("Queue Overflow.\n");
        return;
    }
    if(front == -1) front = 0;
    if(rear=MAX-1) rear =0;
    else rear = rear +1;
    cqueue_arr[rear] = item;
}

int del()
{
int item;
if(isEmpty())
{
    printf("Queue Underflow.\n");
    exit(1);
}
item = cqueue_arr[front];
if(front==rear){
    front = -1;
    rear = -1; 
}
else if (front == MAX -1)
front = 0;
else front = front +1;
return item;
}

int peek() 
{
if(isEmpty())
{
printf("Queue is empty.\n");
exit(1);
}
return cqueue_arr[front];
}


void display()
{
int i;
if(isEmpty())
{
printf("Queue is empty.\n");
return;
}
printf("Queue elements : \n");
i = front;
if(front <= rear){
    printf("%d ",cqueue_arr[i++]);
}
else{
    while(i<=MAX-1) printf("%d ",cqueue_arr[i++]);
    i=0;
    while(i<=rear) printf("%d ",cqueue_arr[i++]);
}
printf("\n");
}

int main()
{
int choice,item,c;
printf("\nCreate a Circular Queue\n\n");
int n,i;
printf("Enter the number of elements will insert into Queue.\n");
scanf("%d",&n);
printf("Enter the elements to be inserted.\n");
for(i=0;i<n;i++)
{
int a;
scanf("%d",&a);
insert(a);
}

while(1)
{

printf("\n\n1.Insertion\n");
printf("2.Deletion\n");
printf("3.Chack number of elements \n");
printf("4.Print the elements of the Queue\n");
printf("5.Quit\n"); 
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the element to be inserted : ");
scanf("%d",&item);
insert(item);
break;

case 2:
item = del();
printf("Deleted item is : %d ",item);
break;

case 3:
c =0;
if(isEmpty)
printf("Number of elements is : 0");
else
{
if(front <= rear){
    c = rear - front + 1;
}
else{
    c = MAX - front;
    c += rear + 1;
}
printf("Number of elements is : %d",c);
}
break;

case 4:
display();
break;

case 5:
exit(1);
break;

defalt:
printf("Wrong choice.");
}
}

return 0;
}