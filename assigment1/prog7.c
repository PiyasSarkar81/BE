#include<stdio.h>

int main(){
int a=0, b,c,d,i,r;
for(i=1;i<=500;i++)
{a=0;
b=i;
while(b>0)
{
d=b%10;
r=d*d*d;
a=a+r;
b/=10;
}
if(a==i)
printf("%d\n",i);
}
return 0;
}
