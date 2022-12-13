#include<stdio.h>
#include<stdlib.h>

struct node {
int cof, exp;
struct node * link;
};

struct node *addatpos(struct node *start,int c,int e, int pos)
{
struct node *tmp, *p;
int i;
tmp = (struct node*)malloc(sizeof(struct node));
tmp -> cof = c;
tmp -> exp = e;
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

void display(struct node *start)
{
struct node *p;
if(start ==NULL)
{                 
printf("List is empty.\n");
return;            
}                  
p= start;  
while(p!=NULL)
{            
printf("%dx^%d ",p->cof,p->exp);
if(p->link!=NULL) printf(" + ");              
p=p->link;   
}
printf("\n\n");
}

int main()
{
printf("Enter the 1st polynomial.\n");
struct node* poly1;
printf("Enter the number of elements will be inserted \n");
int n,i;
scanf("%d",&n);
printf("(cof,exp)");
for(i=1;i<=n;i++)
{
int a,b;
scanf("%d%d",&a,&b);
addatpos(poly1,a,b,i);
}

printf("Enter the 2st polynomial.\n");
struct node* poly2;
printf("Enter the number of elements will be inserted \n");
int m;
scanf("%d",&m);
printf("(cof,exp)");
for(i=1;i<=n;i++)
{
int a,b;
scanf("%d%d",&a,&b);
addatpos(poly2,a,b,i);
}


return 0;
}

