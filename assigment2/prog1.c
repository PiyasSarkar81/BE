#include<stdio.h>
int main(){
int a,b;
printf("Enter the two numbers\n");
scanf("%d",&a);
scanf("%d",&b);
a=a^b;
b=a^b;
a=a^b;
printf("swaped valus:\n");
printf("%d %d\n",a,b);
return 0;
}
