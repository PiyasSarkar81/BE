#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};

struct node* front = NULL, *rear = NULL;

int isEmpty()
{
if(front == NULL) return 1;
else return 0;
}

void insert(int item)
{
      	struct node * tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	if(tmp == NULL)
{
      printf("Memory is not available\n");
      return;
}
tmp -> info = item;
tmp -> link = NULL;
if(front == NULL)
{
front = tmp;
rear = tmp;
}
else
{ 
rear -> link = tmp;
rear = tmp;
}
}

int del()
{
struct node * tmp;
int item;
if(isEmpty())
{
printf("Queue Underflow\n");
exit(1);
}
tmp = front;
item = tmp -> info;
front = front -> link;
free(tmp);
return item;
}

int peek() 
{
if(isEmpty())
{
printf("Queue is empty.\n");
exit(1);
}
return front -> info;
}

int count()
{
struct node * p = front;
int c=0;
do{
c++;
p = p->link;
}while(p != rear->link);
return c;

}

void display()
{
struct node* ptr;
ptr = front;
if(isEmpty())
{
printf("Queue is empty.\n");
return;
}
printf("Queue elements : \n");
while(ptr != rear->link)
{
printf("%d ",ptr -> info);
ptr = ptr->link;
}
printf("\n");
}

int main()
{
int choice,item,c;
printf("\nCreat a Queue\n\n");
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
printf("Number of elements is : %d",count());
break;

case 4:
display();
break;

case 5:
exit(1);
break;

default:
printf("Wrong choice.");
}
}

return 0;
}
