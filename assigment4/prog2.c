#include<stdio.h>

int find(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 *find(decimal_number / 2));
}

int main(){
int a;
long b;
printf("Enter the positive integer\n");
scanf("%d",&a);
b=find(a);
printf("Binary equivalent is %ld\n",b);

return 0;
}
