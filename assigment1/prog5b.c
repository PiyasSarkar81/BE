#include<stdio.h>
long fact(long n)
{
int i;
long factorial=1;
for(i=2;i<=n;i++)
{
factorial *= i;
}
return factorial;
}

int main(){
printf("Enter n: ");
int n;
scanf("%d",&n);
long long sum =0;
int i;
for(i=1;i<=n;i++)
{
sum = sum + n*(n+1)*fact(i);
}
printf("1.2*1! + 2.3*2! + 3.4*3! + .... +n.(n+1)*n! = %ld\n",sum);
return 0;
}

