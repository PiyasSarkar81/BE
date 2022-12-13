#include<stdio.h>
int main()
{
 int i,j,sizePoly1,sizePoly2;
 printf("Enter number of terms in Polynomial 1\n");
 scanf("%d",&sizePoly1);
 printf("Enter number of terms in Polynomial 2\n");
 scanf("%d",&sizePoly2);

 int a[sizePoly1],b[sizePoly2],prod[sizePoly1+sizePoly2];
 printf("Enter Elements of Polynomial 1\n");
 for(i=0;i<sizePoly1;i++)
 {
  printf("Enter x^%d Co-Efficient of Polynomial 1\n",i);
  scanf("%d",&a[i]);
 }
 
 printf("Enter Elements of Polynomial 2\n");
 for(i=0;i<sizePoly2;i++)
 {
  printf("Enter x^%d Co-Efficient of Polynomial 2\n",i);
  scanf("%d",&b[i]);
 }
 for(i=0;i<sizePoly1+sizePoly2;i++)
 {
  prod[i]=0;
 }
 
 for(i=0;i<sizePoly1;i++)
 {
  for(j=0;j<sizePoly2;j++)
  {
   if(a[i]!=0 && b[j]!=0)
   prod[i+j]+=a[i]*b[j];
  }
 }
 for(i=sizePoly1+sizePoly2-1;i>=0;i--)
 {
  if(prod[i]!=0){
   if(i!=0)
      {
       printf("%d x^%d + ",prod[i],i);
      }
      else
      {
       printf("%d x^%d\n",prod[i],i);
      }
  }
 }
}