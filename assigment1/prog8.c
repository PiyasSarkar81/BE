#include<stdio.h>

int func(int x)
{
int i,a=0,d;
for(i=0;i<100;i++){
a=0;
while(x>0)
{
d=x%10;
a+=d*d;
x/=10;
}
x=a;
if(x==1)
return 1;
}
return 0;
}
int main()
{
int c=0,d=0;
while(c<10)
{
d++;
if(func(d)==1)
{
printf("%d\n",d);
c++;
}
}
return 0;
}

