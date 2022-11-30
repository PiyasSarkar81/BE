#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};

struct node *last = NULL;

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

struct node *create_list(struct node *start)
{
int n,i;
struct node *p= start;
printf("Enter the length of the circular link list.\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
start = addatpos(start,i,i);
while(p->link != NULL)
p=p->link;
last =p;
last -> link = start;
return start;
}

int josepushCircle(struct node *start, int k) 
{
int i;
struct node *p , *t;
p=start;
while(p->link == p)
{
for(i=1;i<k;i++)
p=p->link;
t=p;
p=p->link;
start = delatpos(start,t->info);
}
return p->info;
}

int main()
{
int k;
struct node *start;
printf("\nCreat a circular link list.\n\n");
start = create_list(start);
printf("Count to choose next: ");
scanf("%d",&k);
printf("Josepush value is : %d\n",josepushCircle(start,k)); 

return 0;
}
