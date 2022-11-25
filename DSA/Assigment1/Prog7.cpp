#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct node{
int i,j,data;
node *next = NULL;
}node;
struct matrix {
node* head;
};
void insertmatrix(matrix &m,int n)
{
m.head= new node;
node *t= m.head;
node *oldt;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
int k;
cin>>k;
if(k!=0)
{
t->i = i;
t->j=j;
t->data =k;
t->next = new node;
oldt= t;
t=t->next;
}
}
}
oldt->next = NULL;
free(t);
}
matrix addmatrix(matrix n,matrix m)
{
matrix o;
o.head = new node;
node * t= o.head;
node* oldt;
node * t1= m.head;
node * t2= n.head;
while(t1!=NULL&&t2!=NULL)
{
if(t1->i<t2->i)
{
t->i=t1->i;       
t->j=t1->j;
t->data=t1->data;
t1=t1->next;
t->next = new node;
oldt =t; 
t= t->next;       
}                
else if(t1->i>t2->i)
{
t->i=t2->i;
t->j=t2->j;
t->data=t2->data;
t2=t2->next;
t->next = new node;
oldt =t;
t= t->next;
}
else if (t1->j<t2->j)
{
t->i=t1->i;
t->j=t1->j;
t->data=t1->data;
t1=t1->next;
t->next = new node;
oldt= t; 
t= t->next;       
}                
else if (t1->j>t2->j)
{                 
t->i=t2->i;
t->j=t2->j;
t->data=t2->data;
t2=t2->next;
t->next = new node;
oldt =t;
t= t->next;
}
else        
{
t->i=t2->i;
t->j=t2->j;       
t->data=t2->data+t1->data;
t2=t2->next;     
t1=t1->next;
t->next = new node;
oldt =t; 
t= t->next;       

}
}                 
while(t1!=NULL)
{
t->i=t1->i; 
t->j=t1->j;
t->data=t1->data;
t1=t1->next;      
t->next = new node;       
oldt= t;         
t= t->next; 
}                  
while(t2!=NULL)
{                 
t->i=t2->i;
t->j=t2->j;
t->data=t2->data; 
t2=t2->next;   
t->next = new node;
oldt =t;    
t= t->next;
}
oldt->next = NULL;
free (t);
return o;
}
void printmatrix(matrix m,int size)
{
node *t= m.head;
for(int i=0;i<size;i++)
{
for(int j=0;j<size;j++)
{
if(t!=NULL) {
        if (t->i ==i&&t->j==j) {
        printf("%2d ",t->data);
        t=t->next;
        }
        else {
        printf("%2d ",0);
        }
}



else {
printf("%2d ",0);
}

}
cout<<endl;
}
}

int main()
{

int size;
matrix n;
cout<<"Enter size of matrices"<<endl;
cin>>size;
cout<<"Enter the first matrix"<<endl;
insertmatrix(n,size);
matrix m;
cout<<"Enter the second matrix"<<endl;
insertmatrix(m,size);
matrix sum = addmatrix(n,m);
cout<<"Added matrix:"<<endl;
printmatrix(sum,size);
cout<<endl;
return 0;
}
