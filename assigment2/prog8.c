
#include<stdio.h>
int main()
{ 
float c,f;
printf("Enter the Temperature of a city in Fahrenheit degrees\n");
scanf("%f",&f);
c = ((f-32)/9)*5;
printf("the Temperature of a city in Centigrade degrees is : %.2f\n",c);
return 0;
}

