#include<stdio.h>
int main(){
float b,g,dA,hR;
printf("Enter basic salary: ");
scanf("%f",&b);
dA = b*0.6;
hR = b*0.15;
g = b+dA+hR;
printf("Gross salary : %.2f\n",g);
return 0;
}
