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
}
int main()
{
cout<<"Enter the size of the matrix"<<endl;
int size;
cin>>size;
matrix m;
cout<<"Enter the matrix"<<endl;
insertmatrix(m,size);
node * t = m.head;
cout<<"Enter the row of which you would like to find the number of elements of"<<endl;
int row;
cin>>row;
int count =0;
while(t != NULL)
{
if(t->i==row-1)
{
count++;
}
t=t->next;
}
cout<<"The number of elements in row "<<row <<" is "<<count<<endl;
return 0;
}
