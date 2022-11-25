#include<stdio.h>
int main(){
int m,h,f,t;
printf("Withdrawn amount: ");
scanf("%d",&m);
h=m/100;
m=m%100;
f=m/50;
m=m%50;
t=m/10;
printf("$100 : %d, $50 : %d, $10 : %d\n",h,f,t);
return 0;
}

