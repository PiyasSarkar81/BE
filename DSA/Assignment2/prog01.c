#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node* link;
};

struct node *addatpos(struct node *start,int data, int pos)
{
struct node *tmp, *p;
int i;
tmp = (struct node*)malloc(sizeof(struct node));
tmp -> info = data;
if(pos==1)
{
tmp -> link = start;
start = tmp;
return start;
}
p = start;
for(i=1;i<pos-1 && p!= NULL ; i++)
p=p->link;
if(p==NULL)
printf("There are less then %d elements.\n",pos);
else
{
tmp -> link = p-> link;
p->link = tmp;
}
return start;
}

struct node* delatpos(struct node *start,int pos)
{
if(start ==NULL)
{
printf("List is empty.\n");
return;
}
struct node *tmp,*p;
int i;
if(pos==1)
{
tmp = start;
start = start -> link;
free(tmp);
return start;
}
p = start;
for(i=1;i<pos-2 && p!= NULL;i++)
p = p-> link;
if(p->link ==NULL)
printf("There are less then %d elements.\n",pos);
else{
tmp = p->link;
p->link = p-> link->link;
free(tmp);
}
return start;
}

void count(struct node *start)
{
struct node* p;
p= start;
int c=0;
while(p!=NULL)
{
p=p->link;
c++;
}
printf("Number of node in the link list is %d\n",c);
}

struct node *reverse(struct node * start)
{
struct node * prev,*ptr,*next;
prev = NULL;
ptr = start;
while(ptr != NULL)
{
next = ptr -> link;
ptr -> link = prev;
prev = ptr;
ptr = next;
}
start = prev;
printf("\nlink list is reversed\n");
return start;
}

void display(struct node *start)
{
struct node *p;
if(start ==NULL)
{
printf("List is empty.\n");
return;
}
p= start;
printf("List is:\n");
while(p!=NULL)
{
printf("%d ",p->info);
p=p->link;
}
printf("\n\n");
}

void printReverse(struct node *start)
{
if(start == NULL)
return;
printReverse(start->link);
printf("%d ",start->info);
}

struct node *create_list(struct node *start)
{
int n,i;
struct node *p= start;
printf("Enter the number of elements in the link list.\n");
scanf("%d",&n);
printf("Enter the %d elements.\n",n);
for(i=1;i<=n;i++)
{
int data;
scanf("%d",&data);
start = addatpos(start,data,i);
}
return start;
}

int main()
{
struct node *start = NULL;
int choice,data,pos;
printf("\nCreate a link list.\n\n");
start = create_list(start);
while(1)
{
printf("\n1. Insert a node at a specific position.\n");
printf("2. Delete a node from a specific position.\n");
printf("3. Count the number of nodes in the link list.\n");
printf("4. Reverse print the link list.\n");
printf("5. Reverse the link list.\n");
printf("6. Display the link list.\n");
printf("7. Quit.\n");
printf("Enter your choice : ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter the element to be inserted : ");
scanf("%d",&data);
printf("Enter the position of insertion : ");
scanf("%d",&pos);
start = addatpos(start,data,pos);
break;

case 2:
printf("Enter the position of the element to delete:");
scanf("%d",&pos);
start = delatpos(start,pos);
break;

case 3:
count(start);
break;

case 4:
printReverse(start);
break;

case 5:
start = reverse(start);
break;

case 6:
display(start);
break;

case 7:
exit(1);
break;

default:
printf("Wrong choice.\n");

}
}

return 0;
}
