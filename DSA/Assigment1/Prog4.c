#include<stdio.h>
#include<math.h>

typedef struct{
int exp, coe;
}SP;

int main(){
printf("Enter the number of elements in the polinomial\n");
int n,i;
scanf("%d",&n);
SP arr[n];
printf("Enter the Coeficient & Exponient values of the polynomial\n");
for(i=0;i<n;i++){
scanf("%d %d",&arr[i].coe,&arr[i].exp);
}
int x;
printf("Enter the value to evaluate the polynomial.\n");
scanf("%d",&x);
int val=0;
for(i=0;i<n;i++)
val=val+arr[i].coe*pow(x,arr[i].exp);
printf("The value of the polinomials is %d\n",val);
return 0;
}

